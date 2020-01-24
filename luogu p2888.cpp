#include<cstdio>
#include<cstring>
#include<iostream>
#define INF 0x7f7f7f7f
#define MAXN 300 + 5

using namespace std;

int n, m, s, t, T;
int u, v, w;
int d[MAXN][MAXN];

int main()
{
    memset(d,INF,sizeof(d));
    cin >> n >> m >> T;

    for(int i = 1; i <= m; ++ i)
    {
        u = read(), v = read(), w = read();
        d[u][v] = w;    
    }

    for(int k = 1; k <= n; ++ k)
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= n; ++ j)
                d[i][j] = min(max(d[i][k], d[k][j]), d[i][j]);

    for(int i = 1; i <= T; ++ i)
    {
        cin >> u >> v;
        if(d[u][v] != INF)
            cout << d[u][v] << endl;
        else
            cout << "-1" << endl;
    }
}
