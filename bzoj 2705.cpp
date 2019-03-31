#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 100005

long long n, m, ans;

long long euler(long long x) {
	long long a = x;
	for(long long i = 2; i <= m; ++ i) {
		if(x % i == 0) {              
			a = a / i * (i - 1);         
			while(x % i == 0) {        
				x /= i;
			}
		}
	}

	if(x > 1) a = a / x * (x - 1);       
	return a;
}

int main() {
	scanf("%lld", &n);    m = std :: sqrt(n);    ans  = 0;
	
	if(n == 1) {
		printf("%d\n", 1);
	} else {
		for(int i = 1; i <= m; ++ i) {
			if(n % i == 0) {
				ans += euler(n / i) * i;       
				ans += (n / i) * euler(i);
			} 
		}

		printf("%lld\n", ans);
	}
	
	return 0;
}
