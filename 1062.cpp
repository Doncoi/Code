#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1005
#define MAXM 1000005
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, x, y, s, t;
int maxn, minn = INF, minn_2 = INF, tot = 0;
int a[MAXN][MAXN], d[MAXN][MAXN];
int b[MAXM], c[MAXM];

void find(int k) {
	b[++ t] = k;
	if(k == y) {
		if(s == d[x][y]) {
			std :: cout << d[x][y] << " ";
			for(int i = 1; i <= t; ++ i) {
				std :: cout << b[i] << " ";
			}
			std :: cout << std :: endl;
			if(tot == 3) exit(0);
		} else {
			minn = min(s, minn);
		}
		-- t; return;
	}

	for(int i = 1; i <= n; ++ i) {
		if(c[i] == 0 && a[k][i] && a[k][i] != maxn) {
			c[i] = 1, s += a[k][i];
			find(i);
			c[i] = 0, s -= a[k][i];
		}
	}
	-- t; return;
}

void find_1(int k) {
	b[++ t] = k;
	if(k == y) {
		if(s == minn) {
			std :: cout << minn << " ";
			for(int i = 1; i <= t; ++ i) 
				std :: cout << b[i] << " ";
			std :: cout << std :: endl;
			++ tot;
			if(tot == 3) exit(0);
		} else if(s != d[x][y])
			 minn_2 == min(s, minn_2); 
		-- t; return;
	}

	for(int i = 1; i <= n; ++ i) {
		if(c[i] == 0 && a[k][i] && a[k][i] != maxn) {
			c[i] = 1, s += a[k][i];
			find_1(i);
			c[i] = 0, s -= a[k][i];
		}
	}
	-- t; return;
}

void find_2(int k) {
	b[++ t] = k;
	if(k == y) {
		if(s == minn_2) {
			std :: cout << minn_2 << " ";
			for(int i = 1; i <= t; ++ i) 
				std :: cout << b[i] << " ";
			std :: cout << std :: endl;
		} 
		-- t; return;
	}

	for(int i = 1; i <= n; ++ i) {
		if(c[i] == 0 && a[k][i] && a[k][i] != maxn) {
			c[i] = 1, s += a[k][i];
			find_2(i);
			c[i] = 0, s -= a[k][i];
		}
		-- t; return;
	}
}

int main() {
	std :: cin >> n >> x >> y >> maxn;

	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j <= n; ++ j) {	
			std :: cin >> a[i][j];
			d[i][j] = a[i][j];
		} 

	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j <= n; ++ j) 
			for(int k = 1; k <= n; ++ k) 
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);


	b[++ t] = x, c[x] = 1; int k = n;
	for(int i = 1; i <= n; ++ i) {
		if(a[x][i] && a[k][i] != maxn) {
			s += a[x][i];
			find(i);
			s -= a[x][i];
		}
	}

	for(int i = 1; i <= n; ++ i) {
		if(a[x][i] && a[k][i] != maxn) {
			s += a[x][i];
			find_1(i);	
			s -= a[x][i];
		}
	}

	for(int i = 1; i <= n; ++ i) {
		if(a[x][i] && a[k][i] != maxn) {
			s += a[x][i];
			find_2(i);
			s -= a[x][i];
		}
	}

	return 0;
}

