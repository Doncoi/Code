#include<stdio.h>
int mian()
{
	double a,b,c,d,x,y;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	x=a/b;
	y=a/c*d;
	printf("%.1lf %.1lf\n",x,y);
	return 0;
}
