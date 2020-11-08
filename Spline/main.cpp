#include <cstdio>
#include <iostream>
#include "Spline.h"

using namespace std;
using namespace SplineSpace;

int main(void)
{
	//异常抛出测试
		
	//double x0[2]={1,2};		//已知的数据点
	//double y0[2]={3,4};
	//try
	//{
	//	SplineInterface* sp = new Spline(x0,y0,2);
	//}
	//catch(SplineFailure sf)
	//{
	//	cout<<sf.GetMessage()<<endl;
	//}
	//getchar();		//程序暂停

	//单点插值测试

	//double x0[5]={1,2,4,5,6};		//已知的数据点
	//double y0[5]={1,3,4,2,5};
	//try
	//{
	//	//Spline sp(x0,y0,5,GivenSecondOrder,0,0);
	//	SplineInterface* sp = new Spline(x0,y0,5);	//使用接口，且使用默认边界条件
	//	double x=4.5;
	//	double y;
	//	sp->SinglePointInterp(x,y);	//求x的插值结果y
	//	cout<<"x="<<x<<"时的插值结果为:"<<y<<endl;
	//}
	//catch(SplineFailure sf)
	//{
	//	cout<<sf.GetMessage()<<endl;
	//}
	//getchar();	//程序暂停

	//多点插值测试

	//double x0[11]={ -1.0,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1.0 };		//已知的数据点
	//double y0[11]={ 0.038462,0.058824,0.1,0.2,0.5,1,0.5,0.2,0.1,0.058824,0.038462 };
	//double x0[21] = { -1,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1 };
	//double y0[21] = { 0.038462,0.047059,0.058824,0.075472,0.1,0.137931,0.2,0.307692,0.5,0.8,1,0.8,0.5,0.307692,0.2,0.137931,0.1,0.075472,0.058824,0.047059,0.038462 };
	//double x[10] = { -0.9,-0.7,-0.5,-0.3,-0.1,0.1,0.3,0.5,0.7,0.9 };	//插值点
	//double y[10];
	//double leftBound=50/(26*26),RightBound=-50/(26*26);	//边界导数

	//try
	//{
		//Spline sp(x0,y0,21,GivenSecondOrder,leftBound,RightBound);
		//sp.MultiPointInterp(x,10,y);			//求x的插值结果y
		//for(int i = 0;i < 10;i++)
		//{
			//cout<<"x="<<x[i]<<"时的插值结果为:"<<y[i]<<endl;
		//}
	//}
	//catch(SplineFailure sf)
	//{
		//cout<<sf.GetMessage()<<endl;
	//}
	//getchar();	//程序暂停

	// 自动插值测试

	double x0[11]={ -1.0,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1.0 };		//已知的数据点
	double y0[11]={ 0.038462,0.058824,0.1,0.2,0.5,1,0.5,0.2,0.1,0.058824,0.038462 };
	//double x0[21] = { -1,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1 };
	//double y0[21] = { 0.038462,0.047059,0.058824,0.075472,0.1,0.137931,0.2,0.307692,0.5,0.8,1,0.8,0.5,0.307692,0.2,0.137931,0.1,0.075472,0.058824,0.047059,0.038462 };

	double x[100];	//插值点
	double y[100];

	try
	{
		SplineInterface* sp = new Spline(x0,y0,11);	//使用接口，且使用默认边界条件
		sp->AutoInterp(100,x,y);			//求x的插值结果y

		for(int i = 0;i < 100;i++)
			cout<<x[i]<<"\n";
		    cout<<endl;
		for(int i = 0;i < 100;i++)
			cout<<y[i]<<"\n";
    }
	catch(SplineFailure sf)
	{
		cout<<sf.GetMessage()<<endl;
	}
	getchar();	//程序暂停
}