#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105

int n, m, k, stay[MAXN], cnt[MAXN];
long long ans, f[MAXN / 10][MAXN][MAXN];
bool map[MAXN][MAXN];

void DFS(int p, int put, int num) {
	stay[++ m] = num;
	cnt[m] = p;
	if(p >= k || p >= (n + 1) / 2) return;
	for(int i = put + 2; i <= n; ++ i) 
		DFS(p + 1, i, num + (1 << (i - 1)));
}

int main() {
	scanf("%d%d", &n, &k);
	m = 0;
	DFS(0, -1, 0);

	for(int i = 1; i <= m; ++ i) 
		for(int j = 1; j <= m; ++ j) 
			map[i][j] = map[j][i] = ( (stay[i] & stay[j]) || 
				                      ((stay[i] << 1) & stay[j]) || 
				                      ((stay[i] >> 1) & stay[j]) 
				                     ) ? 0 : 1;
 	for(int i = 1; i <= m; ++ i) 
 		f[1][cnt[i]][i] = 1ll;
 	for(int i = 2; i <= n; ++ i) 
 		for(int j = 0; j <= k; ++ j) 
 			for(int now = 1; now <= m; ++ now) {
 				if(cnt[now] > j) continue;
 				for(int l = 1; l <= m; ++ l) 
 					if(map[now][l] && cnt[l] + cnt[now] <= j)
 						f[i][j][now] += f[i - 1][j - cnt[now]][l];
 			}

	ans = 0;
	for(int i = 1; i <= m; ++ i) 
		ans += f[n][k][i];
	printf("%lld\n", ans);
	return 0;
}
