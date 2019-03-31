#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define inf 0x3f3f3f3f
#define mod 1000000007
typedef long long ll;
using namespace std;
const int N=100010;
int n,dp[N],len,m;
int w[21][21];
int g[3];
int flag=0;
int vis[10000]={0};
string str[21],ch;
int maxn=1;
map<string,int>p,pp;
struct man
{
    int x,step;
};
int charge(int y)
{
    for(int ii=2;ii<=sqrt(y);ii++)
    {
        if(y%ii==0)return 0;
    }
    return 1;
}
void bfs()
{
    queue<man>q;
    man s;s.step=0;s.x=n;
   q.push(s);
   vis[n]=1;
   while(!q.empty())
   {
       man t=q.front();
       q.pop();
       //printf("%d %d\n",t.x,t.step);
       if(t.x==m){flag=1;
        cout<<t.step<<endl;return;
       }
       int a[5];a[4]=t.x/1000;a[3]=t.x/100%10;a[2]=t.x/10%10;a[1]=t.x%10;
       for(int i=1;i<5;i++)
       {
           for(int j=0;j<=9;j++)
           {
               if(i==4&&j==0)continue;
               int k=t.x-a[i]*pow(10,i-1)+j*pow(10,i-1);
               //printf("%d %d\n",k,charge(k));
               if(charge(k)==1&&vis[k]==0)
               {
                   vis[k]=1;
                   man K;
                   K.x=k;K.step=t.step+1;
                   q.push(K);
               }
           }
       }
   }
}
 
int main() {
    memset(w,0,sizeof(w));
    cin>>n>>m;
   bfs();
   if(flag==0)puts("Impossible");
    return 0;
}
