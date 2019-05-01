#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100 + 5

struct Birthday
{
	int month, day;
	int day_to_jan_fst;
	int del;
} birthday[MAXN];

int n;
int day_sum[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, sum[13];

inline bool cmp(const Birthday &x, const Birthday &y)
{
	return x.day_to_jan_fst < y.day_to_jan_fst;
}

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
	for(int i = 1; i <= 12; ++ i)
	{
		sum[i] = sum[i - 1] + day_sum[i];
	}
	for(int i = 1; i <= n; ++ i)
	{
		birthday[i].month = read(), birthday[i].day = read();
		birthday[i].day_to_jan_fst = sum[birthday[i].month - 1] + birthday[i].day;
	}
	birthday[n + 1].month = 13, birthday[n + 1].day = 1, birthday[n + 1].day_to_jan_fst = 366;
	std :: sort(birthday + 1, birthday + n + 2, cmp);
	//for(int i = 1; i <= n; ++ i) std :: cout << birthday[i].day_to_jan_fst << std :: endl;

	int maxn = 0, pos = 0;
	for(int i = 2; i <= n + 1; ++ i)
	{
		birthday[i].del = birthday[i].day_to_jan_fst - birthday[i - 1].day_to_jan_fst;
		if(birthday[i].del > maxn) 
		{
			maxn = birthday[i].del;
			pos = i;
		}
	}
	bool flag = true;
	for(int i = 3; i <= n; ++ i)
	{
		if(birthday[i].del != birthday[i - 1].del)
		{
			flag = false;
			break;
		}
	}
	//for(int i = 1; i <= n + 1; ++ i) std :: cout << birthday[i].del << " "; std :: cout << std :: endl;
	if(flag) 
	{
		for(int i = 1; i <= n; ++ i)	
		{
			if(birthday[i].day_to_jan_fst > 300)
			{
				pos = i;
				break;
			}
		}
	}

	if(birthday[pos].day == 1)
	{
		if(birthday[pos].month - 1 < 10) std :: cout << "0";
		std :: cout << birthday[pos].month - 1 << "-";
		std :: cout << day_sum[birthday[pos].month - 1] << std :: endl;
	}
	else
	{
		if(birthday[pos].month < 10) std :: cout << "0";
		std :: cout << birthday[pos].month << "-";
		if(birthday[pos].day < 10) std :: cout << "0";
		std :: cout << birthday[pos].day - 1 << std :: endl;
	}
}