#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#define MAXN 1005
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, k, s, x, u[MAXN], f[MAXN];
float t;

struct Node {
	int a, b, c;
} q[MAXN];

inline bool cmp(Node x, Node y) {
	return x.c < y.c;
}

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	n = read(), k = read(), scanf("%f", &t);
	x = floor(t * 10);

	for(int i = 1; i <= n; ++ i) {
		scanf("%f", &t);
		q[i].a = floor(t * 10);
	}
	for(int i = 1; i <= n; ++ i)
		q[i].b = read();
	for(int i = 1; i <= n; ++ i)
		q[i].c = read();
	for(int i = 1; i <= k; ++ i)
		u[i] = read();
}

void solve() {
	int t = n;
	std :: sort(q + 1, q + n + 1, cmp);
	for(int i = 1; i <= n; ++ i)
		if(q[i].c == q[i + 1].c) 
			q[i].a = q[i].b = q[i].c = 0;
	std :: sort(q + 1, q + n + 1, cmp);

	for(int i = 1; i <= k; ++ i)
		for(int j = 1; j <= n; ++ j)
			if(q[j].c == u[i]) {
				x -=  q[j].a, s += q[j].b;
				q[j].a = q[j].b = q[j].c = 0;
				break;
 			}
 			
 	std :: sort(q + 1, q + n + 1, cmp);
 	for(int i = 1; i <= n; ++ i)
 		if(q[i].a != 0) ++ t;
 		else break;
 	std :: sort(q + 1, q + t + 1, cmp);
 	for(int i = 1; i <= t; ++ i) 
 		for(int j = x; j >= q[i].a; -- j)
 			f[j] = max(f[j], f[j - q[i].a] + q[i].b);

 	printf("%d", s + f[x]);
}

int main() {
	init();
	solve();
}
