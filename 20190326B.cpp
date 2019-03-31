#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 200000 + 5

struct Node
{
    std :: vector<int> edge;
    bool vis;
} node[MAXN];

int n;

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

inline void addEdge(int u, int v)
{
    node[u].edge.push_back(v);
    node[v].edge.push_back(u);
}

void sort()
{
    for(int i = 1; i <= n; ++ i)
    {
        std :: sort(node[i].edge.begin(), node[i].edge.end());
    }
}

void init()
{
    for(int i = 1; i <= n; ++ i)
    {
        node[i].vis = false;
    }
}

void travel(int u, int *step)
{
    std :: vector<int> :: iterator e; int v;
    for(e = node[u].edge.begin(); e != node[u].edge.end(); ++ e)
    {
        if((v = *e) == 1) 
        {
            if(*step == 0) ++ *step;
            return;
        }
        if(node[v].vis) continue;
        node[v].vis = true, ++ *step;
        travel(v, step);
    }
}

void solve(int u)
{
    init();
    int res = 0;
    travel(u, &res);
    std :: cout << res << " ";
}

int main()
{   
    n = read();
    for(int i = 1; i <= n - 1; ++ i)
    {
        addEdge(read(), read());
    }
    for(int i = 2; i <= n; ++ i)
    {
        solve(i);
    }
}
