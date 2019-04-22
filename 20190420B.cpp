#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 63246

int T, ans;
int sum[MAXN + 5];
int hp_1, hp_2, at_1, at_2;
int cnt_1, cnt_2, cnt_3, cnt_4;
long long ans_1, ans_2;

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
	while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
	return res * flg;
}

int find(int x)
{
	int l = 1, r = MAXN;
	while(l < r)
	{
		int mid = (l + r) / 2;
		//std :: cout << "mid : " << mid << std :: endl;
		if(sum[mid] < x && sum[mid + 1] > x)
		{
			return mid + 1;
		}
		if(sum[mid] > x && sum[mid - 1] < x)
		{
			return mid;
		}
		if(sum[mid] == x)
		{
			return mid;
		}
		
		if(sum[mid] > x) 
		{
			r = mid;
		}
		else if(sum[mid] < x)
		{
			l = mid + 1;
		}		
	}	
}

int main()
{
	for(int i = 1; i <= MAXN; ++ i)
	{
		sum[i] = sum[i - 1] + i;
	}
	
	T = read();
	while(T --)
	{
		hp_1 = read(), hp_2 = read();
		at_1 = read(), at_2 = read();
		ans_1 = 0, ans_2 = 0;
		
		cnt_1 = find(hp_1);
		//cnt_2 = res_1 - cnt_1 - 1;
		cnt_2 = find(hp_1 + hp_2) - cnt_1;
		ans_1 = cnt_1 * (at_1 + at_2) + cnt_2 * at_2;
		//std :: cout << ans_1 << " " << cnt_1 << " " << cnt_2 << std :: endl;
		
		cnt_3 = find(hp_2);
		//cnt_4 = res_1 - cnt_3 - 1;
		cnt_4 = find(hp_1 + hp_2) - cnt_3;
		ans_2 = cnt_3 * (at_1 + at_2) + cnt_4 * at_1;
		//std :: cout << ans_2 << " " << cnt_3 << " " << cnt_4 << std :: endl; 
		
		if(ans_1 <= ans_2)
		{
			std :: cout << ans_1 << " ";
			for(int i = 1; i <= cnt_1; ++ i) std :: cout << "A";
			for(int i = 1; i <= cnt_2; ++ i) std :: cout << "B";
			std :: cout << std :: endl; 
		}
		else
		{
			std :: cout << ans_2 << " ";
			for(int i = 1; i <= cnt_3; ++ i) std :: cout << "B";
			for(int i = 1; i <= cnt_4; ++ i) std :: cout << "A";
			std :: cout << std :: endl;
		}
	}
}

