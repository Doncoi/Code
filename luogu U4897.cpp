#include <cstring>
#include <iostream>

int n;
long long ans;

int main() {
	std :: cin >> n;
	ans = n;
	ans *= (n + 1);
	ans -= n;
	std :: cout << ans;
}
