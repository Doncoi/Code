//区间动态规划 
//f[i][j]表示从i到j的最大值，则：
//f[i][j] = max(f[i][k - 1] * f[k + 1][j] + a[k])，枚举k即可 
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define MAXN 35
#define INF 0x3f3f3f3f

int n;
int a[MAXN], root[MAXN][MAXN], f[MAXN][MAXN];

inline int read() {
	char ch = getchar(); int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

//前序遍历 
inline void front(int x, int y) {
	if(root[x][y]) printf("%d ", root[x][y]);
	if(root[x][root[x][y] - 1]) front(x, root[x][y] - 1);
	if(root[root[x][y] + 1][y]) front(root[x][y] + 1, y);
}

int main() {
	n = read();
	for(int i = 0; i <= n; ++ i)
		for(int j = 0; j <= n; ++ j) 
			f[i][j] = 1;
	for(int i = 1; i <= n; ++ i) 
		f[i][i] = a[i] = read(), root[i][i] = i;

	for(int len = 1; len <= n; ++ len) 
		for(int l = 1, r = l + len; r <= n; r = (++ l) + len) {
			int res = -INF;
			for(int i = l; i <= r; ++ i) {
				int tmp = f[l][i - 1] * f[i + 1][r] + a[i];
				res < tmp ? res = tmp, root[l][r] = i : 0;
			} 
			f[l][r] = res; 
		}

	printf("%d\n", f[1][n]);
	front(1, n); printf("\n");
}
