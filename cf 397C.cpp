#include <cstdio>

int n, m, k;

int main() {
	scanf("%d %d %d", &k, &n, &m);
	if(n < k && m < k) {
		printf("-1\n");
		return 0;
	} else {
		int a = n / k, b = m / k;
		n = n % k, m = m % k;
		int ans = a + b;
		if((a == 0 && m) || (b == 0 && n)) {
			printf("-1\n");
			return 0;
		}
		printf("%d\n", ans);                                    
	}
	return 0;
}
