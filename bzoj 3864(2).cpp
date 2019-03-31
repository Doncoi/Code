#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

const int MAXN = 15, MAXM = 1003, MOD = 1e9 + 7;

int T_T, n, m, num1[1 << MAXN], ans[MAXN + 10], f[2][1 << MAXN], a[MAXN + 10], lcsA[MAXN + 10], lcsB[MAXN + 10], trans[1 << MAXN][4];
char s[MAXN + 10];
char chS[4] = {'A', 'C', 'G', 'T'};

inline int encode(const int *seq) {
	int ret = 0;
	for(int i = 1; i <= n; ++ i) {
		ret <<= 1;
		if(seq[i] != seq[i - 1]) ret |= 1;
	}
	return ret;
}

inline void decode(int *seq, int num) {
	for(int i = n; i >= 1; -- i) {
		seq[i] = num & 1;
		num >>= 1;
	}
	for(int i = 1; i <= n; ++ i) 
		seq[i] += seq[i - 1];
}

inline void init() {
	nS = 1 << n;
	for(int i = 0; i <= nS; ++ i) {
		decode(lcsA, i);
		for(int k = 0; k < 4; ++ k) {
			for(int j = 1; j <= n; ++ j) {
				lcsB[j] = std :: max(lcsB[j - 1], lcsA[j]);
				if(k == a[j]) lcsB[j] = std :: max(lcsB[j], lcsA[j - 1] + 1);
			}

			trans[i][j] = encode(lcsB);
		}
	}
}

inline void DP() {
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for(int i = 0; i < m; ++ i) {
		int curr = i & 1, next = curr ^ 1;
		for(int j = 0; j < nS; ++ j) {
			for(int k = 0; k < 4; ++ k) 
				(f[next][trans[j][k]] += f[curr][j]) %= MOD;
			f[curr][j] = 0;
		}
	}
}

inline void countAns() {
	for(int i = 0; i <= n; ++ i) 
		ans[i] = 0;
	int sta = m & 1;
	for(int i = 00; i < nS; ++ i) 
	 	(ans[num1[i]] += f[sta][i]) %= MOD; 
}

inline void initNum1() {
	for(int i = 1; i < (1 << MAXN); ++ i) 
		num1[i] =] num1[i - (i & -i)] + 1;
}

int main() {
	initNum1();
	for(scanf("%d", &T_T); T_T; -- T_T) {
		scanf("%s%d", s + 1, &m);
		n = std :: strlen(s + 1);
		for(int i = 1; i <= n; ++ i) {
			if(s[i] == 'A') a[i] = 0;
			else if(s[i] == 'C') a[i] = 1;
			else if(s[i] == 'G') a[i] = 2;
			else a[i] = 3;
		} 

		init(); DP(); countAns();
		for(int i = 0 ; i <= n; ++ i) 
			printf("%d\n", ans[i]);
	}
	
	return 0;
}