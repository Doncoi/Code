#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 1000100

int phi[MAXN], p[MAXN / 10], num, T, n;
long long ans[MAXN];
bool judged[MAXN];

void init() {
	phi[1] = 1;
	for(int i = 2; i <= MAXN - 100; i ++) {
		if(!judged[i]) p[++ num] = i, phi[i] = i - 1;

		for(int j = 1; j <= num; j ++) {
			if(p[j] * i > MAXN - 100) break;
			judged[i * p[j]] = true;

			if(i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			} 
			phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}

	for(int i = 1; i <= MAXN - 100; ++ i) {
		for(int j = 1; j * i <= MAXN - 100; ++ j) {
			ans[i * j] += (long long) j * phi[j] / 2;
		}
	}
	for(int i = 1; i <= MAXN - 100; ++ i) {
		ans[i] = (long long) i * ans[i] + i;
	}
}

int main() {
	scanf("%d", &T);
	init();
	while(T --) {
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}

	return 0;
}
