#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000000 + 5
#define MOD 998244353
#define INF 0x3f3f3f3f

long long n, a, b, k, cnt = 0, res = 0;
long long fac[MAXN], ans[MAXN][2];

long long inv(long long x)
{
    return x == 1 ? x : (MOD - MOD / x) * inv(MOD % x) % MOD;
}

long long calc(long long n, long long m)
{
    long long tmp = (fac[m] * fac[n - m]) % MOD;
    return (fac[n] * inv(tmp)) % MOD;
}

int main()
{
    std :: cin >> n >> a >> b >> k;
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 3e5 + 5; ++ i)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    for(long long i = 0; i <= n; ++ i)
    {
        if(k - (i * a) >= 0 && (k - a * i) % b == 0 && (k - a * i) / b <= n)
        {
            ans[cnt][0] = i;
            ans[cnt ++ ][1] = (k - a * i) / b;
        }
    }

    for(long long i = 0; i < cnt; ++ i)
    {
        res = (res + calc(n, ans[i][0]) * calc(n, ans[i][1]) % MOD) % MOD;
    }
    std :: cout << res << std :: endl;
}
