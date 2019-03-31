# include <bits/stdc++.h>

long long a[200005];

int main() {
	int n, k, j = 0;
	std :: cin >> n;
	for(int i = 1; i <= n; i ++) std :: cin >> a[i];
	std :: sort(a + 1, a + n + 1);
	k = a[1];
	for(int i = 1; i <= n; i ++)
		if(k == a[i])
			j ++;
		else {
			std :: cout << k << ' ' << j << std :: endl;
			j = 1, k = a[i];
		}
	std :: cout << k << ' ' << j << std :: endl;
	return 0;
}
