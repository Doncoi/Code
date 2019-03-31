#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x*=10;x+=ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt,ans;
int head[1505],cur[1505],h[1505],q[1505],in[1505];
int day[505],low[100005];
struct data{int to,next,v;}e[100005];
void ins(int u,int v,int w)
{e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;e[cnt].v=w;}
void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,0);}
bool bfs(int S,int T)
{
     memset(h,-1,sizeof(h));
     int t=0,w=1;q[0]=S;h[S]=0;
     while(t!=w)
     {
          int now=q[t];t++;
          for(int i=head[now];i;i=e[i].next)
              if(e[i].v&&h[e[i].to]==-1)
              {
                   h[e[i].to]=h[now]+1;
                   q[w++]=e[i].to;
              }
     }
     if(h[T]==-1)return 0;
     return 1;
}
int dfs(int x,int f,int T)
{
     if(x==T)return f;
     int w,used=0;
     for(int i=cur[x];i;i=e[i].next)
          if(h[e[i].to]==h[x]+1)
          {
               w=f-used;w=dfs(e[i].to,min(e[i].v,w),T);
               e[i].v-=w;if(e[i].v)cur[x]=i;e[i^1].v+=w;
               used+=w;if(used==f)return f;
          }
     if(!used)h[x]=1;
     return used;
}
void dinic(int S,int T)
{while(bfs(S,T)){for(int i=0;i<=n+m+3;i++)cur[i]=head[i];dfs(S,inf,T);}}
bool jud()
{
     int SS=n+m+2,TT=n+m+3;
     for(int i=0;i<=n+m+1;i++)
     {
          if(in[i]>0)insert(SS,i,in[i]);
          if(in[i]<0)insert(i,TT,-in[i]);
     }
     dinic(SS,TT);
     for(int i=head[SS];i;i=e[i].next)
         if(e[i].v)return 0;
     return 1;
}
int main()
{
     while(scanf("%d%d",&n,&m)!=EOF)
     {
          cnt=1;int S=0,T=n+m+1;
          ans=0;
          memset(head,0,sizeof(head));
          memset(in,0,sizeof(in));
          for(int i=1;i<=m;i++)
          {
               int g=read();
               in[T]+=g;
               in[i+n]-=g;
          }
          int ed=0;
          for(int i=1;i<=n;i++)
          {
               int x=read();day[i]=read();
               for(int j=1;j<=x;j++)
               {
                   int num=read();
                   low[++ed]=read();int r=read();
                   insert(i,n+num+1,r-low[ed]);
                   in[i]-=low[ed];
                   in[n+num+1]+=low[ed];
               }
          }
          for(int i=1;i<=n;i++)insert(S,i,day[i]);
          for(int i=1;i<=m;i++)insert(i+n,T,inf);
          insert(T,S,inf);
          if(jud())
          {
               dinic(S,T);insert(T,S,-inf);
               for(int i=head[S];i;i=e[i].next)
                   ans+=e[i^1].v;
               printf("%d\n",ans);
               for(int i=1;i<=ed;i++)
                   printf("%d\n",e[(i<<1)^1].v+low[i]);
          }
          else printf("-1\n");
          puts("");
     }
     return 0;
}
