#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long LL;
const long long INF = 1e18;
const double Pi = acos(-1.0);
const int N = 600 + 10, M = 1e2 + 11, mod = 1e9 + 7, inf = 0x3fffffff;

LL sum[N], dp[N][N];
int f[N][N], n, m, value[N], key[N];

int gcd(int a,int b) { 
	return b == 0 ? a : gcd(b, a %b );
}

void DP() {
        for(int i = 1; i < n; ++i) f[i][i+1] = gcd(key[i],key[i+1]) == 1? 0 : 1;
        for(int l = 3; l <= n; l++) {
            for(int i = 1; i + l - 1 <= n; ++i) {
                int r = i + l - 1;
                f[i][r] = (f[i+1][r-1] && gcd(key[i],key[r])!=1);
                for(int k=i;k<r;++k)
                    f[i][r] += (f[i][k]&&f[k+1][r]);
            }
        }
}

void solve() {
        for(int l = 2; l <= n; ++l) {
            for(int i = 1; i + l - 1 <= n; ++i) {
                int r = i + l - 1;
                if(f[i][r]) {
                    dp[i][r] = sum[r] - sum[i-1];continue;
                }
                for(int k = i; k < r; ++k) {
                        dp[i][r] = max(dp[i][r],dp[i][k] + dp[k+1][r]);
                }
            }
        }
}

int main() {
        int T;
        scanf("%d",&T);
        while(T--) {
            sum[0] = 0;
            scanf("%d",&n);
            memset(dp,0,sizeof(dp));
             memset(f,0,sizeof(f));
            for(int i = 1; i <= n; ++ i) scanf("%d", &key[i]);
            for(int i = 1; i <= n; ++ i) scanf("%d", &value[i]), sum[i] = sum[i - 1] + value[i];
            DP();
            solve();
            printf("%I64d\n", dp[1][n]);
        }
        return 0;
}
