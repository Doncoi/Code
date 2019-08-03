#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1200100
using namespace std;
int n,m,k;
int st,ed,cnt;
int head[N];
int dis[N];
int v[N];
struct node
{
    int from,to,val,next;
}edge[N<<1];
struct element
{
    int val,no;
};
bool operator < (element a,element b)
{
    if(a.val==b.val)return a.no<b.no;
    return a.val>b.val;
}
priority_queue<element>q;
void dijikstra(int s,int e)
{
    memset(dis,0x3f,sizeof(dis));
    element fir;
    fir.val=0,fir.no=s;
    dis[s]=0;
    q.push(fir);
    while(!q.empty())
    {
        element u=q.top();
        q.pop();
        if(v[u.no])continue;
        v[u.no]=1;
        for(int i=head[u.no];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[u.no]+edge[i].val<dis[to])
            {
                dis[to]=dis[u.no]+edge[i].val;
                element pus;
                pus.no=to,pus.val=dis[to];
                q.push(pus);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<=k;i++)
    {
        ans=min(ans,dis[e+i*n]);
    }
    printf("%d\n",ans);
}
void init()
{
    memset(head,-1,sizeof(head));
    cnt=1;
}
void edgeadd(int from,int to,int val)
{
    edge[cnt].from=from;
    edge[cnt].to=to;
    edge[cnt].val=val;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}

int main()
{
    init();
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&st,&ed);
    st++,ed++;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        for(int i=0;i<=k;i++)
        {
            edgeadd(x+i*n,y+i*n,z);
            edgeadd(y+i*n,x+i*n,z);
            if(i!=k)
            {
                edgeadd(x+i*n,y+(i+1)*n,0);
                edgeadd(y+i*n,x+(i+1)*n,0);
            }
        }
    }
    dijikstra(st,ed);
}
