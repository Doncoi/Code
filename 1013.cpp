#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

std :: string x, y;

inline void write(int p, int q, int m, int n) {
	if(p > q) return;
	if(p == q) {std :: cout << x[p]; return;}

	int k = x.find(y[n]);
	std :: cout << y[n];
	write(p, k - 1, m, m + k - p - 1);
	write(k + 1, q, m + k - p, n - 1);
}

void init() {
	std :: cin >> x >> y;
}

void solve (){
	int k = x.length();
	write(0, k - 1, 0, k - 1);
}

int main() {
	init();
	solve();
}
