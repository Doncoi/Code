#include <cmath> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream> 
#define MAXN 1005
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

char tmp[MAXN];
int edge[MAXN][MAXN], cou[MAXN], n, k, big[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	std :: cin >> tmp >> k;
	n = std :: strlen(tmp);
	for(int i = 0; i <= 9; ++ i) 
		for(int j = 0; j <= 9; ++ j) 
			if(i == j) edge[i][j] = 1;
			else edge[i][j] = 0;

	for(int i = 0; i < k; ++ i) {
		int u = read(), v = read();
		edge[u][v] = 1;
	}
	big[0] = 1;
}

void solve() {
	for(int k = 0; k <= 9; ++ k) 
		for(int i = 0; i <= 9; ++ i) 
			if(i != k) 
				for(int j = 0; j <= 9; ++ j) 
					if(j != i && j != k && (edge[i][k] && edge[k][j]))
						edge[i][j] = 1;

	for(int i = 0; i <= 9; ++ i)
		for(int j = 0; j <= 9; ++ j) 
			cou[i] += edge[i][j];

	int ans = 1, a, b = 0;
	for(int i = 0; i < n; ++ i) 
		if(cou[tmp[i] - 48]) {
			a = cou[tmp[i] - 48];
			for(int j = b; j >= 0; -- j) {
				big[j] *= a;
				if(big[j] > 9) {
					big[j + 1] += big[j] / 10;
					big[j] = big[j] % 10;
					if(j == b) ++ b;
				}
			}
		}

	for(int j = 0 ; j <= b; ++ j) 
		if(big[j] > 9) {
			big[j + 1] += big[j] / 10;
			big[j] = big[j] % 10;
			if(j == b) ++ b;
		}

	for(int r = b; r >= 0; -- r) 
		std :: cout << big[r];
}

int main() {
	init();
	solve();
}
