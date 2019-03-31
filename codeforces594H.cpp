#include<cstdio>  
#include<cmath>  
#include<cstring>  
double a,b,c,d;  

double min(double a,double b) {  
    if(a>b)return b;  
    else return a;  
}  

double max(double a,double b) {  
    if(a>b)return a;  
    else return b;  
}  

int main() {  
    int i,j,n,k;  
    double t1,t2,x1,x2;  
    double a1,a2,b1,b2,c1,c2,d1,d2;  
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF) {  
        double t;  
          
        double l=0,r=1000000000,mid;  
        for(i=0;i<100000;i++) {  
            mid=(l+r)/2;  
            a1=a+mid;a2=a-mid;b1=b+mid;b2=b-mid;  
            c1=c+mid;c2=c-mid;d1=d+mid;d2=d-mid;  
        	t1=min(min(a1*d1,a1*d2),min(a2*d1,a2*d2));  
        	t2=min(min(b1*c1,b1*c2),min(b2*c1,b2*c2));  
        	x1=max(max(a1*d1,a1*d2),max(a2*d1,a2*d2));  
        	x2=max(max(b1*c1,b1*c2),max(b2*c1,b2*c2));  
        	if(t1<=x2&&t2<=x1)r=mid;   
            else l=mid;   
        }  
        printf("%.11f\n",l);  
    }  
    return 0;  
}  
