//=======================================================================
//函数说明
//函数名称：Correlation
//函数功能：计算最小二乘法拟合的多项式的相关系数
//使用方法：int M------ 拟合多项式的阶数（已知条件）
//          double *b--- 拟合曲线的系数,排列顺序为由高阶到低阶（已知条件）
//			double *x--- 结点x轴数据（已知条件）
//			double *y--- 结点y轴数据（已知条件）
//			double *Yg-- 结点估计值，个数为m（过程变量）
//			int m------ 结点个数（已知条件）
//注意事项：多项式阶数最高为10,多项式的形式为 y = a0 + a1x +a2x2
//=======================================================================
#include <math.h>
double Correlation(int M, double *b, double *x, double *y, double *Yg, int m)
{
	int i,j;
	double power[10],temp,Yavr,Qr,Qt,R; //最大10阶

	Yavr = 0.0;	         //求y的平均值
	for(j=0;j<m;j++)
	{
		Yavr += y[j];
		Yg[j] = 0.0;     //初始化Yg
	}
	Yavr = Yavr/m;

	Qr = 0.0;
	Qt = 0.0;
	for(j=0;j<m;j++)
	{
		temp = 1.0;
		for(i=0;i<M;i++)
		{
			temp *= x[j];
			power[i] = temp;  
			Yg[j]= Yg[j] + b[M-i-1]*power[i];
		}
		Yg[j] = Yg[j] + b[i];

		Qr = Qr + (Yg[j] -Yavr)*(Yg[j] -Yavr);  //求Qr
		Qt = Qt + (y[j] - Yavr)*(y[j] - Yavr);  //求Qt
	}

	R = sqrt(Qr/Qt);

	return(R);
}
