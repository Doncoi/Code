#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1005
#define MAXM 
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

struct Node {
	int n[MAXN];
} a, b, c, one, two, ans;

int p;

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '0') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

Node mult(Node n1, Node n2) {
	Node tmp;
	memset(tmp.n, 0, sizeof(tmp.n));

	for(int i = 1; i <= 500; ++ i) {
		for(int j = 1; j <= 500; ++ j) {
			tmp.n[i + j - 1] += n1.n[i] * n2.n[j];
		}
	}
	for(int i = 1; i <= 500; ++ i) {
		tmp.n[i + 1] += tmp.n[i] / 10;
		tmp.n[i] %= 10;
	}

	return tmp;
}

Node quickPower(Node k, int p) {
	if(p == 1) return two;
	if(p == 0) return one;

	Node tmp = quickPower(k, p / 2);
	if(p % 2 == 0) {
		return mult(tmp, tmp);
	} else {
		return mult(mult(tmp, tmp), two);
	}
}

void init() {
	p = read();
	memset(one.n, 0, sizeof(one.n));
	memset(two.n, 0, sizeof(two.n));
	one.n[1] = 1, two.n[1] = 2;
}

void solve() {
	printf("%d\n", int(p * std :: log10(2) + 1));
	ans = quickPower(two, p);
	ans.n[1] -= 1;
	for(int i = 500; i >= 1; -- i) {
		printf("%d", ans.n[i]);
		if(i != 500 && !(i % 50 - 1)) {
			printf("\n");
		}
	}
}

int main() {
	init();
	solve();
}
