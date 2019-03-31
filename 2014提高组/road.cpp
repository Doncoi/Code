//road.cpp By Doncoi
//上一次提交没有写文件 气死欧累(#`O′)
#include <cstdio>       
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 10010
#define MAXM 200010
using namespace std;

int n, m, head, tail;
int x[MAXM], y[MAXM];
int next[MAXM * 2], to[MAXM * 2], pre[MAXM];
int tot, s, t, q[MAXN], step[MAXN];
bool vis[MAXN];

void add_edge(int a, int b) {
    to[++tot] = b;
    next[tot] = pre[a];
    pre[a] = tot;
}

void bfs1() {
    q[0] = t;    vis[t] = true;    head = 0;    tail = 1;
    while (head < tail) {
        int u = q[head++];
        for (int i = pre[u];i;i = next[i]) {
            if (!vis[to[i]]) {
                vis[to[i]] = true;
                q[tail++] = to[i];
            }
        }
    }
}

bool next_edge(int q) {
    for (int i = pre[q]; i; i = next[i])
        if (!vis[to[i]])
            return false;
    return true;
}

bool bfs2() {
    head = 0;
    tail = 1;
    q[0] = s;
    step[s] = 0;
    while (head < tail) {
        int u = q[head++];
        if (!next_edge(u))
            continue;
        for (int i = pre[u]; i; i = next[i]) {
            if (step[to[i]] == -1) {
                step[to[i]] = step[u] + 1;
                q[tail++] = to[i];
                if (to[i] == t) {
                    printf("%d", step[to[i]]);
                    return true;
                }
            }
        }
    }
    return false;
}

void init() {
    memset(pre, 0, sizeof(pre));
    memset(step, -1, sizeof(step));
    memset(q, 0, sizeof(q));
    memset(next, 0, sizeof(next));
    memset(to, 0, sizeof(to));
    tot = 0;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    memset(vis, false, sizeof(vis));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x[i], &y[i]);
        add_edge(y[i], x[i]); 
    }

    scanf("%d%d", &s,&t);
    bfs1();
    init();
    for (int i = 1; i <= m; i++)
        add_edge(x[i], y[i]);

    if (!vis[s])  printf("-1\n");
    else if (!bfs2()) printf("-1\n");

    fclose(stdin);
    fclose(stdout);
}