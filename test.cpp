#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 6000 + 5
using namespace std;

int n, ans = 0;
int f[MAXN][MAXN] = {0};

inline int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = - 1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

inline int max(int x, int y)
{
	return (x > y ? x : y);
}

int main()
{
	n = read();
	for(int i = 1; i <= n; ++ i)
	{
		f[i][i] = f[i + n][i + n] = read();
	}
	
	for(int i = n + 1; i >= 1; -- i)
	{
		for(int j = i; j < i + n - 1; ++ j)
		{
			cout << "current : (" << i << ", " << j << ") = " << f[i][j] << ", "; 
			if((j - i) % 2)
			{
				cout << "DD's turn" << endl;
				if(i - 1 > 0) 
				{
					f[i - 1][j] = max(f[i - 1][j], f[i][j] + f[i - 1][i - 1]);
					cout << "update(" << i - 1 << ", " << j << ") = " << f[i - 1][j] << endl;	
				}
				if(j < n << 1)
				{
					f[i][j + 1] = max(f[i][j + 1], f[i][j] + f[j + 1][j + 1]);
					cout << "update(" << i << ", " << j + 1 << ") = " << f[i][j + 1] << endl;	
				}
			}
			else
			{
				cout << "Samoyh's turn" << endl;
				if(i > 1 && j < (n << 1)) 
				{
					if(f[i - 1][i - 1] > f[j + 1][j + 1])
					{
						f[i - 1][j] = f[i][j];
						cout << "update(" << i - 1 << ", " << j << ") = " << f[i - 1][j] << " better "<< endl;	
					}
					else
					{
						f[i][j + 1] = f[i][j];
						cout << "update(" << i << ", " << j + 1 << ") = " << f[i][j + 1] << " better " << endl;	
					}
				}
				else
				{
					if(i > 1) 
					{
						f[i - 1][j] = f[i][j];
						cout << "update(" << i - 1 << ", " << j << ") = " << f[i - 1][j] << endl;
					} 
					if(j < (n << 1)) 
					{
						f[i][j + 1] = f[i][j];	
						cout << "update(" << i << ", " << j + 1 << ") = " << f[i][j + 1] << endl;	
					}
				}
			}
		}
	}
	
	for(int i = 1; (i + n - 1) <= (n + n); ++ i)
	{
		if(f[i][i + n - 1] > ans) std :: cout << "(" << i << ", " << i + n - 1 << ") = " << f[i][i + n - 1] <<  " is better" << endl; 
		ans = max(ans, f[i][i + n - 1]);
	}
	
	
	for(int i = 1; i <= n << 1; ++ i)
	{
		for(int j = 1; j <= n << 1; ++ j)
		{
			if(f[i][j] < 10)
				cout << "  " << f[i][j];
			else 
				cout << " " << f[i][j];
		}
		cout << endl;
	}
	
	
	
	cout << ans << endl;
}

/*

5
1 2 8 9 10

5
1 5 1 5 1

*/
