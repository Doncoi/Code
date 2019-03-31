#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;

int read()

{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) 
        {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) 
        {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int n, m, fa[N], lc[N], rc[N], rev[N], que[N], len, sze[N], val[N];
int which(int x) 
{return rc[fa[x]] == x;}

bool is_root(int x) 
{
    return !fa[x] || (lc[fa[x]] != x && rc[fa[x]] != x);
}

void down(int x) 
{
    if (rev[x]) 
    {
        swap(lc[x], rc[x]);
        if (lc[x]) rev[lc[x]] ^= 1;
        if (rc[x]) rev[rc[x]] ^= 1;
        rev[x] = 0;
    }
}

void upt(int x) 
{
    sze[x] = 1;
    if (lc[x]) sze[x] += sze[lc[x]];
    if (rc[x]) sze[x] += sze[rc[x]];
}

void rotate(int x) 
{
    int y = fa[x], z = fa[y], b = lc[y] == x ? rc[x] : lc[x];
    if (z && !is_root(y)) (lc[z] == y ? lc[z] : rc[z]) = x;
    fa[x] = z; fa[y] = x; b ? fa[b] = y : 0;
    if (x == lc[y]) rc[x] = y, lc[y] = b;
    else lc[x] = y, rc[y] = b; upt(y); upt(x);
}

void splay(int x) 
{
    int i, y; que[len = 1] = x;
    for (y = x; !is_root(y); y = fa[y]) que[++len] = fa[y];
    for (i = len; i >= 1; i--) down(que[i]);
    while (!is_root(x)) 
    {
        if (!is_root(fa[x])) 
        {
            if (which(x) == which(fa[x])) rotate(fa[x]);
            else rotate(x);
        }
        rotate(x);
    }
    upt(x);
}

void Access(int x) 
{
    int y;
    for (y = 0; x; y = x, x = fa[x]) 
    {
        splay(x); rc[x] = y;
        if (y) fa[y] = x; upt(x);
    }
}
int Find_Root(int x) 
{
    Access(x); splay(x);
    while (down(x), lc[x]) x = lc[x];
    splay(x); return x;
}

void Make_Root(int x) 
{
    Access(x); splay(x);
    rev[x] ^= 1;
}

void Link(int x, int y) 
{
    Make_Root(x); fa[x] = y;
}

void Cut(int x, int y) 
{
    Make_Root(x); Access(y); splay(y);
    lc[y] = 0; fa[x] = 0; upt(y);
}

int Select(int x, int y) 
{
    Make_Root(x); Access(y); splay(y);
    return sze[y];
}

int main() 
{
    int i, x, y, z; n = read();
    for (i = 1; i <= n + 1; i++) sze[i] = 1;
    for (i = 1; i <= n; i++) 
    {
        x = val[i] = read();
        if (i + x <= n) Link(i, i + x);
        else Link(i, n + 1);
    }
    m = read(); while (m--) 
    {
        x = read();
        if (x == 2) 
        {
            y = read() + 1; z = read();
            Cut(y, y + val[y] <= n ? y + val[y] : n + 1);
            Link(y, y + z <= n ? y + z : n + 1);
            val[y] = z;
        }
        else 
        {
            y = read() + 1;
            printf("%d\n", Select(y, n + 1) - 1);
        }
    }
    return 0;
}
