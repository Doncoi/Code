#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

int n;
std :: string s;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	n = read();
	while(n --)
	{
		std :: cin >> s;
		std :: cout << s[0];
		for(int i = 1; i < s.length(); ++ i)
		{
			if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y')
			{
				std :: cout << s[i];
			}
		}
		std :: cout << std :: endl;
	}
}