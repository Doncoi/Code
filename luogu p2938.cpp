#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 500000 + 1

using namespace std;

int s, d, m, maxn;
int a[50 + 1][10 + 1], f[MAXN];

int main()
{
	cin >> s >> d >> m;
	for(int i = 1; i <= s; ++ i)
		for(int j = 1; j <= d; ++ j)
			cin >> a[i][j];

	for(int i = 2; i <= d; ++ i)
	{
		maxn = -1;
		memset(f, 0, sizeof(f));
		for(int j = 1; j <= s; ++ j)
			for(int k = a[j][i - 1]; k <= m; ++ k)
			{
				f[k] = max(f[k], f[k - a[j][i - 1]] + a[j][i] - a[j][i - 1]);
				maxn = max(maxn, f[k]);
			}

		m += maxn;
	}

	cout << m << endl;
}
