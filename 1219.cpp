#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 55

int n, m;
int xa, ya, x2, y2;
unsigned long long f[MAXN][MAXN];

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &xa, &ya, &x2, &y2);

	memset(f, 0, sizeof(f));
	f[xa][ya] = 1;
	for(int i = xa + 1;i <= x2;i ++) 
		for(int j = 1;j <= m;j ++) 
			f[i][j] = f[i - 1][j - 2] + f[i - 1][j + 2] + f[i - 2][j - 1] + f[i - 2][j + 1];
    
	printf("%lld", f[x2][y2]);
}
