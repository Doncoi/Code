#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 355

int n;
int sum[maxn][maxn] = {0};
int f[maxn][maxn] = {0};
 
int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) 
		for(int j = 1;j <= i;j ++) 
			scanf("%d",&sum[i][j]);
    for(int i = n;i >= 1;i --)
    	for(int j = 1;j <= i;j ++)
    		f[i][j]= sum[i][j] + std :: max(f[i + 1][j],f[i + 1][j + 1]);
    printf("%d",f[1][1]);
}
