#include <bits/stdc++.h>
const int max_tot = 300000 + 10;

struct tree {
    int dy, c[3];
} t[max_tot];

int now, t_num;
int a[max_tot], next[max_tot], last[max_tot], num[max_tot];
long long cnt[max_tot], ans[max_tot];

void go(int &k, int &x) {
    if (!x) x = ++t_num;
    k = x;
}

int main() {
    int n,m;

    
    scanf("%d%d", &n, &m);
    int i, j, k;
    char c;
    for (i = 1; i <= n; ) {
        scanf("%c", &c);    c -= 'x';
        while ( c < 0 || c > 2 ) { scanf("%c", &c);  c -= 'x';}
        a[++ now] = c;
        go(k, t[0].c[c]);
        for (j = 2; j <= m; ++ j) {
          scanf("%c", &c);  c -= 'x';
          a[++ now] = c;
          go(k, t[k].c[c]);
        }
        if (!t[k].dy) {t[k].dy = i; cnt[i] = 1; ++i; }
        else {
          ++ cnt[t[k].dy];
          now -= m;  -- n;
        }
    }
    for (i = 1; i <= n; ++ i) ans[m] += cnt[i] * (cnt[i] - 1) >> 1;
        now = 0;
        for (i=1;i<=n;++i) {
            for (j=1;j<i;++j) num[j]=0;
                for (j=1;j<=m;++j) {
            		++now;
             	    for (k = next[now] = last[a[now] * m + j]; k; k = next[k])
               			++ num[ (k - 1) / m + 1 ];
                    last[a[now] * m + j] = now;
                }
            for (j = 1;j < i;++ j) ans[num[j]] += cnt[j] * cnt[i];
        }
    for (i = 0; i <= m; ++ i) printf("%lld\n", ans[i]);
}         