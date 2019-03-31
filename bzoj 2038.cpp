#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 50005

int n, m, block[MAXN], c[MAXN];
long long s[MAXN], ans;

struct Query {
	int l, r, id;
	long long a, b; 
} a[MAXN];

bool cmp(const Query &a, const Query &b) {
	if(block[a.l] == block[b.l]) return a.r < b.r;
	return a.l < b.l;
}

bool cmp_id(const Query &a, const Query &b) {
	return a.id < b.id;
}

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

void init() {
	scanf("%d %d", &n, &m);
	int size = int(std :: sqrt(n));
	for(int i = 1; i <= n; ++ i) {
		block[i] = (i - 1) / size + 1;
	    scanf("%d", &c[i]);
	}
	  
	for(int i = 1; i <= m; i ++) {
	    scanf("%d %d", &a[i].l, &a[i].r);
	    a[i].id = i;
    }
}

void update(int p, int add) {
	ans -= s[c[p]] * s[c[p]];
	s[c[p]] += add;
	ans += s[c[p]] * s[c[p]];
}

void solve() {
	for(int i = 1, l = 1, r = 0; i <= m; ++ i) {
		for( ; r < a[i].r; ++ r)
			update(r+1,1);
		for( ; r > a[i].r; -- r)
		    update(r,-1);
		for( ; l < a[i].l; ++ l)
		    update(l,-1);
		for( ; l > a[i].l; -- l)
		    update(l-1,1);
		if(a[i].l == a[i].r) {
			a[i].a = 0; a[i].b = 1;
			continue;
		}

		a[i].a = ans - (a[i].r - a[i].l + 1);
		a[i].b = (long long)(a[i].r - a[i].l + 1) * (a[i].r - a[i].l);
		long long k = gcd(a[i].a, a[i].b);
		a[i].a /= k, a[i].b /= k;
	}
}

int main() {
	init();
	std :: sort(a + 1, a + m + 1, cmp);
	solve();
	std :: sort(a + 1, a + m + 1, cmp_id);

	for(int i = 1; i <= m; i++)
	    printf("%lld/%lld\n", a[i].a, a[i].b);
	return 0;
}
