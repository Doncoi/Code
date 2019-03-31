#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10005

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

int n, m, cnt, ai, bi;
int a[MAXN][300], c[MAXN], r[MAXN];

int main() {
	n = read(), m = read();
	for(int i = 1; i <= m; ++ i) {
		ai = read(), bi = read();
		for(int j = 1; j <= c[ai]; ++ j)
			if(a[ai][j] == bi) continue;
		++ r[bi], ++ c[ai], a[ai][c[ai]] = bi;
	}

	for(cnt = 0; cnt < n; ) {
		int tmp = 0;
		for(int i = 1; i <= n; ++ i) 
			if(!r[i]) {
				++ cnt, ++ tmp, r[i] = MAXN;
				for(int j = 1; j <= c[i]; ++ j) 
					-- r[a[i][j]];
			}
		if(!tmp) {
			printf("T_T\n%d\n", n - cnt);
			return 0;
		}
	} 

	printf("o(?иж_?иж)o\n");
	return 0;
}
