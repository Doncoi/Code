#include<cstdio>
#include<vector>
using namespace std;
#define N 30010
int n,deep[N],g[N][25];
vector<int>p[N];
void dfs(int x,int de){
    for(int i=0;i<p[x].size();i++){
        if(!deep[p[x][i]]){
            deep[p[x][i]]=deep[x]+1;
            g[p[x][i]][0]=x;
            dfs(p[x][i],de+1);
        }
    }
}
int lca(int a,int b){
    if(deep[a]<deep[b]) swap(a,b);
    int t=deep[a]-deep[b];
    for(int i=0;i<=20;i++){
        if((1<<i)&t){
            a=g[a][i];
        }
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--){
        if(g[a][i]!=g[b][i]){
            a=g[a][i];
            b=g[b][i];
        }
    }
    return g[a][0];
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        p[x].push_back(y);
        p[y].push_back(x);
    }
    dfs(1,1);
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            g[i][j]=g[g[i][j-1]][j-1];
        }
    }
    int x,y,q,ans=0;
    scanf("%d%d",&q,&x);
    for(int i=1;i<q;i++){
        scanf("%d",&y);
        int gg=lca(x,y);
        ans+=deep[x]+deep[y]-2*deep[gg];
        x=y;
    }
    printf("%d\n",ans);
    return 0;
}
