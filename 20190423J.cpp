#include<stdio.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
 
int main(){
     
    int i,a,b,c,d;
     
        scanf("%d%d%d%d",&a,&b,&c,&d);
        double p=(a+b+c+d)/2.0;
        double s=sqrt((p-a)*(p-b)*(p-c)*(p-d));
        printf("%.6lf\n",s);
         
     
} 