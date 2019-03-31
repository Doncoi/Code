#include <vector> 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 405
#define MAXM 
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

struct Node {
	int cnt, vis;
	std :: vector<int> son;
} node[MAXN];

int n, p;
int maxn = INF;

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '0') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void swap(int &a, int &b) {
	int tmp = a;
	a = b, b = tmp;
}

void DFS(int ans, int flag, int n) {
	if(ans >= maxn) return;
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		if(node[i].vis == flag) {
			for(int j = 0; j < node[i].son.size(); ++ j) {
				node[node[i].son[j]].vis = flag + 1, ++ cnt;
			}
		}
	}
	if(cnt == 0) {
		maxn = ans;  
		return;
	}
	for(int i = 1; i <= n; ++ i) {
		if(node[i].vis == flag + 1) {
			node[i].vis = -1;
			DFS(ans + cnt - 1, flag + 1, n);
			node[i].vis = flag + 1;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(node[i].vis == flag + 1) {
			node[i].vis = -1;
		}
	}
}

void init() {
	n = read(), p = read();
	for(int i = 1; i <= p; ++ i) {
		int a = read(), b = read();
		if(a > b) {
			swap(a, b);
		}
		node[a].son.push_back(b);
	}
}

void solve() {
	node[1].vis = 1;
	DFS(1, 1, n);
	printf("%d\n", maxn);
}

int main() {
	init();
	solve();
}
