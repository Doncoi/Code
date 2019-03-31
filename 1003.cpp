#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int inf=1<<30;  
  
int n,ans=0;  
int dis[110],map[110][110],vis[110];  
int f[110][2],to[110];  
  
void readdata()  
{  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=n;j++)  
        {  
            scanf("%d",&map[i][j]);  
        }  
}  
void prim()  
{  
    int minx,k=1,tot=0,cnt=0;  
    for(int i=1;i<=n;i++)  
        dis[i]=inf;  
    dis[1]=0;  
    for(int i=1;i<=n;i++)  
    {  
        minx=inf;  
        for(int j=1;j<=n;j++)  
        {  
            if(dis[j]<minx && !vis[j])  
            {  
                k=j;  
                minx=dis[j];  
            }  
        }  
        ans+=minx;  
        vis[k]=1;  
        for(int j=1;j<=n;j++)  
        {  
            if(map[k][j]<dis[j] && !vis[j])  
            {  
                dis[j]=map[k][j];  
                to[j]=k;  
            }     
        }  
        if(minx)  
        {  
            f[cnt][0]=min(to[k],k);  
            f[cnt][1]=max(to[k],k);  
            cnt++;  
        }  
    }  
    printf("%d\n",cnt);  
    for(int i=0;i<cnt;i++)  
    {  
        printf("%d %d\n",f[i][0],f[i][1]);  
    }  
    printf("%d\n",ans);  
}  
int main()  
{  
    readdata();  
    prim();  
    return 0;  
}  
