#include <cstdio>
#include <cstring>
#define MAXN 1005

int T, n;
int ans[MAXN];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
	ans[1] = 3;
	for(int i = 2; i <= 1000; ++ i) {
		int cnt = 0;
		for(int j = 1; j <= i; j ++) {
			if(gcd(i, j) == 1) {
				cnt ++; 
			}
		}
		ans[i] = ans[i - 1] + cnt * 2; 
	}
}

int main() {
	scanf("%d", &T);
	memset(ans, 0, sizeof(ans));
	solve();

	for(int t = 1; t <= T; ++ t) {
		scanf("%d", &n);
		printf("%d %d %d\n", t, n, ans[n]);
	}
}
