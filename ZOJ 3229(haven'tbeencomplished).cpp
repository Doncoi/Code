#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cmath>
#define MAXN 1505
#define MAXM 100005
#define INF 0x3f3f3f3f

inline int read() {
    char c = getchar();    int tmp = 0, flag = 1;
    while(c <'0' || c > '9') {if(c == '-') flag = -1; c = getchar();} 
    while(c >= '0' && c <= '9') {tmp = tmp * 10 + c - '0'; c = getchar();}

    return tmp * flag;
}

int n, m, cnt, ans;
int day[MAXN];

struct Node {
    int head, cur, level, pre, in;
} node[MAXN];

struct Edge {
    int next, to, cap, low;
} edge[MAXN];

void addEdge(int from, int to, int cap) {
    edge[cnt].next = node[from].head, node[from].head = cnt, edge[cnt].to = to, edge[cnt ++].cap = cap; 
    edge[cnt].next = node[to].head,   node[to].head = cnt,   edge[cnt].to = from, edge[cnt ++].cap = 0;
}

bool bfs(int S, int T) {
    for(int i = 0; i <= MAXN; ++ i) node[i].level = -1;
    int t = 0, w = 1; node[0].pre = S, node[S].level = 0; 

    while(t != w) {
        int now = node[t ++].pre; 
        for(int e = node[now].head; e; e = edge[e].next) {
            if(edge[e].cap && node[edge[e].to].level == -1) 
                node[edge[e].to].level = node[now].level + 1, node[w ++].pre = edge[e].to;
        }
    }

    if(node[T].level == -1) return false;
    else return true;
}

int dfs(int x, int flow, int T) {
    if(x == T) return flow;
    int aug, used = 0;

    for(int e = node[x].cur; e; e = edge[e].next) {
        if(node[edge[e].to].level == node[x].level + 1) {
            aug = flow - used, aug = dfs(edge[e].to, std :: min(edge[e].cap, aug), T);
            edge[e].cap -= aug;     if(edge[e].cap) node[x].cur = e;    edge[e ^ 1].cap += aug;
            used += aug;   if(used == flow) return flow;
        }
    }

    if(!used) node[x].level = 1;
    return used;
}

void Dinic(int S, int T) {
    while(bfs(S, T)) {
        for(int i = 0; i <= n + m + 3; ++ i) {
            node[i].cur = node[i].head;
            dfs(S, INF, T);
        }
    }
}

bool judged() {
    int SS = n + m + 2, TT = n + m + 3; 
    for(int i = 0; i <= n + m + 1; ++ i) {
        if(node[i].in > 0) addEdge(SS, i, node[i].in);
        if(node[i].in < 0) addEdge(i, TT, -node[i].in);
    }

    Dinic(SS, TT);
    for(int e = node[SS].head; e; e = edge[e].next) 
        if(edge[e].cap) return false;
    return true;
}

int main() {
    while(scanf("%d %d", &n, &m)) {
        cnt = ans = 0;    int S = 0, T = n + m + 1, ed = 0;
        for(int i = 0; i <= MAXN; ++ i) node[i].head = node[i].in = 0;

        for(int i = 1; i <= m; ++ i) {
            int g = read(); node[T].in += g;  node[i + n].in -= g;
        }
        for(int i = 1; i <= n; ++ i) {
            int x = read(); day[i]= read();
            for(int j = 1; j <= x; ++ j) {
                int num = read();
                edge[++ ed].low = read(); int r = read();
                addEdge(i, n + num + 1, r - edge[ed].low);
                node[i].in -= edge[ed].low;  node[i + num + 1].in += edge[ed].low;
            }
        }

        for(int i = 1; i <= n; ++ i) addEdge(S, i, day[i]);
        for(int i = 1; i <= m; ++ i) addEdge(i + n, T, INF);
        addEdge(T, S, INF);
 
        if(judged()) {
            Dinic(S, T);    addEdge(T, S, - INF);
            for(int e = node[S].head; e; e = edge[e].next) 
                ans += edge[e ^ 1].cap;

            printf("%d\n", ans);
            for(int i = 1; i <= ed; ++ i) 
                printf("%d\n", edge[(i << 1) ^ 1].cap + edge[i].low);
        } else {
            printf("-1\n");
        }
        printf("");
    }

    return 0;
}
