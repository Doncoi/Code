#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct node{int x,y,z;node(int x1=0,int y1=0,int z1=0){x=x1,y=y1,z=z1;}};

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int a[11][11][11][11];
int key[11][11];
int dis[11][11][1<<15];
bool vis[11][11][1<<15];
queue<node >que;
int n,m,k,w;

int main(){

    scanf("%d%d%*d%d",&n,&m,&k);
    for(int i=1,b,c,d,e,f;i<=k;++i){
        scanf("%d%d%d%d%d",&b,&c,&d,&e,&f);
        if(!f)
            a[d][e][b][c] = a[b][c][d][e] = -1;
        else
            a[d][e][b][c] = a[b][c][d][e] |= 1<<f;
    }
    scanf("%d",&w);
    for(int i=1,b,c,d;i<=w;++i){
        scanf("%d%d%d",&b,&c,&d);
        key[b][c] |= 1<<d;
    }

    memset(dis,0x3f,sizeof dis);
    dis[1][1][0] = 0;
    que.push(node(1,1,0));
    node now;

    do{

        now = que.front();
        que.pop();
        vis[now.x][now.y][now.z] = false;

        for(int i=0,p,q,r;i<4;++i){
            p = now.x+dx[i];
            q = now.y+dy[i];
            if(p>0 && q>0 && p<=n && q<=m && dis[p][q][now.z]>dis[now.x][now.y][now.z]+1 && a[p][q][now.x][now.y]!=-1 && (now.z&a[p][q][now.x][now.y])==a[p][q][now.x][now.y]){
                dis[p][q][now.z|key[p][q]] = dis[p][q][now.z] = dis[now.x][now.y][now.z]+1;
                if(!vis[p][q][now.z|key[p][q]]){
                    vis[p][q][now.z|key[p][q]] = true;
                    que.push(node(p,q,now.z|key[p][q]));
                }
            }
        }

    }while(!que.empty());

    int ans = 0x3f3f3f3f;
    for(int i=0;i<(1<<(w+1));++i)
        ans = min(ans,dis[n][m][i]);
    if(ans == 0x3f3f3f3f)
        printf("-1");
    else
        printf("%d",ans);

    return 0;

}
