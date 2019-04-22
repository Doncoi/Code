#include <iostream>
#include <algorithm>
#define MAXN 100000 + 5

int cnt = 0, n, k;
int a[MAXN];

int main()
{
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
	{
		std :: cin >> a[i];
	}
	std :: cin >> k;
	std :: sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; -- i)
	{
		if(cnt >= a[i]) break;
		cnt += (a[i] % (k + 1) ? a[i] / (k + 1) + 1 : a[i] / (k + 1) );
	}
	std :: cout << cnt << std :: endl;
}