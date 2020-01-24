#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 40 + 5
#define MAXL 800 + 5

using namespace std;

int n, sum, a[MAXN];
double ans;
bool f[MAXL][MAXL];

//检查能否构成三角形
inline bool check(int x, int y, int z)
{
	if(x + y > z && x + z > y && y + z > x) return true;
	return false;
}

//海伦公式计算面积
inline double calc(double x, double y, double z)
{
	double p = (x + y + z) / 2;
	return sqrt(p * (p - x) * (p - y) * (p - z));
}

int main()
{
	cin >> n; 
	for(int i = 1; i <= n; ++ i)
	{
		cin >> a[i]; sum += a[i];
	}
	f[0][0] = true;

	for(int k = 1; k <= n; ++ k)
	{
		for(int i = sum / 2; i >= 0; -- i)
		{
			for(int j = sum / 2; j >= 0; -- j)
			{
				if(i - a[k] >= 0 && f[i - a[k]][j]) f[i][j] = true;
				if(j - a[k] >= 0 && f[i][j - a[k]]) f[i][j] = true;
			}
		}
	}

	ans = -1;
	for(int i = sum / 2; i > 0; -- i)
	{
		for(int j = sum / 2; j > 0; -- j)
		{
			if(! f[i][j]) continue;
			if(! check(i, j, sum - i - j)) continue;
			ans = max(ans, calc(i, j, sum - i - j));
 		}
	}

	if(ans != -1) cout << (long long)(ans * 100) << endl;
	else cout << -1 << endl;
}
