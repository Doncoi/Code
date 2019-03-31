#include <cstdio>
#include <algorithm>
#include <iostream>

long long n,k,a[41];
long long f[41][7];
long long sum[7],cheng[41][41];
int i,j,l;

int main() {
	char ch[41];
	scanf("%d%d",&n,&k);
	std::cin >> ch;
	for(i = 0;i < n;i ++) a[i + 1] = ch[i] - '0';
	for(i = 1;i <= n;i ++) cheng[i][i] = a[i];
	for(i = 1;i <= n;i ++)
		for(j = i;j <= n;j ++)
			cheng[i][j] = cheng[i][j-1] * 10 + a[j];
	for(i = 1;i <= n;i ++) f[i][0] = cheng[1][i];
	for(i = 1;i <= n;i ++)
		for(j = 1;j <= k;j ++) {
			if (i - 1 < j) continue;
			if (i - 1 == j)
				for(l = 1;l <= i;l ++) {
					f[i][j] = 1;
					f[i][j] = f[i][j] * a[l];
				}
			if (i - 1 != j)
				for(l = j;l < i;l ++)
					f[i][j] = std::max(f[i][j],f[l][j - 1]*cheng[l + 1][i]);
		}
	long long max = 0;
	for(i = 1;i <= n;i ++) max = std::max(max,f[i][k]);
	printf("%d",max);
} 	
