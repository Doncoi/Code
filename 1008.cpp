#include <cmath> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 25
#define INF 0x7fffffff
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, k, ans, e;
int a[MAXN];
bool vis[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline bool prime(int x) {
	for(int i = 2; i <= trunc(std :: sqrt(x)); ++ i) 
		if(!(x % i)) return false;
	return true;
}

void DFS(int dep, int pre, int last) {
	if(dep == k) {
		if(prime(pre)) ++ ans;
		return;
	}

	for(int i = last; i <= n; ++ i) 
		if(!vis[i]) {
			++ dep, pre += a[i], vis[i] = true;
			DFS(dep, pre, i + 1);
			-- dep, pre -= a[i], vis[i] = false;
 		}
}

void init() {
	n = read(), k = read();
	for(int i = 1; i <= n; ++ i)
		a[i] = read();
}

void solve() {
	DFS(0, 0, 1);
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
}
