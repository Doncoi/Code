//link.cpp By Doncoi
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXSIZE 300010
#define MODN 10007

int f[MAXSIZE], t[MAXSIZE];
int value[MAXSIZE];
int sum[MAXSIZE], maxn[MAXSIZE];

int main() {
	freopen("link.in", "r", stdin);
	freopen("link.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n - 1; i++) 
        scanf("%d %d", &f[i], &t[i]);

    for(int i = 1;i <= n;i ++) scanf("%d", &value[i]);

    int maxuw = 0, ans = 0;
    for(int i = 1;i <= n - 1;i ++) {
        maxuw = std :: max(maxuw, std :: max(value[f[i]] * maxn[t[i]],  value[t[i]] * maxn[f[i]]));
        ans = (ans % MODN + ((value[f[i]] % MODN) * (sum[t[i]] % MODN)) % MODN + ((value[t[i]] % MODN) * (sum[f[i]] % MODN)) % MODN) % MODN;
        sum[f[i]] += value[t[i]];
        sum[t[i]] += value[f[i]];
        maxn[f[i]] = std :: max(maxn[f[i]], value[t[i]]);
        maxn[t[i]] = std :: max(maxn[t[i]], value[f[i]]);
    }

    printf("%d %d", maxuw, (ans * 2) % MODN);
    fclose(stdin);
    fclose(stdout);
}