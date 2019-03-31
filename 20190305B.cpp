#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100 + 5
#define MAXM 500

struct Node
{
    int head, color;
} node[MAXN];

struct Edge
{
    int to, next, color;
} edge[MAXM * 2 + 5];

int n, m, cnt;
bool fillJudge[5];

int reverge(int e)
{
    return e > MAXM ? e - MAXM : e + MAXM;
}

void addEdge(int u, int v)
{
    edge[++ cnt].to = u, edge[cnt].color = 0;
    edge[cnt].next = node[u].head, node[u].head = cnt;

    edge[reverge(cnt)].to = v, edge[reverge(cnt)].color = 0;
    edge[reverge(cnt)].next = node[v].head, node[v].head = reverge(cnt);
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    n = read(), m = read();
    for(int i = 1; i <= m; ++ i)
    {
        addEdge(read(), read());
    }

    for(int i = 1; i <= n; ++ i)
    {
        memset(fillJudge, false, sizeof(fillJudge));
        for(int e = node[i].head; e; e = edge[e].next)
        {
            if(edge[e].color) fillJudge[edge[e].color] = true;
            if(edge[reverge(e)].color) fillJudge[edge[reverge(e)].color] = true;
        }

        for(int j = 1; j <= 4; ++ j)
            if(! fillJudge[j]) 
            {
                node[i].color = j;
                std :: cout << j;
                break;
            }

        for(int e = node[i].head; e; e = edge[e].next)
        {
            if(edge[e].color || edge[reverge(e)].color) continue;
            edge[e].color = edge[reverge(e)].color = node[i].color;
        }
    }
}
