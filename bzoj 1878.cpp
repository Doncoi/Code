#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 50005
#define MAXM 1000005
#define MAXQ 200005

int n, m, size, tot;
int a[MAXN], cnt[MAXM], ans[MAXQ];

struct Query {
	int l, r, belong, key;
} query[MAXQ];

inline bool cmp(const Query &a, const Query &b) {
	return a.belong < b.belong || a.belong == b.belong && a.r < b.r;
}

void init() {
	scanf("%d", &n), size = std :: sqrt(n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &m);
	for(int i = 1; i <= m; ++ i) {
		query[i].key = i;
		scanf("%d%d", &query[i].l, &query[i].r);
		query[i].belong = (query[i].l - 1) / size + 1;
	}
}

void solve() {
	std :: sort(query + 1, query + m + 1, cmp);
	int tl = 0, tr = 0;

	for(int i = 1; i <= m; ++ i) {
		int l = query[i].l, r = query[i].r;

		while(tl < l) {
			cnt[a[tl]] --;
			if(!cnt[a[tl]]) tot --;
			tl ++;
		}
		while(tl > l) {
			tl --;
			if(!(cnt[a[tl]])) tot ++;
			cnt[a[tl]] ++;
		}
		while(tr < r) {
			tr ++;
			if(!cnt[a[tr]]) tot ++;
			cnt[a[tr]] ++;
		}
		while(tr > r) {
			cnt[a[tr]] --;
			if(!cnt[a[tr]]) tot --;
			tr --;
		}

		ans[query[i].key] = tot;
	} 

	for(int i = 1; i <= m; ++ i) {
		printf("%d\n", ans[i]);
	}

	return;
}

int main() {
	init(), solve();
	return 0;
}
