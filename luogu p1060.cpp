//裸的01背包，用花费和重要程度的乘积表示价值即可
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 25 + 5
#define MAXM 30000 + 5
using namespace std;

int n, m;   //n是总物品个数，m是总钱数
int value[MAXN], cost[MAXN], f[MAXM];

void ZeroOnePack(int cost, int value) {  
    for(int i = m; i >= cost; i --)
        f[i] = max(f[i], f[i - cost] + value);
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> cost[i] >> value[i];
        value[i] *= cost[i];   //按照题意，用花费和重要程度的乘积表示价值
    }

    for(int i = 1; i <= n; ++ i)
    {
        ZeroOnePack(cost[i], value[i]);
    }

    cout << f[m] << endl;//背包大小为m时最大值
} 