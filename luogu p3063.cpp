#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3
#define MAXN 500 + 5
#define MAXM 1000 + 5

 using namespace std;

struct Edge
{
    int nxt, to, dis, flow;
} edge[MAXM];

int n, m, k, s, t, cnt, ans;
int head[MAXN], dis[MAXN], vis[MAXN], flow[MAXN];

inline void addEdge(int u, int v, int w, int f)
{
    edge[++ cnt].nxt = head[u], head[u] = cnt;
    edge[cnt].to = v, edge[cnt].flow = f, edge[cnt].dis = w;
}

inline void SPFA(int min_flow)
{
    queue<int> q;
    memset(dis, 50, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    q.push(s); dis[s]=0, vis[s]=1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop(); vis[u] = 0;
        for(int e = head[u], v; e; e = edge[e].nxt)
        {
            if(dis[v = edge[e].to] > dis[u] + edge[e].dis && edge[e].flow >= min_flow)
            {
                dis[v] = dis[u] + edge[e].dis;
                if(! vis[v])
                {
                    q.push(v); vis[v]=1;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k; 
    s = 1, t = n;
    for(int i = 1; i <= m; ++ i)
    {
        int u, v, w, f;
        cin >> u >> v >> w >>f;
        addEdge(u, v, w, f), addEdge(v, u, w, f);
        flow[i] = f;
    }
    sort(flow + 1, flow + m + 1);

    ans = INF;
    for(int i = 1; i <= m; ++ i)
    {
        SPFA(flow[i]);
        ans = min(ans, dis[t] + k / flow[i]);
    }
    cout << ans << endl;
}