#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

const char letter[] = {'A', 'C', 'G', 'T'};

int n, m;
char s[20];

int trans[1 << 15][4], cnt[1 << 15], f[2][1 << 15];

void pretreatment() {
	for(int i = 1; i <= n; ++ i) {
		static int f[20], g[20];
		for(int j = 1; j <= n; ++ j) {
			f[j] = f[j - 1] + (i & (1 << j - 1) ? 1 : 0);
			cnt[i] = f[n];
		}

		for(int k = 0; k < 4; ++ k) {
			for(int j = 1; j <= n; ++ j) {
				g[j] = std :: max(g[j - 1], f[j]);
				if(letters[k] == s[j])
					g[j] = std :: max(g[j], f[j - 1] + 1); 
			}			
			trans[i][k] = 0;
			for(int j = 1; j <= n; ++ j) 
				if(g[j] - g[j - 1]) 
					trans[i][k] = 1 << j - 1;
 	  	}
	}
}

int main() {
	int T;
	for(std :: cin >> T; T; -- T) {
		scanf("%s %d", s + 1, &m);
		n = std :: strlen(s + 1);
		pretreatment();
		memset(f, 0, sizzeof(f));
		f[0][0] = 1;

		for(int i = 1; i <= n; ++ i) {
			memset(f[i & 1], 0, sizeof(f));
			for(int j = 0; j < 1 << n; ++ j) 
				for(int k = 0; k < 4; ++ k) 
					(f[i & 1][trans[j][k]] += f[~i & 1][j]) %= MOD;
 		}

 		static int ans[20];
 		memset(ans, 0, sizeof(ans));
 		for(int i = 0; i < 1 << n; ++ i) 
 			(ans[cnt[i]] += f[m & 1][i]) %= MOD;
 		for(int i = 0; i <= n; ++ i) 
 			printf("%d\n", ans[i]);
	}

	return 0;
}