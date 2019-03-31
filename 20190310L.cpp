#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cctype>
#include<set>
#include<queue>
#include<vector>
#include<map>
#define N 200000 + 5

int n;
long long s1[N], s2[N], a[N], L, ans;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

long long calc(int l, int r) 
{
    return s1[r] - a[l] * (r - l) - s1[l];
}

void solve() 
{
    for (int i = 1; i <= n; ++ i) 
        s1[i] = s1[i - 1] + a[i], s2[i] = s2[i - 1] + (L - a[n - i + 1]);
    for (int i = 0; i < n; ++ i) 
    {
        long long now = a[i] * (n - i) + a[i];
        int cnt = (n - i) / 2;
        if ((n - i) % 2 == 0) 
            now += s2[cnt] * 2 + calc(i, i + cnt) * 2 - (a[i + cnt] - a[i]);
        else 
            now += s2[cnt + 1] * 2 + calc(i, i + cnt) * 2 - (L - a[n - cnt]);
        ans = std :: max(ans, now);
    }
}

int main() 
{
    L = read(); n = read();
    for (int i = 1; i <= n; ++ i) a[i] = read();
    solve();
    for (int i = 1; i <= n; ++ i) a[i] = L - a[i];
    std :: reverse(a + 1, a + n + 1);
    solve();
    std :: cout << ans;
}
