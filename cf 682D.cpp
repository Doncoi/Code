#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f
#define MAXN 1005
#define MAXM 15

int n, m, k, ans;
int f[MAXN][MAXN], dp[MAXN][MAXN][MAXM];
char a[MAXN], b[MAXN];

inline int read() {
	char ch = getchar();    int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {res = res * 10 + ch - '0'; ch = getchar();}
	return res * flag;
}

inline void init() {
	n = read(), m = read(), k = read();
	ans = 0;
	memset(f, 0, sizeof(f));
	memset(dp, 0, sizeof(dp));
}

int main() {
	init();
	std :: cin >> a >> b;
	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j <= m; ++ j) 
			if(a[i - 1] == b[j - 1]) 
				f[i][j] = f[i - 1][j - 1] + 1;

	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			for(int l = 1; l <= k; ++ l) {
				dp[i][j][l] = std :: max(dp[i - 1][j][l], dp[i][j - 1][l]);
				if(f[i][j]) 
					dp[i][j][l] = std :: max(dp[i - f[i][j]][j - f[i][j]][l - 1] + f[i][j], dp[i][j][l]);
				ans = std :: max(dp[i][j][l], ans);
			}

	printf("%d\n", ans);
	return 0;
}
