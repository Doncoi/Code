#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 5000 + 5

struct Node
{
    int head, otg, num;
} node[MAXN];

struct Edge
{
    int from, to, next;
} edge[MAXN];

int n, cnt, ans;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') res = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
    return res * flg;
}

inline void addEdge(int u, int v)
{
    edge[++ cnt].from = u, edge[cnt]. to = v; 
    edge[cnt].next = node[u].head;
    node[u].head = cnt, node[u].otg ++;
}

inline bool cmp(const Node &x, const Node &y)
{
    if(x.otg == y.otg)
    {
        return x.num > y.num;
    }
    return x.otg > y.otg;
}

int main()
{
    n = read(), cnt = 0, ans = 1;
    for(int i = 1; i <= n; ++ i)
    {
        node[i].num = i, node[i].otg = 0;
    }
    for(int i = 1; i <= n - 1; ++ i)
    {
        int u = read(), v = read();
        addEdge(u, v);
    }

    std :: sort(node + 1, node + n + 1, cmp);
    /*
    for(int i = 1; i <= n; ++ i)
    {
        std :: cout << node[i].num << " " << node[i].otg << std :: endl;
    }
    */

    if(node[1].num == 1) 
    {
        ans += node[1].otg - 1;
    }
    else
    {
        ans += node[1].otg;
    }
    if(node[2].num == 1)
    {
        ans += node[2].otg - 1;
    }
    else 
    {
        ans += node[2].otg;
    }

    //std :: cout << node[1].num << " " << node[2].num << std :: endl;

    for(int e = node[2].head; e; e = edge[e].next)
    {
        if(edge[e].to == node[1].num) -- ans;
    }
    for(int e = node[1].head; e; e = edge[e].next)
    {
        if(edge[e].to == node[2].num) -- ans;
    }

    std :: cout << ans << std :: endl;
}

/*
11
1 2
1 3
1 4
2 5 
2 6
2 7
3 8
4 9
4 10
4 11

7


12
1 2
1 3
1 4
1 12
2 5
2 6
2 7
3 8
4 9
4 10
4 11

6
*/