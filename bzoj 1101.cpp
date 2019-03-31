#include <cmath>
#include <cstdio>
#include <algorithm>
#define min(a, b) (a < b ? a : b)
#define MAXN 50000

int T, cnt;
int notPrime[MAXN + 5]; 
long long prime[MAXN + 5], mu[MAXN + 5];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void lineShaker() {
	mu[1] = 1;
	for(int i = 2; i <= MAXN; ++ i) {
		if(!notPrime[i]) mu[i] = -1, prime[++ cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= MAXN; ++ j) {
			notPrime[i * prime[j]] = true;
			if(!(i % prime[j])) {
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
	for(int  i = 1; i <= MAXN; ++ i) mu[i] = mu[i] + mu[i - 1];
}

long long calc(int n, int m, int k) {
	long long res = 0; int last;    n /= k, m /= k;
	for(int i = 1; i <= m && i <= n; i = last + 1) {
		last = min(n / (n / i), m / (m / i));
		res += (mu[last] - mu[i - 1]) * (m / i) * (n / i);
	}
	return res;
}

int main() {
	T = read(), cnt = 0;
	lineShaker();
	while(T --) {
		int n = read(), m = read(), k = read();
		printf("%lld\n", calc(n, m, k));
	}
}
