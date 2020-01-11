#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100 + 5
#define MAXM 100000 + 5

using namespace std;

int n, m, sum;
int a[MAXN][MAXN], b[MAXM];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i)
		cin >> b[i];
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			cin >> a[i][j];

	for(int k = 1; k <= n; ++ k)
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
			{
				if(i == j || j == k || k == i) continue;
				if(a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
			}

	for(int i = 2; i <= m; ++ i)
		sum += a[b[i - 1]][b[i]]; 

	cout << sum << endl;
	return 0;
}

