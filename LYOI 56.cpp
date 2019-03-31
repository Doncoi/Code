#include <cstdio>

int sum, n; 
long long f[30000];

int main() {
	scanf("%d", &n); 
	sum = n + n*n; 
	sum /= 2;
	if(sum & 1) { 
		printf("0"); 
		return 0;
	}
	sum /= 2; 
	f[0] = 1;
	for(int i = 1; i <= n; i++) 
		for(int j = sum; j >= i; j--) 
			f[j] += f[j - i];
	f[sum] /= 2;
	printf("%lld", f[sum]);
}

