#define _CRT_SECURE_NO_WARNINGS             //������ȫ���
#include <graphics.h>                       //ͼ�ν���ͷ�ļ�
#include <conio.h>                          //��׼�������ͷ�ļ�
#include <math.h>                           //��ѧ����ͷ�ļ�
#include <iostream>
#include <stdio.h>
using namespace std;

/***************************************/
/*            ��ͼ������               */
/***************************************/
int main()
{
    int n;
    char way;
    cout << "Please input n:" << endl;
    cin >> n;
    cout << "��ֵ��ʽ��" << endl;
    cin >> way;

    // Lagrange ��ֵ
    double lagrange(double x1[], double y1[], int c1, double t1);
    double t1;
    double* z1 = (double*)malloc(sizeof(double) * 100000);//�����ڴ�ռ�
    double* x1 = (double*)malloc(sizeof(double) * 21);//�����ڴ�ռ�
    double* y1 = (double*)malloc(sizeof(double) * 21);//�����ڴ�ռ�

    // ��ͼ
    int h = 0;
    int u = 0;
    int p = 0;
    double* temp = NULL;
    double* hanshu_y = (double*)malloc(sizeof(double) * 100000);//�����ڴ�ռ�
    long beishu_x = 1, beishu_y = 200;
    int graphic_x = 800, graphic_y = 700;//���ڴ�С
    initgraph(graphic_x, graphic_y);//��ʼ����ͼ����

    //������
    setlinecolor(BLUE);//���û�����ɫ
    line(0, graphic_y / 2 + 200, graphic_x, graphic_y / 2 + 200);        //��x��
    line(graphic_x / 2, 0, graphic_x / 2, graphic_y);                    //��y��

    settextcolor(RED);//����������ɫ
    outtextxy(graphic_x - 20, graphic_y / 2 + 205, 'x');                   //x
    outtextxy(graphic_x / 2 + 5, 10, 'y');                                 //y
    outtextxy(graphic_x / 2 - 10, graphic_y / 2 + 205, '0');               //0

    settextcolor(LIGHTGREEN);
    outtextxy(graphic_x / 10, graphic_x / 10, L" ȡn=20��Lagrange��ֵ ");

    setaspectratio(0.006, -1.0);                            //��������������õ�ǰ��������
    setorigin(graphic_x / 2, graphic_y / 2 + 200 );          // ��������ԭ�㵽��Ļ�����

    // ��ʼ��ԭ����ͼ��
    int f = 0;
    for (double x = -1.0; x <= 1.0; x += 1.0 / 50000)       // -1~~~~1
    {
        hanshu_y[h++] = 1 / (1 + 25 * x * x);               // ���㺯��y=1/(1+25*x^2)
    }
    for (int i = -h / 2; i < h / 2; i++)
    {
        putpixel(beishu_x * i, beishu_y * hanshu_y[f++], LIGHTMAGENTA);
    }

    // ��ʼ����ֵ����
    if (way == 'L')                // Lagrange ��ֵ����
    {
        //double x1[11] = { -1.0,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1.0 };
        //double y1[11] = { 0.038462,0.058824,0.1,0.2,0.5,1,0.5,0.2,0.1,0.058824,0.038462 };
        //double x1[21] = { -1,- 0.9,- 0.8,- 0.7,- 0.6,- 0.5,- 0.4,- 0.3,- 0.2,- 0.1,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1 };
        //double y1[21] = { 0.038462,0.047059,0.058824,0.075472,0.1,0.137931,0.2,0.307692,0.5,0.8,1,0.8,0.5,0.307692,0.2,0.137931,0.1,0.075472,0.058824,0.047059,0.038462 };
        for (t1 = -1.0; t1 <= 1.0; t1 += 1.0 / 50000)       // -1~~~~1
            z1[u++] = lagrange(x1, y1, n, t1);                           // ������ƺ���ֵ
        int l = 0;
        for (int i = -u / 2; i < u / 2; i++)
        {
            putpixel(beishu_x * i, beishu_y * z1[l++], LIGHTGRAY);
        }
    }

    _getch();
    closegraph();//�ر�ͼ�ν���
    return 0;
}

/***************************************/
/*        Lagrange����ʽ��ֵ           */
/***************************************/
// x1[n] ���n���ڵ�ֵ
// y1[n] ��Žڵ��Ӧ����ֵ
// c �����ڵ���
// t1 ָ����ֵ��
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