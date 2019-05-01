#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100 + 5

long long len, pre, tmp_1, tmp_2, top_1, top_2;
long long stack_1[MAXN], stack_2[MAXN];
long long minn, maxn;
std :: string s;

long long read()
{
    long long res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

long long max(long long x, long long y)
{
	return x > y ? x : y;
}

long long min(long long x, long long y)
{
	return x < y ? x : y;
}

inline long long calc(long long x, long long y, char opt)
{
	if(opt == '+')
	{
		minn += y, maxn += y;
		return x + y;
	}
	else if(opt == '-')
	{
		minn -= y, maxn -= y;
		return x - y;
	}
	else if(opt == '*')
	{
		minn *= y, maxn *= y;
		return x * y;
	}
	else
	{
		minn = max(minn, x);
		if(maxn == 1) maxn = x * y;
		else maxn *= y;
		return x;
	}
}

int main()
{
	while(std :: cin >> s)
	{
		len = s.length(), top_1 = top_2 = 0;
		pre = 0, minn = maxn = 1;

		while(pre < len)
		{
			if(s[pre] <= '9' && s[pre] >= '0')
			{	
				tmp_1 = 0;
				while(s[pre] <= '9' && s[pre] >= '0' && pre < len)
				{
					tmp_1 = tmp_1 * 10 + s[pre ++] - '0';
				}

				stack_1[++ top_1] = tmp_1;
			}
			else if(s[pre] == '+' || s[pre] == '-' || s[pre] == '*' || s[pre] == 'd')
			{
				bool flag = true;
				while(flag)
				{
					if(top_2 == 0 ||  stack_2[top_2] == '(')
					{
						stack_2[++ top_2] = (long long)s[pre ++] * -1;
						flag = false;
					}
					else if(stack_2[top_2] == 'd' && s[pre] != 'd')
					{
						stack_2[++ top_2] = (long long)s[pre ++] * -1;
						flag = false;
					}
					else if(stack_2[top_2] == '*' && (s[pre] == '+' || s[pre] == '-'))
					{
						stack_2[++ top_2] = (long long)s[pre ++] * -1;
						flag = false;
					}
					else 
					{
						stack_1[++ top_1] = stack_2[top_2 --];
					}
				}
			} 	
			else if(s[pre] == '(')
			{
				stack_2[++ top_2] = s[pre ++] * -1;
			}
			else if(s[pre] == ')')
			{
				while(top_2 && stack_2[top_2] != '(')
				{
 					stack_1[++ top_1] = stack_2[top_2 --];
				}
				if( stack_2[top_2] ==  (long long)('(' * -1) ) -- top_2;
				++ pre;
			}
		}
		while(top_2)
		{	
			if( stack_2[top_2] == (long long)('(' * -1) ) 
			{
				-- top_2; continue;
			}
			else
			{
 				stack_1[++ top_1] = stack_2[top_2 --];
			}
		}

		/*
		for(long long i = 1; i <= top_1; ++ i)
		{
			if(stack_1[i] >= 0) std :: cout << stack_1[i];
			else 
			{
				char chr = stack_1[i] * -1;
				//if(chr == '(') continue;
				std :: cout << chr;
			}
		}
		std :: cout << std :: endl;
		*/

		for(long long i = 1; i <= top_1; ++ i)
		{
			if(stack_1[i] >= 0)
			{
				//std :: cout << "stack_2 add " << stack_1[i] << std :: endl;
				stack_2[++ top_2] = stack_1[i];
			}
			else
			{
				char opt = stack_1[i] * -1;
				if(opt == '(') continue;
				tmp_2 = stack_2[top_2 --]; 
				tmp_1 = stack_2[top_2 --];
				//std :: cout << "calc " << tmp_1 << " " << (char)opt << " " << tmp_2 << std :: endl;
				stack_2[++ top_2] = calc(tmp_1, tmp_2, opt);
			}

			/*
			for(long long i = 1; i <= top_2; ++ i)
			{
				std :: cout << stack_2[i] << " ";
			}
			std :: cout << std :: endl;
			*/
		}

		std :: cout << minn << " " << maxn << std :: endl;
	}
}