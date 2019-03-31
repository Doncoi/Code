#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define pb push_back
#define N 700100
using namespace std;
int dp,pre[N],p[N],to[N],weight[N],fa[N],deep[N],v[N],A[N],B[N],LCA[N];
int s[N][20],n,m,a,b,c,i,sum[N],ans,cnt,dis[N],dist[N];

void addEdge(int x,int y,int z) {
    dp ++;
    pre[dp] = p[x];
    p[x] = dp;
    to[dp] = y;
    weight[dp] = z;
}

void dfs(int x) {
    int i;
    i = p[x];
    while (i) {
        if (to[i]!=fa[x]) {
            deep[to[i]]=deep[x]+1;
            fa[to[i]]=x;
            v[to[i]]=weight[i];
            dis[to[i]]=dis[x]+weight[i];
            dfs(to[i]);
        }
        i=pre[i];
    }
}

int lca(int x,int y) {
    if(deep[x]>deep[y])x^=y^=x^=y;
    int i;
    for(i=19;i>=0;i--) {
        if(deep[y]-deep[x]>=(1<<i)) {
            y=s[y][i];
        }
    }
    if(x==y)return x;
    for(i=19;i>=0;i--) {
        if(s[x][i]!=s[y][i]) {
            x=s[x][i];
            y=s[y][i];
        }
    }
    return fa[x];
}

void gao(int x) {
    int i=p[x];
    while (i) {
        if (to[i]!=fa[x]) {
            gao(to[i]);
            sum[x]+=sum[to[i]];
        }
        i=pre[i];
    }
}

int check(int x) {
    int cnt=0,dec=0;	
    for (i=1;i<=n;i++)
    sum[i]=0;
    for (i=1;i<=m;i++)
    if (dist[i]>x) {
        cnt++;
        dec=max(dec,dist[i]-x);
        sum[A[i]]++;
        sum[B[i]]++;
        sum[LCA[i]]-=2;
    }
    gao(1);
    for (i=1;i<=n;i++)
    if ((sum[i]==cnt)&&(v[i]>=dec)) return 1;
    return 0;
} 

int main() {
    scanf("%d%d",&n,&m); 
    for (i=1;i<n;i++) {
        scanf("%d%d%d",&a,&b,&c);
        addEdge(a,b,c);
        addEdge(b,a,c);
    }

    dfs(1);
    for(i=1;i<=n;i++)s[i][0]=fa[i];
    for(int h=1;h<20;h++) {
        for(i=1;i<=n;i++) {
            s[i][h]=s[s[i][h-1]][h-1];
        }
    }
    
    for (i=1;i<=m;i++) {
        scanf("%d%d",&A[i],&B[i]);
        LCA[i]=lca(A[i],B[i]);
        dist[i]=dis[A[i]]+dis[B[i]]-2*dis[LCA[i]];
    }
    int L=0,R=0;    
    for (i=1;i<=m;i++)
    R=max(R,dist[i]);
    int mid;
    while (L<=R) {
        mid=(L+R)>>1;
        if (check(mid)) R=mid-1;else L=mid+1;
    }
    printf("%d\n",L);
}