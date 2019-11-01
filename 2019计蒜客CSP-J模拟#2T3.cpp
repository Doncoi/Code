#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
​
#define int long long
#define random(a,b) (a+rand()%(b-a+1))
​
using namespace std;
​
inline int read() {
    int w = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        w = (w << 3) + (w << 1) + ch - 48;
        ch = getchar();
    }
    return w * f;
}
​
int n, m, dis[100010], val[100010], head[100010], cnt;
​
struct Edge{
    int from, to, next, dis;
}edge[1000010];
​
inline void addedge(int u, int v, int w) {
    cnt++;
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].dis = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

inline void ins(int u, int v, int w) {
    addedge(u, v, w);
    addedge(v, u, w);
    return ;
}
struct Node {
    int u, dis;
   friend bool operator < (Node u, Node v) {
    return u.dis > v.dis;
    }
};
​
priority_queue <Node> q;
​
inline void Dij(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0;
    q.push((Node){st, dis[st]});
    while(!q.empty()) {
        Node front = q.top();
        q.pop();
        int u = front.u;
        if(dis[u] != front.dis) continue;
        for(int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if(dis[v] > dis[u] + edge[i].dis){
                dis[v] = dis[u] + edge[i].dis;
                q.push((Node){v, dis[v]});
                q.push((Node){v, dis[v]});
            }
        }
    }
    return ;
}
​
signed main() {
    n = read();
    m = read();
    for(int i = 1; i <= n; i++) 
        val[i] = read();
    for(int i = 1; i <= m; i++) 
    {
        int x = read();
        int y = read();
        int z = read();
        ins(x, y, z);
    }

    Dij(n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dis[i] <= dis[1]) ans += val[i];
    }
    cout << ans << endl;
    return 0;
}
