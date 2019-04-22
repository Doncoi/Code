#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 500000 + 5

int T, u, v, n, m, cnt;
int q[MAXN], l, r;
std :: string s;
std :: map<std :: string, int> M;

struct Node
{
    std :: string name; 
    int head;
    bool voted, controled, conviced;
} node[MAXN];

struct Edge
{
    int from, to, next;
} edge[MAXN];

inline void addEdge(int u, int v)
{
    edge[++ cnt].to = v, edge[cnt].from = u;
    edge[cnt].next = node[u].head, node[u].head = cnt;
}

void solve(int u)
{
    l = 0, r = 0;
    q[++ r] = u;
    while(l <= r)
    {
        int pre = q[++ l];
        //std :: cout << node[u].name << " ";
        node[pre].conviced = true;
        for(int e = node[pre].head; e; e = edge[e].next)
        {
            q[++ r] = edge[e].to;
        }
    }
}

int main()
{
    std :: cin >> T;
    while(T --)
    {
        std :: cin >> u >> v >> m;
        n = cnt = 0; M.clear();

        for(int i = 1; i <= u; ++ i)
        {
            std :: cin >> s;
            int tmp = M[s];
            if(! tmp) 
            {
                M[s] = ++ n;
                node[n].name = s, node[n].head = 0;
                node[n].voted = false, node[n].controled = true, node[n].conviced = true;
            }
            else
            {
                node[tmp].controled = true, node[tmp].conviced = true;
            }
        }
        for(int i = 1; i <= v; ++ i)
        {
            std :: cin >> s;
            int tmp = M[s];
            if(! tmp) 
            {
                M[s] = ++ n;
                node[n].name = s, node[n].head = 0;
                node[n].voted = true, node[n].controled = false, node[n].conviced = false;
            }
            else
            {
                node[tmp].voted = true;
            }
        }
        for(int i = 1; i <= m; ++ i)
        {
            std :: cin >> s;
            int tmp1 = M[s];
            if(! tmp1) 
            {
                tmp1 = M[s] = ++ n;
                node[n].name = s, node[n].head = 0;
                node[n].voted = false, node[n].controled = false, node[n].conviced = false;
            }
            std :: cin >> s;
            int tmp2 = M[s];
            if(! tmp2)
            {
                tmp2 = M[s] = ++ n;
                node[n].name = s, node[n].head = 0;
                node[n].voted = false, node[n].controled = false, node[n].conviced = false;

            }

            addEdge(tmp1, tmp2);
        }
        /*
        for(int i = 1; i <= cnt; ++ i)
        {
            std :: cout << node[edge[i].from].name << " -> " << node[edge[i].to].name << std :: endl;
        }
        */

        for(int i = 1; i <= u; ++ i)
        {
            solve(i);
            //std :: cout << std :: endl;
        }

        /*
        std :: cout << std :: endl;
        for(int i = 1; i <= n; ++ i)
        {
            std :: cout << i << " " << node[i].name << " ";
            if(node[i].voted) std :: cout << "voted ";
            if(node[i].controled) std :: cout << "controled ";
            if(node[i].conviced) std :: cout << "conviced";
            std :: cout << std :: endl;
        }

        std :: cout << std :: endl << "Ans : ";
        */
        int res = 0;
        for(int i = 1; i <= n; ++ i)
        {
            if(node[i].voted && node[i].conviced)
            {
                ++ res;
                std :: cout << (res == 1 ? "" : " ") << node[i].name;
            }
        }
        std :: cout << std :: endl;
    }
}
