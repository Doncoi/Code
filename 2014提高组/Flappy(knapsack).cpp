#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10010
#define INF 1e9

using namespace std;

int n, m, k, p, ans;
int up[MAXN],down[MAXN];    //储存管道
int x[MAXN],y[MAXN];        //储存跳跃与下降
int f[MAXN][1010];          //动态规划数组

int main() {
    scanf("%d%d%d", &n, &m, &k);
    up[n] = m + 1;
    down[n] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        up[i] = m + 1;
        down[i] = 0;
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &p);
        scanf("%d%d", &down[p], &up[p]);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[i][j] = INF;
    f[0][0] = INF;

    for (int i = 1; i <= n; i++) {
        for (int j = x[i - 1];j <= m; j++) {
            f[i][j] = min(f[i][j], f[i - 1][j - x[i - 1]] + 1);  //由一次跳跃得到
            f[i][j] = min(f[i][j], f[i][j - x[i - 1]] + 1);
        }
        for (int j = m - x[i - 1]; j <= m; j++) {
            f[i][m] = min(f[i][m], f[i - 1][j] + 1);
            f[i][m] = min(f[i][m], f[i][j] + 1);     
        }
        for (int j = down[i] + 1; j <= up[i] - 1; j++)
            if (j + y[i - 1] <= m)
                f[i][j] = min(f[i][j], f[i - 1][j + y[i - 1]]);
        for (int j = 1; j <= down[i]; j++)
            f[i][j] = INF;
        for (int j = up[i]; j <= m; j++)
            f[i][j] = INF;
    }

    ans = INF;
    int cnt = k;
    for (int i = n; i >= 1; i--) {
        for (int j = down[i] + 1; j <= up[i] - 1; j++)
            ans = min(ans, f[i][j]);
            if (ans != INF)
                break;
                if (up[i] != m + 1)
                cnt--;
    }
    if (cnt == k) printf("1\n%d\n", ans);
    else printf("0\n%d\n", cnt);
}