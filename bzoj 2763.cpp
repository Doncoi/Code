#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 1200000 + 5
using namespace std;
 
int n, m, k, s, t, cnt;
int head[MAXN], dis[MAXN], vis[MAXN];
 
struct Node
{
    int to, val, next;
} edge[MAXN << 1];
 
struct Dist
{
    int val, no;
};
 
bool operator < (Dist a, Dist b)
{
    if(a.val == b.val) 
        return a.no < b.no;
    return a.val > b.val;
}
 
priority_queue<Dist> q;

void Dijkstra()
{
    memset(dis,0x3f,sizeof(dis));
    Dist fir;
    fir.val=0, fir.no=s;
    dis[s]=0; q.push(fir);
 
    while(!q.empty())
    {
        Dist u = q.top(); q.pop();
        if(vis[u.no])continue;
        vis[u.no] = 1;
        for(int e = head[u.no]; e != -1; e = edge[e].next)
        {
            int v = edge[e].to;
            if(dis[u.no] + edge[e].val < dis[v])
            {
                dis[v] = dis[u.no] + edge[e].val;
                Dist pus; pus.no = v, pus.val = dis[v];
                q.push(pus);
            }
        }
    }
 
    int ans = INF;
    for(int i = 0; i <= k; ++ i)
        ans = min(ans, dis[t + i * n]);
    cout << ans << endl;
}
 
void init()
{
    memset(head, -1, sizeof(head));
    cnt = 1;
}
 
void addEdge(int u, int v, int w)
{
    edge[cnt].to = v, edge[cnt].val = w;
    edge[cnt].next = head[u], head[u] = cnt ++;
}
 
int main()
{
    init();
    cin >> n >> m >> k >> s >> t;
    s ++, t ++;
 
    for(int i = 1; i <= m; ++ i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u ++, v ++;
        for(int i = 0; i <= k; ++ i)
        {
            addEdge(u + i * n, v + i * n, w);
            addEdge(v + i * n, u + i * n, w);
            if(i != k)
            {
                addEdge(u + i * n, v + (i + 1) * n, 0);
                addEdge(v + i * n, u + (i + 1) * n, 0);
            }
        }
    }
 
    Dijkstra();
}
