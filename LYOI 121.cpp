#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define INF 0x7fffffff

int n, m, a[151], c[271], fi[501], ne[500001], w[500001], cnt, tot, ans, dis[501], totnum, v[501][501];

void addEdge(int u, int vv, int val) {
    w[++ cnt] = vv; ne[cnt] = fi[u]; fi[u] = cnt; v[u][vv] += val;
    w[++ cnt] = u; ne[cnt] = fi[vv]; fi[vv] = cnt;
}

inline bool bfs() {
    std :: queue<int> q;
    memset(dis, -1, sizeof(dis));
    q.push(0);  dis[0] = 0;

    while(!q.empty()) {
        int k = q.front();  q.pop();
        for(int i = fi[k]; i; i = ne[i])
          if(v[k][w[i]] > 0 && dis[w[i]] == -1) {
            dis[w[i]] = dis[k] + 1;  q.push(w[i]);
          }
    }

    if(dis[tot] == -1) return false;
    return true;
}

int findd(int u, int vv) {
    if(u == tot) return vv;
    int now = 0, kkz;
    for(int i = fi[u]; i; i = ne[i])
        if(v[u][w[i]] > 0 && dis[w[i]] == dis[u] + 1 && (kkz = findd(w[i], std :: min(v[u][w[i]], vv - now)))) {
            v[u][w[i]] -= kkz;  v[w[i]][u] += kkz; now += kkz;
            if(now == vv) return now;
        }
    if(!now) dis[u] = -1;
    return now;
}

int main() {
    scanf("%d%d", &m, &n); tot = m + n + 1;
    for(int i = 1; i <= m; i ++) {
        scanf("%d", &a[i]); addEdge(0, i, a[i]); totnum += a[i];
    }
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &c[i]); addEdge(i + m, tot, c[i]); 
        for(int j = 1; j <= m; j ++) addEdge(j, i + m, 1);
    }

    while(bfs()) ans += findd(0, INF);
    if(ans != totnum) {
        printf("0\n");  return 0;
    }
        
    printf("1\n");
    for(int i = 1; i <= m; i ++) {
        for(int j = m + 1; j < tot; j ++)
          if(!v[i][j]) printf("%d ", j - m);
        printf("\n");
    }

    return 0;
}
