#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int map[200][200];
int d, n;
int x, y, k;

int main() {
	freopen("wireless.in", "r", stdin);
	freopen("wireless.out", "w", stdout);

	scanf("%d %d", &d, &n);	
	memset(map, 0, sizeof(map));    int maxn = 0;
	while(n --) { 
		scanf("%d %d %d", &x, &y, &k);
		for(int i = x - d + 30;i <= x + d + 30;i ++)
			for(int j = y - d + 30;j <= y + d + 30;j ++) {
				map[i][j] += k;
				maxn = std :: max(maxn, map[i][j]);
			}
	}

	int ans = 0;
	for(int i = 1;i <= 199;i++)
		for(int j = 1;j <= 199;j ++) 
			if(map[i][j] == maxn) ans ++;

	printf("%d %d\n", ans, maxn);

	fclose(stdin);
	fclose(stdout);
}