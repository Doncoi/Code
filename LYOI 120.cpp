#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MAXN 10010
#define INF 0x7fffffff

const int m = 5000;
const int T = 10000;

int n, ans, s, cnt = 1;
int head[MAXN], h[MAXN], to[MAXN];
bool used[MAXN];

struct Edge {
    int next, to, s;
} edge[MAXN * 20];

void addEdge(int x, int y, int z) {
    edge[++cnt].next = head[x];
    edge[cnt].to = y;
    edge[cnt].s = z;
    head[x] = cnt;
}

void insert(int x, int y) {
    addEdge(x, y, 1), addEdge(y, x, 0);
}

bool makeLevelGraph() {
    std :: queue<int>Q;
    memset(h, -1, sizeof(h));
    h[0] = 0;
    Q.push(0);
    while(!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for(int i = head[now]; i; i = edge[i].next) {
            if(h[edge[i].to] == -1 && edge[i].s) {
                h[edge[i].to] = h[now] + 1;
                Q.push(edge[i].to);
            }
        }
    }
    if(h[T]==-1)return false;
    return true;
}

int augument(int u, int f) {
    if(u == T) return f;
    int used = 0;
    for(int i = head[u]; i; i = edge[i].next) {
        if(!edge[i].s || h[edge[i].to] != h[u] + 1) continue;
        int w = f - used;
        w = augument(edge[i].to, std :: min(w, edge[i].s));
        edge[i].s -= w;
        edge[i ^ 1].s += w;
        used += w;
        if(used == f) return f;
    }
    if(!used) h[u] = -1;
    return used;
}

void Dinic() {
    while(makeLevelGraph())
        ans -= augument(0, INF);
}

void output() {
    for(int i = 1; i < s; i ++) {
        for(int j = head[i]; j; j = edge[j].next) {
            if(edge[j].s) continue;
            to[i] = edge[j].to - m;
            break;
        }
    }
    for(int i = 1; i < s; i ++) {
        if(used[i]) continue;
        int t = i;
        while(t != -m) {
            printf("%d ", t);
            used[t] = true;
            t = to[t];
        }
        puts("");
    }
}

int main() {
    std :: cin >> n;
    for( ; ; ) {
        ans ++,s ++;
        for(int i = 1; i < s; i ++)
            if(sqrt(i + s) == (int)sqrt(i + s))
                insert(i, s + m);
        insert(0, s), insert(s + m, T);
        Dinic();
        if(ans > n)break;
    }
    printf("%d\n", s - 1);
    output();
    return 0;
}       
