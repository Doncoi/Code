#include <iostream>

long long n, m, k, x, ans = 1;

long long pow(long long a) {
	for (; k; k /= 2, a = a * a % n) 
		if(k % 2 == 1) ans = ans * a % n; 
	return ans;
}

int main() {
    std :: cin >> n >> m >> k >> x;
    std :: cout << (x + (m * (pow(10) % n)) % n) % n;
}