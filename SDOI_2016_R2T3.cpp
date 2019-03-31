#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 3005
#define INF 1000000000

int n, m, q[MAXN], ql, qr;
long long sum[MAXN], a[MAXN], b[MAXN], *f = a, *g = b;

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

inline double slop(int x, int y) {
	return (double)(g[x] - g[y] + sum[x] * sum[x] - sum[y] * sum[y]) / (sum[x] - sum[y]);
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i) 
		sum[i] = read() + sum[i - 1],
		f[i] = sum[i] * sum[i];

	for(int k = 1; k < m; ++ k) {
		std :: swap(f, g), q[ql = qr = 1] = 0;
		for(int i = 1; i <= n; ++ i) {
			while(ql < qr && slop(q[ql], q[ql + 1]) < 2 * sum[i]) ++ ql;
			f[i] = g[q[ql]] + (sum[i] - sum[q[ql]]) * (sum[i] - sum[q[ql]]);
			while(ql < qr && slop(q[qr], q[qr - 1]) > slop(q[qr], i)) -- qr;
			q[++ qr] = i;
		}
	}

	printf("%I64d\n", (long long)(m * f[n] - sum[n] * sum[n]));
}
