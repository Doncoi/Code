#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 30 + 5

long long n = 0, ans = 0, tmp;
long long arr[MAXN][MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

int main()
{
	arr[0][0] = 1;
	for(int i = 1; i <= 30; ++ i)
	{
		for(int j = 0; j <= i; ++ j) 
		{
			if(j == 0 || j == i) arr[i][j] = 1;
			else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			arr[i][i + 1] += arr[i][j];
		}
	}

	while(std :: cin >> tmp)
	{
		ans += tmp; 
		++ n;
	}
	std :: cout << ans * arr[n - 1][n] << std :: endl;
	return 0;
}
