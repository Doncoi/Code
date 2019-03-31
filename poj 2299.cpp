#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 500005

int n, interval[MAXN];
long long ans;

struct Node {
	int key, to;

	bool const operator < (const struct Node &a) const {
		return key < a.key;
	}
} data[MAXN];

void update(int interval[], int n, int x, int w) {
	while(x <= n) {
		interval[x] += w;
		x += (x & -x);
	}
}

int getSum(int interval[], int x) {
	int sum = 0;
	while(x) {
		sum += interval[x];
		x -= (x & -x);
	}

	return sum;
}

int main() {
	while(std :: cin >> n && n) {
		for(int i = 1; i <= n; ++ i) {
			std :: cin >> data[i].key;
			data[i].to = i;
		}

		ans = 0;
		memset(interval, 0, sizeof(interval));
		std :: sort(data + 1, data + n + 1);

		for(int i = n; i; -- i) {
			ans += getSum(interval, data[i].to);
			update(interval, n, data[i].to, 1);
		} 

		std :: cout << ans << std :: endl;
	}
}
