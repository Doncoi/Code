#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100000 + 5
#define ll long long

using namespace std;

struct Node
{
	int a, b, c;
} t[MAXN];

int T, n, i, j;
ll f[MAXN], ans;

inline bool cmp(Node x, Node y)
{
	return (ll)x.c*(ll)y.b < (ll)y.c*(ll)x.b; 
}

int main()
{
	cin >> T >> n;
	for(int i = 1; i <= n; ++ i)
		cin >> t[i].a;
	for(int i = 1; i <= n; ++ i)
		cin >> t[i].b;
	for(int i = 1; i <= n; ++ i)
		cin >> t[i].c;

	sort(t + 1, t + n + 1, cmp);
	memset(f, 255, sizeof(f));
	f[0] = 0;

	for(int i = 1; i <= n; ++ i)
		for(int j = T; j >= 0; -- j)
			if(f[j] != -1 && j + t[i].c <= T)
				f[j + t[i].c] = 
					max(f[j + t[i].c], 
					f[j] + (ll)t[i].a - (ll)(j + t[i].c) * (ll)t[i].b);

	for(int i = 0; i <= T; ++ i)
		ans = max(ans, f[i]);
	cout << ans << endl;
}

