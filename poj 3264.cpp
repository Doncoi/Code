#include <cstdio>
#include <cstring>
#include <algorithm> 

const int N = 5e4 + 5;
const int LogN = 15;

int n, m, a[N], Log[N], minn[LogN + 1][N], maxn[LogN + 1][N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	Log[0] = -1;

	for(int i = 1; i <= n; ++ i) {
		minn[0][i] = maxn[0][i] = a[i], Log[i] = Log[i >> 1] + 1;
	} 

	for(int j = 1; j <= LogN; ++ j) {
		for(int i = 1;i + (1 << j) - 1 <= n; ++ i) {
			minn[j][i] = std :: min(minn[j - 1][i], minn[j - 1][i + (1 << j - 1)]);
			maxn[j][i] = std :: max(maxn[j - 1][i], maxn[j - 1][i + (1 << j - 1)]);
		} 
	}

	for(int i = 1; i <= m; ++ i) {
		int l, r;
		scanf("%d %d", &l, &r);
		int k = Log[r - l + 1];
		printf("%d\n", std :: max(maxn[k][l], maxn[k][r - (1 << k) + 1]) - std :: min(minn[k][l], minn[k][r - (1 << k) + 1]));
	}
	
	return 0;
} 
