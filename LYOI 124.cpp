#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int inf = 0x3f3f3f3f;

int head[1447],nxt[4714],to[4714],wei[4714],tot=1;
int n,m;
int a[47][47];
int cur[1447];
int ans = 0;
queue<int> que;
int c[1447];

void add(int,int,int);
bool bfs();
int dinic(int,int);

int main(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
            ans += a[i][j];
        }

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(((i&1)&&(j&1)) || ((!(i&1))&&(!(j&1)))){
                add(1445,(i-1)*m+j,a[i][j]);
                if(i>1) 
                    add((i-1)*m+j,(i-2)*m+j,inf);
                if(i<n) 
                    add((i-1)*m+j,i*m+j,inf);
                if(j>1) 
                    add((i-1)*m+j,(i-1)*m+j-1,inf);
                if(j<m) 
                    add((i-1)*m+j,(i-1)*m+j+1,inf);
            }
            else
                add((i-1)*m+j,1446,a[i][j]);

    int flag;
    while(bfs()){
        memcpy(cur,head,sizeof head);
        flag = 1;
        while(flag){
            flag = dinic(1445,inf);
            ans -= flag;
        }
    }

    printf("%d",ans);

    return 0;

}

void add(int from,int tp,int value){

    ++tot;nxt[tot]=head[from];head[from]=tot;to[tot]=tp;wei[tot]=value;
    ++tot;nxt[tot]=head[tp];head[tp]=tot;to[tot]=from;wei[tot]=0;

}

bool bfs(){

    memset(c,0,sizeof c);
    c[1445] = 1;
    que.push(1445);

    int now;

    do{

        now = que.front();
        for(int i=head[now];i;i=nxt[i])
            if(!c[to[i]] && wei[i]){
                c[to[i]] = c[now]+1;
                que.push(to[i]);
            }

        que.pop();

    }while(!que.empty());

    return c[1446];

}

int dinic(int place,int low){

    if(place == 1446)
        return low;

    int lower;
    for(int& i=cur[place];i;i=nxt[i])
        if(c[to[i]]==c[place]+1 && wei[i]){
            lower = dinic(to[i],min(low,wei[i]));
            if(lower){
                wei[i] -= lower;
                wei[i^1] += lower;
                return lower;
            }
        }

    return 0;

}
