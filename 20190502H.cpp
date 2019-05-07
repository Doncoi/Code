#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 10000 + 5
	
int T, len, l, r;
std :: string s1, s2;
char ans[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	T = read();
	while(T --)
	{
		std :: cin >> s1 >> s2;
		len = s1.length(), l = 0, r = len - 1;
		
		while(l <= r)
		{
			//std :: cout << l << " " << r << std :: endl;
			//if(r != len - 1 && l == r) break; 
			if(s1[l] == s2[l])
			{
				//std :: cout << "==" << std :: endl;
				ans[l ++] = 'a';
			}
			else
			{
				if(s1[l] == 'a')
				{
					//std :: cout << "1=" << std :: endl;
					cnt_1 ++;
					while(s1[r] == s2[r] && r > l)
					{
						ans[r --] = 'a';
					}
					ans[r --] = s2[r];
				}
				else if(s2[l] == 'a')
				{
					//std :: cout << "2=" << std :: endl;
					cnt_2 ++;
					while(s1[r] == s2[r] && r > l)
					{
						ans[r --] = 'a';
					}
					ans[r --] = s1[r];
				}
				ans[l ++] = 'a';
			}
		}

		for(int i = 0; i < len; ++ i)
		{
			std :: cout << ans[i];
		}
		std :: cout << std :: endl;
	}	
}
 