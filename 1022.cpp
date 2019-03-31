#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5005
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b) 

const int qx[2] = {-1, 0}, qy[2] = {0, -1};

int n, m, k, id1 = 0, id2 = 0, match[MAXN], w[MAXN][MAXN];
bool a[MAXN][MAXN], map[MAXN][MAXN], used[MAXN];

inline int read() {
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

bool DFS(int x) {
	if(used[x]) return false;
	used[x] = true;
	for(int i = 1; i <= id2; ++ i)
		if(a[x][i])
			if(!match[i] || DFS(match[i])) {
				match[i] = x;
				return true;
			}

	return false;
}

void init() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= k; ++ i) 
		map[read()][read()] = true;	
	for(int i = 0; i <= n + 1; ++ i) 
		map[i][0] = map[i][m + 1] = true;
	for(int i = 0; i <= m + 1; ++ i) 
		map[0][i] = map[n + 1][i] = true;
}

void solve() {
	for(int i = 1; i <= n; ++ i) 
		for(int j = 1; j <= m; ++ j)
			if(!map[i][j]) {

				if((i + j) & 1) {
					w[i][j] = ++ id1;
					for(int l = 0; l < 2; ++ l) 
						if(!map[ i + qx[l] ][ j + qy[l] ])
							a[ id1 ][ w[ i + qx[l] ][ j + qy[l] ] ] = true;
				} else {
					w[i][j] = ++ id2;
					for(int l = 0; l < 2; ++ l) 
						if(!map[ i + qx[l] ][ j + qy[l] ])
							a[ w[ i + qx[l] ][ j + qy[l] ] ][ id2 ] = true;
				}
			}

	int ans = 0;
	for(int i = 1; i <= id1; ++ i) {
		memset(used, false, sizeof(used));
		if(DFS(i)) ++ ans;
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
}
