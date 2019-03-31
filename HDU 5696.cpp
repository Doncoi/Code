#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

int n, A[MAXN];
long long tmp[MAXN], ans[MAXN];

void max(long long &a, long long &b) {
    a = std :: max(a, b);
}

void solve(int l, int r) {
	if(l > r) return;

	int mid = 0;
	for(int i = l; i <= r; ++ i) {
		if(!mid || A[i] < A[mid]) mid = i;
	}

	int w = r - l + 1;
	for(int i = 1; i <= w; ++ i) tmp[i] = 0;
	for(int i = l; i <= mid; ++ i) {
		long long rom = A[mid] * A[i]; 
		max(tmp[mid - i + 1], rom);
	}
	for(int i = mid; i <= r; ++ i) {
		long long rom = A[mid] * A[i];
		max(tmp[i - mid + 1], rom);
	}

	long long max_pre = 0;
	for(int i = 1; i <= w; ++ i) {
		max(max_pre, tmp[i]);
		max(ans[i], max_pre);
	}

	solve(l ,mid - 1);
	solve(mid + 1, r);
}

int main() {
	while(scanf("%d", &n)) {
		memset(ans, 0, sizeof(ans));

		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &A[i]);
		}

		solve(1, n);
		for(int i = 1; i <= n; ++ i) {
			printf("%I64d\n", ans[i]);
		}
	}

	return 0;
}
