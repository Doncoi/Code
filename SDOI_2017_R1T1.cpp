#include <cmath>
#include <cstdio>
#include <algorithm>
#define min(a, b) (a < b ? a : b)
#define swap(a, b) std :: swap(a, b);
#define MAXN 15000005
#define MOD 1000000007

int n, m, cnt, last;
long long ans = 1;
int mu[MAXN], inv[MAXN], prime[MAXN], g[MAXN];
bool notPrime[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void lineShaker() {
	mu[1] = 1;
	for(int i = 2; i <= n; ++ i) {
		if(!notPrime[i]) 
			prime[++ cnt] = i, mu[i] = 1;

		for(int j = 1; (j <= cnt) && (i * prime[j] <= n); ++ j) {
			notPrime[i * prime[j]] = 1;
			if(!(i % prime[j])) {
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		} 
	}

	inv[1] = 1;
	for(int i = 2; i <= n; ++ i) 
		inv[i] = ( -((long long) MOD / i * inv[MOD % i] % MOD) + MOD ) % MOD;
}

long long quickPower(long long a, long long b) {
	long long res = 1;
	while(b) {
		if(b & 1) res = res * a % MOD;
		a = a * a % MOD, b >>= 1;
	}
	return res;
}

int main() {
	n = read(), m = read();
	if(n > m) swap(n, m);
	lineShaker();
	for(int i = 1; i <= n; ++ i) g[i] = 1;
	for(int i = 1; i <= cnt; ++ i) {
		int pre = prime[i];
		for(long long j = pre; j <= n; j = j * pre) 
			g[j] = pre; 
	}

	g[0] = 1;
	for(int i = 1; i <= n; ++ i) 
		g[i] = (long long) g[i] * g[i - 1] % MOD;
	for(int i = 1; i <= n; i = last + 1) {
		last = min(n / (n / i), m / (m / i));
		ans = ans * quickPower((long long)g[last] * quickPower(g[i - 1], MOD - 2) % MOD, 
			            (long long)((long long)n / i) * ((long long)m / i)) % MOD;
	}

	printf("%lld\n", ans);
}
