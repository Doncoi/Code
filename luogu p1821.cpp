#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1000 + 5
#define MAXM 100000 + 5
#define INF 0x3f3f3f3f

using namespace std;

int n, m, s;
int u, v, w;
int cnt_1, cnt_2, ans;

struct Node
{
    int head, dis;
    bool in_queue;
} node_1[MAXN], node_2[MAXN];

struct Edge
{
    int to, next, len;
} edge_1[MAXM], edge_2[MAXM];

void addEdge_1(int u, int v, int w)
{
    edge_1[++ cnt_1].to = v, edge_1[cnt_1].len = w;
    edge_1[cnt_1].next = node_1[u].head;
    node_1[u].head = cnt_1;
}

void addEdge_2(int u, int v, int w)
{
    edge_2[++ cnt_2].to = v, edge_2[cnt_2].len = w;
    edge_2[cnt_2].next = node_2[u].head;
    node_2[u].head = cnt_2;
}

inline int read() {
    char ch = getchar(); int res = 0;
    while( ch < '0' || ch > '9' ) ch = getchar();
    while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
    return res;
}

//涓€鑸矾杩嘢PFA
void SPFA_1()
{
    queue<int> q;
    for(int i = 1; i <= n; ++ i)
        node_1[i].dis = INF;
    node_1[s].dis = 0;
    node_1[s].in_queue = true, q.push(s);

    while(! q.empty())
    {
        int u = q.front(); node_1[u].in_queue = false; q.pop();
        for(int e = node_1[u].head, v; e; e = edge_1[e].next)
        {
            if(node_1[v = edge_1[e].to].dis > node_1[u].dis + edge_1[e].len)
            {
                node_1[v].dis = node_1[u].dis + edge_1[e].len;
                if(! node_1[v].in_queue)
                {
                    q.push(v); 
                    node_1[v].in_queue = true;
                }
            }
        }
    }
}

void SPFA_2()
{
    queue<int> q;
    for(int i = 1; i <= n; ++ i)
        node_2[i].dis = INF;
    node_2[s].dis = 0;
    node_2[s].in_queue = true, q.push(s);

    while(! q.empty())
    {
        int u = q.front(); node_2[u].in_queue = false; q.pop();
        for(int e = node_2[u].head, v; e; e = edge_2[e].next)
        {
            if(node_2[v = edge_2[e].to].dis > node_2[u].dis + edge_2[e].len)
            {
                node_2[v].dis = node_2[u].dis + edge_2[e].len;
                if(! node_2[v].in_queue)
                {
                    q.push(v); 
                    node_2[v].in_queue = true;
                }
            }
        }
    }
}

int main()
{
    n = read(), m = read(), s = read();
    for(int i = 1; i <= m; ++ i)
    {
        u = read(), v = read(), w = read();
        addEdge_1(u, v, w), addEdge_2(v, u, w);
    }

    SPFA_1(); SPFA_2();

    for(int i = 1; i <= n; ++ i)
    {
        if(node_1[i].dis + node_2[i].dis > ans)
        {
        	if(node_1[i].dis == INF || node_2[i].dis == INF)
        		continue;
            ans = node_1[i].dis + node_2[i].dis;
		}
    }

    cout << ans << endl;
}