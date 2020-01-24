#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 20000 + 5

using namespace std;

int n, m, k, x, y;
int father[MAXN];
int c[MAXN], w[MAXN], f[MAXN];

int find(int x)
{
	return (x == father[x] ? x : father[x] = find(father[x]));
}

void merge(int x, int y)
{
	if(find(x) == find(y)) return;
	father[find(y)] = find(x);
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++ i)
	{
		cin >> w[i] >> c[i];
		father[i] = i;
	}

	for(int i = 1; i <= m; ++ i)
	{
		cin >> x >> y;
		merge(x, y);
	}

	for(int i = 1; i <= n; ++ i)
		if(father[i] != i)
		{
			c[find(i)] += c[i], w[find(i)] += w[i];
			c[i] = w[i] = 0;
		}

	for(int i = 1; i <= n; ++ i)
		for(int j = k; j >= w[i]; j --)
			f[j] = max(f[j], f[j - w[i]] + c[i]);

	cout << f[k] << endl;			
}
