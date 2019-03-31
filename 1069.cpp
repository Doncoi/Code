#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct edge
{
    int x,y,v;
}cr[100050];
bool cmp(edge a,edge b) {return a.v>b.v;}
int n,m;
int an[20050],pr[20050],en[20050];

int get_father(int x)
{
    if(pr[x]==x) return x;
    pr[x]=get_father(pr[x]);
    return pr[x];
}
void Union(int x,int y)
{
    int fx=get_father(x);
    int fy=get_father(y);
    if(fx!=fy) pr[fx]=fy;
}

int main()
{
    scanf("%d%d",&n,&m);
    int x,y,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&cr[i].x,&cr[i].y,&cr[i].v);
    }
    sort(cr+1,cr+m+1,cmp);
    memset(pr,0,sizeof(pr));
    memset(en,0,sizeof(en));
    for(int i=1;i<=n;i++) {pr[i]=i;en[i]=0;}
    for(int i=1;i<=m;i++)
    {
        x=cr[i].x;
        y=cr[i].y;
        int fx=get_father(x);
        int fy=get_father(y);
        if(fx==fy)
        {
            printf("%d\n",cr[i].v);
            return 0;
        }
        if(en[x]==0) en[x]=y;
        else Union(y,en[x]);
        if(en[y]==0) en[y]=x;
        else Union(x,en[y]);
    }
    printf("0\n");
    return 0;
}
