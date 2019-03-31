#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 300
#define M 11000
std :: queue<int> q;

int to[M], val[M], flow[M], next[M], head[N], tot;
int dis[N], pre[N], s, t;
bool inq[N];

inline void add(int x,int y,int v,int fl) {
    to[++tot] = y, val[tot] = v,flow[tot] = fl, next[tot] = head[x], head[x] = tot;
    to[++tot] = x, val[tot] = -v,flow[tot] = 0, next[tot] = head[y], head[y] = tot;
}

inline bool spfa() {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(s), inq[s] = 1;
    int x, y, i;
    while(!q.empty()) {
        x = q.front(),q.pop();
        inq[x] = 0;
        for(i = head[x]; i; i = next[i]) {
            if(flow[i] > 0 && dis[y = to[i]] > dis[x] + val[i]) {
                dis[y] = dis[x] + val[i], pre[y] = i;
                if(!inq[y]) q.push(y), inq[y]=1;
            }
        }
    }
    if(dis[t]==0x3f3f3f3f) return false;
    else return true;
}

int mcmf() {
    int i, fl = 0x3f3f3f3f, ret = 0;
    for(i = t; i; i = to[pre[i] ^ 1])
        fl = std ::min(fl, flow[pre[i]]);
    for(i = t; i; i = to[pre[i]^1])
        flow[pre[i]] -= fl,
        flow[pre[i]^1] += fl,
        ret +=  fl * val[pre[i]];
    return ret;
}

void rebuild() {
    for(int i = 2; i <= tot; i += 2) {
        flow[i] = flow[i] + flow[i ^ 1];
        flow[i ^ 1] = 0;
        std :: swap(val[i], val[i ^ 1]);
    }
}

int main() {
    int n, m, i, j, k, x, y, v, ans;
    scanf("%d%d", &n, &m);
    s = 0, t = n + m + 1;
    for(i = 1, tot = 1; i <= n; i ++)
        scanf("%d", &v), add(0, i, 0, v);
    for(i = 1; i <= m; i ++)
        scanf("%d",&v), add(i+n,t,0,v);
    for(i = 1; i <= n; i ++)
        for(j = 1; j <= m; j ++)
            scanf("%d", &v), add(i,j+n,v,0x3f3f3f3f);

    ans = 0;
    while(spfa())
        ans += mcmf();
    printf("%d\n", ans);

    rebuild();
    ans = 0;
    while(spfa())
        ans+=mcmf();
    printf("%d\n", -ans);
    
    return 0;
} 
