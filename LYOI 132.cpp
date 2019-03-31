#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
#define Maxn 4100
#define INF 0xfffffff

struct node {
    int x,y,f,o,next;
} t[Maxn * 1010]; 

int len, first[Maxn], n,m,k;
int hp[110],rl[110][110],cnt=2,add;
vector<int > num[110];

int mymin(int x,int y) {return x<y?x:y;}
int mymax(int x,int y) {return x>y?x:y;}

void ins(int x,int y,int f) {
    t[++len].x=x;t[len].y=y;t[len].f=f;
    t[len].next=first[x];first[x]=len;t[len].o=len+1;
    t[++len].x=y;t[len].y=x;t[len].f=0;
    t[len].next=first[y];first[y]=len;t[len].o=len-1;
}

int st,ed;
queue<int > q;
int dis[Maxn];

bool bfs() {
    while(!q.empty()) q.pop();
    memset(dis,-1,sizeof(dis));
    q.push(st);dis[st]=0;
    while(!q.empty()) {
        int x=q.front();
        for(int i=first[x];i;i=t[i].next) if(t[i].f>0) {
            int y=t[i].y;
            if(dis[y]==-1) {
                dis[y]=dis[x]+1;
                q.push(y);
            }
        }
        q.pop();
    }
    if(dis[ed]==-1) return 0;
    return 1;
 }

 int ffind(int x, int flow) {
    if(x == ed) return flow;
    int now = 0;
    for(int i = first[x]; i; i = t[i].next) if(t[i].f > 0) {
        int y = t[i].y; 
        if(dis[y] == dis[x] + 1) {
            int a = ffind(y, mymin(flow - now, t[i].f));
            t[i].f -= a;
            t[t[i].o].f += a;
            now += a;
        }
        if(now == flow) break;
    }
    if(now == 0) dis[x] = -1;
    return now;
} 

int max_flow() {
   int ans = 0;
    while(bfs())
        ans += ffind(st, INF);
    return ans;
}

bool check(int x) {
    for(int i=1;i<=n;i++) num[i].push_back(++cnt);
    num[0].push_back(1);num[n+1].push_back(2);
    for(int i=1;i<=m;i++) {
        int y=rl[i][(x-1)%rl[i][0]+1],z=rl[i][x%(rl[i][0])+1];
        if(z==0||y==n+1) continue;
        y=num[y][x];z=num[z][x+1];
        ins(y,z,hp[i]);
    }
    for(int i=1;i<=n;i++) ins(num[i][x],num[i][x+1],INF);
    int now=max_flow();
    add+=now;
    return add>=k;
}
 
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d", &hp[i], &rl[i][0]);
        for(int j = 1; j <= rl[i][0]; j ++) {
            scanf("%d", &rl[i][j]);
            if(rl[i][j] == -1) rl[i][j] = n + 1;
        }
    }
    for(int i = 1; i <= m; i ++) num[i].clear();
    for(int i = 0; i <= n + 1; i ++) num[i].push_back(0);//00000
    int ans = 0; st = 1, ed = 2;
    for(int i = 1; i <= n; i ++) num[i].push_back(++ cnt);
    num[0].push_back(1); num[n + 1].push_back(2);
    add = 0;
    while(1) {
        ans ++;
        if(check(ans)) {printf("%d\n", ans); break;}
        if(ans > 100) {printf("0\n"); break;}
    }
    
    return 0;
}
