#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000 + 5
#define MAXV 1250 + 5

using namespace std;

int n, T, k, ans;
int f[MAXV], v[MAXN], h[MAXN];

int main() {
    cin >> n >> T >> k;

    for (int i = 1; i <= n; ++ i) {
        cin >> v[i] >> h[i];
        //完全背包，要处理到所有奶酪都被压扁的情况
        for (int j = h[i]; j <= T * 5 / 4; j ++)
            f[j] = max(f[j], f[j - h[i]] + v[i]);
    }

    //枚举最顶端的奶酪
    ans = f[T];
    for (int i = 1; i <= n; ++ i)
        if (h[i] >= k)  //如果i是一块大奶酪
            ans = max(ans, f[(T - h[i]) * 5 / 4] + v[i]);
    //把i放在奶酪塔顶端，下面的奶酪高度全部减小
    //其他奶酪被压缩后，加上大奶酪总体积为T
    //这时减去大奶酪的体积，剩下的被压缩的奶酪应当为
    cout << ans << endl;
}
