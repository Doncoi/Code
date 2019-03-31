#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 20

const int dx[9] = {-2, -1, 1, 2, 2, 1, -1, -2, 0};
const int dy[9] = {-1, -2, -2, -1, 1, 2, 2, 1, 0};

int n, m, x, y;
int f[MAXN][MAXN];
bool reach[MAXN][MAXN];

int main() {
	std :: cin >> n >> m >> x >> y;
	memset(f, 0, sizeof(f));    memset(reach, true, sizeof(reach));    f[0][0] = 1;
	for(int i = 0;i <= 8;i ++) 
		reach[x + dx[i]][y + dy[i]] = false;
		
	for(int i = 1;i <= n;i ++) {
		if(reach[i][0]) f[i][0] = 1;
		else break;
	}
	 
	for(int i = 1;i <= m;i ++) {
		if(reach[0][i]) f[0][i] = 1;
		else break;
	}

	for(int i = 1;i <= n;i ++) 
		for(int j = 1;j <= m;j ++) 
			if(reach[i][j]) 
				f[i][j] = f[i - 1][j] + f[i][j - 1]; 
    
	printf("%d", f[n][m]);
}
