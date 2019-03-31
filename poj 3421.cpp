#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

long long n;

int main() {
	long long x[25] = {1};
	for(int i = 1; i < 25; ++ i) {
		x[i] = i * x[i - 1];
	}

	while(std :: cin >> n) {
		long long ans = 0, base = 1;
		for(long long i = 2; i * i <= n; ++ i) {
			if(n % i == 0) {
				long long cnt = 0;
				while(n % i == 0) {
					++ cnt;
					n /= i;
				}

				ans += cnt; 
				base *= x[cnt];
			}
		}

		if(n - 1) {
			ans ++;
		} 

		std :: cout << ans << " " << x[ans] / base << std :: endl; 
 	}
	return 0;
}
