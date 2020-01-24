#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
#define N 10005
#define M 300005

int n, m; 
map<string, int> couple; // couple 

struct Edge 
{
    int v, nex;
} e[M];

int tot, h[N];

void addEdge(int u, int v) 
{
    e[++ tot].v = v;
    e[tot].nex = h[u], h[u] = tot;
}

inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
    while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
    return (res * flag);
}

int idx, cnt;
int dfn[N], low[N], color[N];
int s[N], top;
bool ins[N];

void Tarjan(int u) 
{
    dfn[u] = low[u] = ++ idx;
    s[++ top] = u, ins[u] = 1;
    for(int i = h[u]; i; i = e[i].nex) 
    {
        int v = e[i].v;
        if(! dfn[v]) 
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) 
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) 
    {
        ++ cnt;
        do{
            color[s[top]]=cnt;
            ins[s[top]]=0;
        }while(s[top--]!=u);
    }
}

int main()
{
    n = read();
    string gir, boy;
    for(int i = 1; i <= n; ++ i) 
    {
        cin >> gir >> boy;
        couple[gir] = i;
        couple[boy] = i + n;
        addEdge(i, i + n);
    }

    m = read();
    for(int i = 1; i <= m; ++ i) 
    {
        cin >> gir >> boy;
        addEdge(couple[boy], couple[gir]);
    }

    for(int i = 1; i <= n * 2; ++ i) 
        if(! dfn[i]) Tarjan(i);

    for(int i = 1; i <= n; ++ i) 
        if(color[i] == color[i + n]) cout << "Unsafe\n";
        else cout << "Safe\n";
}