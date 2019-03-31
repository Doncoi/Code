#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))

int n;
long long w[MAXN];
int head[MAXN], tot;
int vis[MAXN], root, _root, cut; 
long long maxc[MAXN][3], ans;

struct Edge {
    int to, next;
} edge[MAXN * 2];

void addEdge(int u, int v) {
    edge[tot].to=v, edge[tot].next = head[u], head[u] = tot++;
}

void findOnecircle(int u, int fa) {
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        if(v == fa) continue;
        if(!vis[v]) findOnecircle(v, u);
        else root = v, _root = u, cut = i; 
    }
}

void treeMaxind(int u, int fa){
    maxc[u][1] = w[u], maxc[u][0] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(i == cut || i == (cut ^ 1) || v == fa) continue;
        treeMaxind(v, u);
        maxc[u][1] += maxc[v][0];
        maxc[u][0] += std :: max(maxc[v][0], maxc[v][1]);
    }
}

long long onecircleTreeMaxind(int u) {
    long long tmp = 0;
    findOnecircle(u, -1); 
    treeMaxind(root, -1);
    tmp = maxc[root][0];
    treeMaxind(_root, -1);
    tmp = std :: max(tmp, maxc[_root][0]);
    return tmp;
}

int main() {
    scanf("%d", &n);
    mem(head, -1), ans = 0, tot = 0;
    mem(vis, 0), mem(maxc, 0);
    for(int i = 1; i <= n; i ++) {
        int a, b;
        scanf("%lld %d", &a, &b);
        w[i] = a;
        addEdge(i, b), addEdge(b, i);
    }

    for(int i = 1; i <= n; i ++){
        if(vis[i]) continue;
        ans += onecircleTreeMaxind(i);
    }
    printf("%lld\n", ans);
    return 0;
}
