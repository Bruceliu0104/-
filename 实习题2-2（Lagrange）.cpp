#define _CRT_SECURE_NO_WARNINGS             //跳过安全检查
#include <graphics.h>                       //图形界面头文件
#include <conio.h>                          //标准输入输出头文件
#include <math.h>                           //数学运算头文件
#include <iostream>
#include <stdio.h>
using namespace std;

/***************************************/
/*            画图主函数               */
/***************************************/
int main()
{
    int n;
    char way;
    cout << "Please input n:" << endl;
    cin >> n;
    cout << "插值方式：" << endl;
    cin >> way;

    // Lagrange 插值
    double lagrange(double x1[], double y1[], int c1, double t1);
    double t1;
    double* z1 = (double*)malloc(sizeof(double) * 100000);//申请内存空间
    double* x1 = (double*)malloc(sizeof(double) * 21);//申请内存空间
    double* y1 = (double*)malloc(sizeof(double) * 21);//申请内存空间

    // 画图
    int h = 0;
    int u = 0;
    int p = 0;
    double* temp = NULL;
    double* hanshu_y = (double*)malloc(sizeof(double) * 100000);//申请内存空间
    long beishu_x = 1, beishu_y = 200;
    int graphic_x = 800, graphic_y = 700;//窗口大小
    initgraph(graphic_x, graphic_y);//初始化绘图界面

    //画坐标
    setlinecolor(BLUE);//设置画线颜色
    line(0, graphic_y / 2 + 200, graphic_x, graphic_y / 2 + 200);        //画x轴
    line(graphic_x / 2, 0, graphic_x / 2, graphic_y);                    //画y轴

    settextcolor(RED);//设置字体颜色
    outtextxy(graphic_x - 20, graphic_y / 2 + 205, 'x');                   //x
    outtextxy(graphic_x / 2 + 5, 10, 'y');                                 //y
    outtextxy(graphic_x / 2 - 10, graphic_y / 2 + 205, '0');               //0

    settextcolor(LIGHTGREEN);
    outtextxy(graphic_x / 10, graphic_x / 10, L" 取n=20；Lagrange插值 ");

    setaspectratio(0.006, -1.0);                            //这个函数用于设置当前缩放因子
    setorigin(graphic_x / 2, graphic_y / 2 + 200 );          // 设置坐标原点到屏幕中央点

    // 开始画原函数图像
    int f = 0;
    for (double x = -1.0; x <= 1.0; x += 1.0 / 50000)       // -1~~~~1
    {
        hanshu_y[h++] = 1 / (1 + 25 * x * x);               // 计算函数y=1/(1+25*x^2)
    }
    for (int i = -h / 2; i < h / 2; i++)
    {
        putpixel(beishu_x * i, beishu_y * hanshu_y[f++], LIGHTMAGENTA);
    }

    // 开始画插值函数
    if (way == 'L')                // Lagrange 插值函数
    {
        //double x1[11] = { -1.0,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1.0 };
        //double y1[11] = { 0.038462,0.058824,0.1,0.2,0.5,1,0.5,0.2,0.1,0.058824,0.038462 };
        //double x1[21] = { -1,- 0.9,- 0.8,- 0.7,- 0.6,- 0.5,- 0.4,- 0.3,- 0.2,- 0.1,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1 };
        //double y1[21] = { 0.038462,0.047059,0.058824,0.075472,0.1,0.137931,0.2,0.307692,0.5,0.8,1,0.8,0.5,0.307692,0.2,0.137931,0.1,0.075472,0.058824,0.047059,0.038462 };
        for (t1 = -1.0; t1 <= 1.0; t1 += 1.0 / 50000)       // -1~~~~1
            z1[u++] = lagrange(x1, y1, n, t1);                           // 计算近似函数值
        int l = 0;
        for (int i = -u / 2; i < u / 2; i++)
        {
            putpixel(beishu_x * i, beishu_y * z1[l++], LIGHTGRAY);
        }
    }

    _getch();
    closegraph();//关闭图形界面
    return 0;
}

/***************************************/
/*        Lagrange多项式插值           */
/***************************************/
// x1[n] 存放n个节点值
// y1[n] 存放节点对应函数值
// c 给定节点数
// t1 指定插值点
double lagrange(double x1[], double y1[], int c1, double t1)
{
    int i, j, k, m1;
    double z, s;
    z = 0.0;
    if (c1 < 1) return(z);
    if (c1 == 1)
    {
        z = y1[0];
        return(z);
    }
    if (c1 == 2)
    {
        z = (y1[0] * (t1 - x1[1]) - y1[1] * (t1 - x1[0])) / (x1[0] - x1[1]);
        return(z);
    }
    for (i = 0; i < c1; i++)
    {
        s = 1.0;
        for (j = 0; j < c1; j++)
            if (j != i) s = s * (t1 - x1[j]) / (x1[i] - x1[j]);
        z = z + s * y1[i];
    }
    return(z);
}