#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;


double a[10000],b[10000];
bool num[10000];
double eps=0.0000001;
int main()
{
	int n;
	cin>>n;

	for (int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i],&b[i]);
	double stx[2],sty[2];
	for (int i=0;i<=1;i++)
		cin>>stx[i]>>sty[i];
	int cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++) 
	{
		double x1=(stx[0]-a[i])*(stx[0]-a[i])+(sty[0]-b[i])*(sty[0]-b[i]);
		double y1=(stx[1]-a[i])*(stx[1]-a[i])+(sty[1]-b[i])*(sty[1]-b[i]);
		if (x1>y1) num[i]=0,cnt1++;
			else num[i]=1,cnt2++;
	}
	double ansx[2]={0},ansy[2]={0};
	for (int i=1;i<=n;i++)
	{
		if (!num[i])
		{
			ansx[0]+=a[i];
			ansy[0]+=b[i];
		}
		else {
			ansx[1]+=a[i];
			ansy[1]+=b[i];
		}
	}
	ansx[0]=ansx[0]/cnt1;
	ansy[0]=ansy[0]/cnt1;
	ansx[1]=ansx[1]/cnt2;
	ansy[1]=ansy[1]/cnt2;
	while (fabs(ansx[0]-stx[0])>eps||fabs(ansy[0]-sty[0])>eps||fabs(ansx[1]-stx[1])>eps||fabs(ansy[1]-sty[1])>eps)
	{

		stx[0]=ansx[0];
		sty[0]=ansy[0];
		stx[1]=ansx[1];
		sty[1]=ansy[1];
		cnt1=0,cnt2=0;
		for (int i=1;i<=n;i++) 
		{
			double x1=(stx[0]-a[i])*(stx[0]-a[i])+(sty[0]-b[i])*(sty[0]-b[i]);
			double y1=(stx[1]-a[i])*(stx[1]-a[i])+(sty[1]-b[i])*(sty[1]-b[i]);
			if (x1>y1) num[i]=0,cnt1++;
				else num[i]=1,cnt2++;
		}
		double ansx[2]={0},ansy[2]={0};
		for (int i=1;i<=n;i++)
		{
			if (!num[i])
			{
				ansx[0]+=a[i];
				ansy[0]+=b[i];
			}
			else {
				ansx[1]+=a[i];
				ansy[1]+=b[i];
			}
		}
		ansx[0]=ansx[0]/cnt1;
		ansy[0]=ansy[0]/cnt1;
		ansx[1]=ansx[1]/cnt2;
		ansy[1]=ansy[1]/cnt2;
		printf("%lf  %lf\n%lf  %lf\n",ansx[0],ansy[0],ansx[1],ansy[1]);
	}
	
	return 0;
}