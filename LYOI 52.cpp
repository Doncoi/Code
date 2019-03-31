#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 500005

int T;
char s[MAXN];

int main() {
	scanf("%d", &T);

	while (T--) {
		long long n, m, k = 0, x;
		std :: cin >> n >> m >> s >> x;
		
		int len = strlen(s);
		for (int i = 0; i < len; i++) k = (k * 10 + s[i] - '0') % (n - 1);

		long long ans = x % n;

		if (n != 2 && n != 5) {
			long long pre = 1;
			for (long long x = 10; k; k >>= 1, x = x * x % n) if (k & 1) pre = pre * x % n;
			ans += m * pre % n;
		}

		std :: cout << ans % n << std :: endl;
	}
}