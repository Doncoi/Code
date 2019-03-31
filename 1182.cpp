#include <cstdio>
#include <cstring>
#define MAXN 1000005

int n, m, cnt;
int a[MAXN], b[MAXN];

inline bool check(int x) {
	for(int i = 1; i < x; ++ i)
		if(a[i] == n && b[i] == m)
			return true;
	return false;
}

inline void solve(int x) {
	if(n == m) {cnt = x; return;}
	if(check(x)) {cnt = -1; return;}
	a[x] = n, b[x] = m;
	if(n > m) {n -= m, m <<= 1; solve(x + 1);}
	else if(n < m) {m -= n, n <<= 1; solve(x + 1);}
}

int main() {
	scanf("%d %d", &n, &m);
	if((n + m) & 1) printf("-1\n");
	else solve(1), printf("%d\n", cnt);
}
