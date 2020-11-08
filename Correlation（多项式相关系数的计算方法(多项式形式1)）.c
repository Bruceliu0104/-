//=======================================================================
//����˵��
//�������ƣ�Correlation
//�������ܣ�������С���˷���ϵĶ���ʽ�����ϵ��
//ʹ�÷�����int M------ ��϶���ʽ�Ľ�������֪������
//          double *b--- ������ߵ�ϵ��,����˳��Ϊ�ɸ߽׵��ͽף���֪������
//			double *x--- ���x�����ݣ���֪������
//			double *y--- ���y�����ݣ���֪������
//			double *Yg-- ������ֵ������Ϊm�����̱�����
//			int m------ ����������֪������
//ע���������ʽ�������Ϊ10,����ʽ����ʽΪ y = a0 + a1x +a2x2
//=======================================================================
#include <math.h>
double Correlation(int M, double *b, double *x, double *y, double *Yg, int m)
{
	int i,j;
	double power[10],temp,Yavr,Qr,Qt,R; //���10��

	Yavr = 0.0;	         //��y��ƽ��ֵ
	for(j=0;j<m;j++)
	{
		Yavr += y[j];
		Yg[j] = 0.0;     //��ʼ��Yg
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

		Qr = Qr + (Yg[j] -Yavr)*(Yg[j] -Yavr);  //��Qr
		Qt = Qt + (y[j] - Yavr)*(y[j] - Yavr);  //��Qt
	}

	R = sqrt(Qr/Qt);

	return(R);
}
