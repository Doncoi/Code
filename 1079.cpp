#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;  
const int n=58;  
const int inf=0x7fffffff;
const int N=100+5;
int m,i,j,x,y,w,k,Min,minj,b[N],dis[N][N];  
char s,t;  
int main()  
{  
    scanf("%d",&m);  
    for (i=1;i<=n;++i)  
    for (j=1;j<=n;++j)  
    dis[i][j]=0x7777777;  
    for (i=1;i<=m;++i)  
    {
        cin>>s>>t>>w;  
        x=s-64;  
        y=t-64;  
        if (x>=1&&x<26) b[x]=1;  
        if (y>=1&&y<26) b[y]=1;  
        dis[x][y]=min(dis[x][y],w);  
        dis[y][x]=min(dis[y][x],w);  
    }  
    for (k=1;k<=n;k++)  
    for (i=1;i<=n;i++)  
    for (j=1;j<=n;j++)  
    if (i!=j&&dis[i][j]>dis[i][k]+dis[k][j])  
    dis[i][j]=dis[i][k]+dis[k][j];  
    Min=inf;  
    for (i=1;i<=n;i++)  
    if (b[i]&&dis[26][i]<Min)  
    {  
        Min=dis[26][i];  
        minj=i;  
    }  
    printf("%c %d",minj+64,Min);  
    return 0;  
}  