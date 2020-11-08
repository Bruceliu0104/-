//=======================================================================
//����˵��
//�������ƣ�Correlation
//�������ܣ�������С���˷���ϵĶ���ʽ�����ϵ��
//ʹ�÷�����int M------��϶���ʽ����������֪������
//          double *b---������ߵ�ϵ��,���������У���֪������
//			double *x---���x�����ݣ���֪������
//			double *y---���y�����ݣ���֪������
//			double *Yg--������ֵ����*y���Ӧ������Ϊm�����̱�����
//			int m------����������֪������
//ע���������ʽ�������Ϊ10,����ʽ����ʽΪ y = b0 + b1*(x-Xavr)...
//=======================================================================
#include <math.h>
double Correlation(int M, double *b, double *x, double *y, double *Yg, int m)
{
	int i,j;
	double power[10],temp,Xavr,Xdif,Yavr,Qr,Qt,R; //���10��

	Xavr = 0.0;
	Yavr = 0.0;	         //��y��ƽ��ֵ��x��ƽ��ֵ
	for(j=0;j<m;j++)
	{
		Xavr += x[j];
		Yavr += y[j];
		Yg[j] = 0.0;     //��ʼ��Yg
	}
	Xavr = Xavr/m;
	Yavr = Yavr/m;

	Qr = 0.0;
	Qt = 0.0;
	for(j=0;j<m;j++)
	{
		temp = 1.0;
		Xdif = x[j]-Xavr;

		for(i=0;i<M-1;i++)
		{
			temp *= Xdif;
			power[i] = temp;  
			Yg[j]= Yg[j] + b[i+1]*power[i];
		}
		Yg[j] = Yg[j] + b[0];

		Qr = Qr + (Yg[j] -Yavr)*(Yg[j] -Yavr);  //��Qr
		Qt = Qt + (y[j] - Yavr)*(y[j] - Yavr);  //��Qt
	}

	R = (double)sqrt(Qr/Qt);

	return(R);
}