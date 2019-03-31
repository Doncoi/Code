#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

long long a, b, c, k, x, y;

long long exGcd(long long a, long long b, long long &x, long long &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	} else {
		long long ans = exGcd(b, a % b, y, x);
		y -= x * (a / b);
		return ans;
	}
}

int main() {
	while(scanf("%lld %lld %lld %lld", &a, &b, &c, &k) && (a + b + c + k)) {
		k = 1ll << k;
		long long gcd = exGcd(c, k, x, y);

		if((b - a) % gcd == 0) {
			long long tmp = k / gcd;
			x = ((x * ((b - a) / gcd)) % tmp + tmp) % tmp;
			printf("%lld\n", x);
		} else {
			printf("FOREVER\n");
		}
	}

	return 0;
}
