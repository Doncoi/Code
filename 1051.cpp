#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100005
#define abs(x) (x > 0 ? x : x * -1)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

const int seed_1 = 123, seed_2 = 321;
const int mod_1 = 1000007, mod_2 = 1000007;

int n, ans;
int hash_1[mod_1 + 5], hash_2[mod_2 + 5];

struct Node {
	int len;
	std :: string s;
} node[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void hash(int key) {
	int len = node[key].s.length();
	int t = 1, tmp_1 = 0, tmp_2 = 0;
	for(int i = 0; i < len; ++ i) {
		tmp_1 = (tmp_1 * seed_1 + node[key].s[i] - 'a' + 1) % mod_1;
		tmp_2 = (tmp_2 * seed_2 + node[key].s[i] - 'a' + 1) % mod_2;

		if(i == len - 1) continue;
		t = max( min(hash_1[tmp_1], hash_2[tmp_2]) + 1, t);
	}

	hash_1[tmp_1] = max(hash_1[tmp_1], t);
	hash_2[tmp_2] = max(hash_2[tmp_2], t);
	ans = max(t, ans); 
}

void init() {
	n = read();
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> node[i].s, 
		node[i].len = node[i].s.length();
		hash(i);
	}
}

void solve() {
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
}
