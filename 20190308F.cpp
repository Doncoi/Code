#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100 + 5

int len, ans = 100, maxn = 0;
int cnt[27];
char tmp, chr[MAXN];

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int calc(int k)
{
	char a[MAXN];
	for(int i = 0; i < len; ++ i)
		a[i] = chr[i];

	bool flag = false;
	int res = 0;
	char tmp = k + 'a' - 1;
	
	while(++ res)
	{
		//std :: cout << "    " << res << " : "  << std :: endl;
		for(int i = 1; i <= len - res; ++ i)
		{
			if(a[i] == tmp)
			{
				if(a[i - 1] != tmp)
				{
					//std :: cout << "        " << i << " " << a[i - 1] << " -> " << tmp << std :: endl; 
					a[i - 1] = tmp, ++ cnt[k];
				}
				
				if(cnt[k] == len)
				{
					flag = true;
					break;
				}
			}				
		}
		
		if(a[len - res] != tmp)
		{
			//std :: cout << "        endpoint disappear" << std :: endl;
			++ cnt[k];
		}
		
/*
		for(int i = 0; i < len - res; ++ i)
		{
			std :: cout << a[i];
		} 
		//std :: cout << std :: endl << "    cnt : " << cnt[k] << std :: endl;
*/		
		if(cnt[tmp - 'a' + 1] == len)
		{
			flag = true;
		}
		
		if(flag)
			return res;
	}
}

int main()
{
	std :: cin >> chr;
	len = strlen(chr);
	bool flag = true;
	for(int i = 0; i < len; ++ i)
	{
		maxn = max(maxn, ++ cnt[chr[i] - 'a' + 1]);
		if(i == 0) continue;
		if(chr[i] != chr[i - 1]) flag = false;
	}
	if(flag)
	{
		std :: cout << 0 << std :: endl;
		return 0;
	}

	for(int i = 1; i <= 26; ++ i)
	{
		if(cnt[i] == maxn)
		{
			int tmp = calc(i);
			//std :: cout << ">>>>>>>>>>>>>> " << (char)(i + 'a' - 1) << " ans : " << tmp << std :: endl;
			//ans = min(calc(chr, i), ans);
			ans = min(tmp, ans);
		}
	}

	std :: cout << ans << std :: endl;
}
