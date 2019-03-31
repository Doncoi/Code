#include <cstdio>
#include <algorithm>
#define EPS 1e-6
#define MAXN 1005

int n, k;
double a[MAXN], b[MAXN], ans[MAXN];

int main() {
	while(scanf("%d%d", &n, &k) && (n + k)) {
		for(int i = 1; i <= n; ++ i) scanf("%lf", &a[i]);
		for(int i = 1; i <= n; ++ i) scanf("%lf", &b[i]);

		double L = 0.0, R = 1.0;
		while(L < R - EPS) {
			double mid = (L + R) / 2.0;
			for(int i = 1; i <= n; ++ i)  
				ans[i] = a[i] - b[i] * mid;
			std :: sort(ans + 1, ans + n + 1);
			double total = 0.0;
			for(int i = k + 1; i <= n; ++ i)
				total += ans[i];
			if(total >= 0.0) L = mid;
			else R = mid;
		}

		printf("%d\n", (int)(L * 100 + 0.5));
	}	

	return 0;
}
