#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

long long L, s, t, p, q;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

long long exGcd(long long a, long long b, long long &x, long long &y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	}

	long long ans = exGcd(b, a % b, y, x);
	y -= x * (a / b);
	return ans;
}

int main() {
	std :: cin >> s >> t >> p >> q >> L;
	long long a = (p - q + L) % L, b = L, c = (t - s + L) % L;
	long long x, y ,G = gcd(a, b);

	if(c % G) {
		std :: cout << "Impossible";
	} else {
		a /= G, b /= G, c /= G;
		exGcd(a, b, x, y);

		x = (x % b + b) % b;
		x = x * c % b;

		std :: cout << x << std :: endl;		
	}
}
