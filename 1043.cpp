#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 15
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, x, y, z;
int map[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

void init() {
	n = read();
	memset(map, 0, sizeof(map));
	while(scanf("%d%d%d", &x, &y, &z) && (x | y | z)) 
		map[x][y] = z;
}

void solve() {
	int x1, y1, x2, y2;
	for (x1 = 1; x1 <= n; x1++) {  
        for (y1 = 1; y1 <= n; y1++) {  
            for (x2 = 1; x2 <= n; x2++) {  
                if (x1 + y1 - x2 > 0) {  
                    y2 = x1 + y1 - x2;  
                } else {
                	continue;  
                }
                f[x1][y1][x2][y2] = max(f[x1 - 1][y1][x2 - 1][y2], f[x1][y1 - 1][x2 - 1][y2]);
                f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], f[x1][y1 - 1][x2][y2 - 1]);  
                f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], f[x1 - 1][y1][x2][y2 - 1]);  
                f[x1][y1][x2][y2]  += (map[x1][y1] + map[x2][y2]);  
                if (x1 == x2 && y1 == y2)
                    f[x1][y1][x2][y2] -= map[x1][y1];  
            }  
        }  
    }  
    
    printf("%d", f[n][n][n][n]);  
}

int main() {
	init();
	solve();
}
