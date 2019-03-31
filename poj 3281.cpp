#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 500
#define INF 0x3fffffff

int g[MAXN][MAXN];
int path[MAXN], cap[MAXN], s, t;
int n;

std :: queue<int> q;

int bfs() {
    int i, tmp;
    while(!q.empty()) q.pop();
    memset(path, -1, sizeof(path));
    path[s] = 0;    cap[s] = INF;	q.push(s);

    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        if(tmp == t) break;
        for(i = 0; i <= n; ++ i) {
            if(i != s && path[i] == -1 && g[tmp][i]) {
                cap[i] = std :: min(cap[tmp], g[tmp][i]);
                q.push(i);
                path[i] = tmp;
            }
        }
    }

    if(path[t] == -1) {
    	return -1;
    } else {
    	return cap[t];
    }
}

int edmordsKarp() {
    int flow, ans = 0;
 
    while((flow = bfs()) != -1) {
        ans += flow;
        for(int tmp = t; tmp != s; tmp = path[tmp]) {
            g[path[tmp]][tmp] -= flow;
            g[tmp][path[tmp]] += flow;
        }
    }
    return ans;
}

int main() {
    int N,F,D;
    while(scanf("%d%d%d", &N, &F, &D) != EOF) {
        memset(g, 0, sizeof(g));
        n = F + D + 2 * N + 1;    s = 0;    t = n;

        for(int i = 1; i <= F; ++ i) g[0][i] = 1;
        for(int i = 1; i <= N; ++ i) g[F + 2 * i - 1][F + 2 * i] = 1;
        for(int i = F + 2 * N + 1; i <= F + 2 * N + D; ++ i) g[i][n] = 1;

        int k1, k2, u;
        for(int i = 1; i <= N; ++ i) {
            scanf("%d %d", &k1, &k2);
            while(k1 --) {
                scanf("%d", &u);
                g[u][F + 2 * i - 1] = 1;
            }
            while(k2 --) {
                scanf("%d", &u);
                g[F + 2 * i][F + 2 * N + u] = 1;
            }
        }
        printf("%d\n",edmordsKarp());
    }
    return 0;
}
