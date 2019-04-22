#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 50000 + 5
#define MAXM 300000 + 5
#define MAXF 1000 + 5
#define INF 0x3f3f3f3f

int n, m, f, s, t; 
int flight[MAXF];
int cnt;
long long ans = INF;

struct Node
{
    int head;
    long long dis;
    bool vis;
} node[MAXN];

struct Edge
{
    int to, next, cost;
    bool flag;
} edge[MAXM];

struct Dist
{
    int dist, x;

    Dist(int x = 0, long long dist = INF) : dist(dist), x(x) {}
    bool operator()(Dist l, Dist r)
    {
        return l.dist > r.dist;
    }
};

std :: priority_queue<Dist, std ::vector<Dist>, Dist> q;

inline long long min(long long a, long long b)
{
    return (a < b ? a : b);
}

inline int read()
{
    char ch = getchar();
    int res = 0;
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res;
}

inline void addEdge(int from, int to, int cost, bool used)
{
    edge[++ cnt].to = to, edge[cnt].cost = cost, edge[cnt].flag = used;
    edge[cnt].next = node[from].head, node[from].head = cnt;
}

long long Dijkstra()
{
    for (int i = 1; i <= n; ++i)
        node[i].dis = INF;
    node[s].dis = 0; q.push(Dist(s, 0));

    while (!q.empty())
    {
        //std :: cout << "All Right" << std :: endl;
        Dist tmp = q.top();
        q.pop();

        int u = tmp.x;
        long long d = node[u].dis;
        if (tmp.dist != d)
            continue;

        for (int e = node[u].head, v; e && edge[e].flag; e = edge[e].next)
        {
            if (node[v = edge[e].to].dis <= d + edge[e].cost)
                continue;
            node[v].dis = d + edge[e].cost;
            q.push(Dist(v, node[v].dis));
        }
    }

    return node[t].dis;
}

int main()
{
    n = read(), m = read(), f = read(), s = read(), t = read();
    for(int i = 1; i <= m; ++ i)
    {
        int u = read(), v = read(), w = read();
        addEdge(u, v, w, true), addEdge(v, u, w, true);
    }
    for(int i = 1; i <= f; ++ i)
    {
        int u = read(), v = read(), w = 0;
        addEdge(u, v, w, false);
        flight[i] = cnt;
    }

    ans = min(ans, Dijkstra());
    for(int i = 1; i <= f; ++ i)
    {
        edge[flight[i]].flag = true;
        ans = min(ans, Dijkstra());
        edge[flight[i]].flag = false;
    }

    std :: cout << ans << std :: endl;
    return 0;
}