#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 13 

int n, m;
double c[MAXN][MAXN], f[MAXN][MAXN], ans[MAXN];

inline void Gauss() {
	for(int i = 1; i <= n; ++ i) {
		int idx = i;
		for(int j = i + 1; j <= n; ++ j) 
			if(fabs(f[idx][i]) < fabs(f[j][i])) idx = j;
		if(idx != i) 
			for(int j = i; j <= m; ++ j) 
				std :: swap(f[idx][j], f[i][j]);

		for(int j = i + 1; j <= n; ++ j) {
			double tmp = f[j][i] / f[i][i];
			for(int k = i; k <= m; ++ k) 
				f[j][k] -= f[i][k] * tmp;
		}
	}

	for(int i = n; i >= 1; -- i) {
		double tmp = f[i][m];
		for(int j = n; j > i; -- j) 
			tmp -= ans[j] * f[i][j];
		ans[i] = tmp / f[i][i]; 
	}

	return;
}

int main() {
	scanf("%d", &n); m = n + 1;
	for(int i = 0; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			scanf("%lf", &c[i][j]);

	for(int i = 0; i <= n; ++ i) {
		int j = i - 1;
		double d = 0;
		for(int k = 1; k <= n; ++ k) {
			f[i][k] = (c[i][k] - c[j][k]) * 2;
			d += c[i][k] * c[i][k] - c[j][k] * c[j][k];
		}

		f[i][m] = d;
	}

	Gauss();
	for(int i = 1; i <= n; ++ i) {
		if(i < n) printf("%.3lf ", ans[i]);
		else printf("%.3lf\n", ans[i]);
	}

	return 0;
}
