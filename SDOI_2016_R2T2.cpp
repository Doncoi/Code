#include <cstdio>
#include <cstring>
#include <cstring>
#include <algorithm>
#define MAXN 1000000
#define MAXP 1000000007ll

int n, m;
long long fac[MAXN + 5], inv[MAXN + 5], f[MAXN + 5];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

inline long long calc(int x, int y) {
	return (((fac[x] * inv[y]) % MAXP) * inv[x - y]) % MAXP;
}

inline long long quickPower(long long x, long long y) {
	long long z = 1; while(y) {
		if(y & 1) z = (z * x) % MAXP; 
		x = (x * x) % MAXP; y >>= 1;
	} return z;
}

inline void init() {	
	fac[0] = 1ll, f[1] = 0, f[2] = 1;
	for(int i = 1; i < MAXN; ++ i) fac[i] = fac[i - 1] * (long long) i % MAXP;
	inv[MAXN] = quickPower(fac[MAXN], MAXP - 2);
	for(int i = MAXN - 1; i >= 0; -- i) inv[i] = inv[i + 1] * (long long)(i + 1) % MAXP;
	for(int i = 3; i <= MAXN; ++ i) f[i] = (long long)(i - 1) * (f[i - 1] + f[i - 2]) % MAXP;
}

inline void solve() {
	int T = read(); while(T --) {
		n = read(), m = read();
		printf("%I64d\n", calc(n, m) * f[n - m] % MAXP);
	}
}

int main() { init(); solve(); }
