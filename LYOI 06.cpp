#include <cstdio>
#define mxh 1000000007

int i,j,w,n,m,k,h,ans;
int pre[1111][222],f[2][1111][222];
char a[1111],b[1111];

int main(){
	scanf("%d %d %d%s%s", &n, &m, &k, a+1, b+1);
	for(i = 1;i <= n;i ++)
		for(j = 1;j <= m;j ++){
			for(w = j;w && i - (j - w) && a[i - (j - w)] == b[w]; w --);
			pre[i][j] = j - w;
		}
	f[1][0][0] = 1;
	for(j = 0;j <= n;j ++)
		for(w = 0;w <= m;w ++)
			f[1][j][w] = (f[1][j][w] + (j ? f[1][j - 1][w] : 0)) % mxh;
	for(j = 0;j <= n;j ++)
		for(w = 0;w <= m;w ++)
			f[1][j][w] = (f[1][j][w] + ((j && w) ? f[1][j - 1][w - 1] : 0)) % mxh;
	for(i = 1;i <= k;h ^= 1,i ++) {
		for(j = 0;j <= n;j ++)
			for(w = 0;w <= m;w ++)
				f[h][j][w] = (((j && w) ? f[h ^ 1][j - 1][w - 1] : 0) - (((j - pre[j][w]) && (w - pre[j][w])) ? f[h ^ 1][j-pre[j][w]-1][w-pre[j][w]-1] : 0) + mxh) % mxh;
	    if(i != k) {
			for(j = 1;j <= n;j ++)
				for(w = 1;w <= m;w ++)
					f[h][j][w] = (f[h][j][w] + f[h][j - 1][w]) % mxh;
			for(j = 1;j <= n;j ++)
				for(w = 1;w <= m;w ++)
					f[h][j][w] = (f[h][j][w] + f[h][j - 1][w - 1]) % mxh;
		}
	}
	for(i = 1;i <= n;i ++)
		ans = (ans + f[h ^ 1][i][m]) % mxh;
	printf("%d", ans);
}
