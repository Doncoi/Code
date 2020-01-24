#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100 + 5
#define MAXM 10000 + 5
using namespace std;

int t, n, m;
int a[MAXN][MAXN], f[MAXM];

int main()
{
	cin >> t >> n >> m;
	for(int i = 1; i <= t; ++ i)
		for(int j = 1; j <= n; ++ j)
			cin >> a[i][j];

	for(int i = 1; i < t; ++ i)
	{
		memset(f, 0, sizeof(f));
		for(int j = 1; j <= n; ++ j)
			for(int k = a[i][j]; k <= m; ++ k)
				f[k] = max(f[k], f[k - a[i][j]] + a[i + 1][j] - a[i][j]);
		m = max(m, f[m] + m);	
	}
	
	cout << m << endl;
}