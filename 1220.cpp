#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 105

int n;
int map[MAXN][MAXN];
int f[MAXN][MAXN];

int main() {
	scanf("%d", &n);
	memset(map, 0, sizeof(map));    memset(f, 0, sizeof(f));
	for(int i = 1;i <= n;i ++) 
		for(int j = 1;j <= i;j ++)
			scanf("%d", &map[i][j]);

	for(int i = n;i >= 1;i --) {
		for(int j = 1;j <= i;j ++) {
			f[i][j] = std :: max(f[i + 1][j],f[i + 1][j + 1]) + map[i][j];
 		}
	}

	printf("%d", f[1][1]);
}