#include<cmath>
#include<iostream>
using namespace std;

//x[n]                存放n个给定的有序节点
//y[n]                存放n个给定节点上对应的函数值
//n                   给定结点的个数
//t                   指定插值点
//函数返回指定插值点t处的函数近似值
//为避免龙格现象对计算结果的影响，自动选取8个节点进行插值
//当插值点t靠近n个节点所在区间的某端时，选取节点将少于8个
//当插值点t位于结点的区间外时，则会仅取区间某端的4个节点进行插值

double lagrange(double x[], double y[], int n, double t)
{
	int i, j, k, m;
	double z, s;
	z = 0.0;
	if (n < 1) return(z);
	if (n == 1) 
	{
		z = y[0]; 
		return(z);
	}
	if (n == 2) 
	{
		z = (y[0] * (t - x[1]) - y[1] * (t - x[0])) / (x[0] - x[1]);
		return(z);
	}
	i = 0;
	while ((x[i] < t) && (i < n)) i = i + 1;   //寻找插值点 t 所在的位置
	k = i - 4;                                 //取插值区间左端点
	if (k < 0) k = 0;
	m = i + 3;                                 //取插值区间右端点
	if (m > n - 1) m = n - 1;
	for (i = k; i < +m; i++)
	{
		s = 1.0;
		for (j = k; j < +m; j++)
			if (j != i) s = s * (t - x[j]) / (x[i] - x[j]);
		z = z + s * y[i];
	}
	return(z);
}

int main()
{
	double t, z;
	double x[10] = { 0.10,0.15,0.25,0.40,0.50,0.57,0.70,0.85,0.93,1.00 };
	double y[10] = { 0.904837,0.860708,0.778801,0.670320,0.606531,0.565525,0.496585,0.427415,0.394554,0.367879 };
	t = 0.63;
	z = lagrange(x, y, 10, t);
	cout << "t=" << t << "     z=" << z << endl;
}
