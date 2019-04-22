#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 20 + 5

int T, n, m;

struct point
{
    int x, y;
    point() {}

    point(int _x, int _y) : x(_x), y(_y) {}

    friend inline point operator-(const point &lhs, const point &rhs)
    {
        return point(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    friend inline int operator*(const point &lhs, const point &rhs)
    {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    inline int norm() const
    {
        return x * x + y * y;
    }
} p[MAXN], q[MAXN];

int read()
{
    char ch = getchar();
    int res = 0, flag = 1;
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            flag = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return (res * flag);
}

inline bool cmp(int u, int v)
{
    int det = (p[u] - p[1]) * (p[v] - p[1]);
    if (det)
    {
        return det > 0;
    }

    return (p[u] - p[1]).norm() < (p[v] - p[1]).norm();
}

void Graham()
{
    int id = 1; //寻找位于最左下角的极点
    for (int i = 2; i <= n; ++i)
    {
        if (p[i].x < p[id].x || (p[i].x == p[id].x && p[i].y < p[id].y))
        {
            id = i;
        }
    }
    if (id != 1)
    {
        std ::swap(p[1], p[id]);
    }

    static int pre[MAXN]; //使用辅助数组储存点的下标并排序
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = i;
    }
    std ::sort(pre + 2, pre + n + 1, cmp); //第一位为我们找到的极点，不参与排序

    q[++m] = p[1];
    for (int i = 2; i <= n; ++i)
    {
        int j = pre[i];
        while (m >= 2 && (p[j] - q[m - 1]) * (q[m] - q[m - 1]) >= 0)
        {        //判断拐向
            --m; //若发生拐向，则出现了凹边，是当前点出队
        }

        q[++m] = p[j];
    }
}

int main()
{
    T = read();
    while (T--)
    {
        n = read(), m = 0;
        for (int i = 1; i <= n; ++i)
        {
            p[i].x = read(), p[i].y = read();
        }
        Graham();
        std ::cout << m << std ::endl;
        for (int i = 1; i <= m; ++i)
        {
            std ::cout << q[i].x << " " << q[i].y << std ::endl;
        }
    }
}