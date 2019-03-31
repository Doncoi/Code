#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 105
#define abs(x) (x > 0 ? x : x * -1)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, cnt;
std :: string tmp;

struct Node {
	int sum; 
	std :: string s;
} node[MAXN];

inline bool cmp(Node x, Node y) {
	if(x.sum == y.sum) {
		if(x.s.length() == y.s.length()) 
			for(int i = 0; i < x.s.length(); ++ i)
				return x.s[i] < y.s[i];
		return x.s.length() < y.s.length();
	}
	return x.sum > y.sum;
}

void init() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> tmp;
		bool flag = true;
		for(int i = 1; i <= cnt; ++ i)
			if(node[i].s == tmp) {
				++ node[i].sum;
				flag = false;
			}
		if(flag) 
			node[++ cnt].s = tmp, node[cnt].sum = 1;
	}

	std :: sort(node + 1, node + cnt + 1, cmp);
}

void solve() {
	std :: cout << cnt << std :: endl;
	int pre = 1;
	while(pre <= cnt) {
		std :: cout << node[pre].sum << std :: endl;
		std :: cout << node[pre ++].s << std :: endl;
		while(node[pre].sum == node[pre - 1].sum)
			std :: cout << node[pre ++].s << std :: endl;
	}
}

int main() {
	init();
	solve();
}
