#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 19930726
#define MAXN 1000000 + 5

using namespace std;

string s, S;
int n, id = -1, mx = -1;
int p[MAXN], vis[MAXN], t[MAXN];
long long k, ans = 1;

long long quick_pow(long long x, long long n, int mod)
{
    long long ans = 1;
    while(n)
    {
        if(n & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}

long long min(long long a,int b)
{
    return a < b ? a : b;
}

int main()
{
    cin >> n >> k >> s;
    //不再插入无关字符
    S = '$' + s;
    //manachar
    for(int i = 1; i <= n; ++ i)
    {
        p[i] = i < mx ? min(p[(id << 1) - i], mx - i) : 1;
        while(S[i + p[i]] == S[i - p[i]])
            p[i] ++;
        if(i + p[i] - 1 > mx)
            id = i, mx = i + p[i] - 1;
        //桶排序计数
        t[(p[i] - 1) << 1 | 1] ++;
    }

    int cnt = 0;
    //按群体大小降序排序，不计算偶数长度的回文串
    for(int i = (n & 1 ? n : n - 1); i >= 1; i -= 2)
    {
        cnt += t[i];
        if(cnt > k)
        {
            ans = ans * quick_pow(i, k, MOD) % MOD;
            break;
        }
        else
        {
            ans = ans * quick_pow(i, cnt, MOD) % MOD;
            k -= cnt;
        }
    }

    k > cnt ? cout << "-1" : cout << ans;
}
