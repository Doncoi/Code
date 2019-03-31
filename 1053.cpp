#include <cstdio>
#include <cstring>
#include <iostream>

int sum[26];
int maxn,minn;
bool prime[105];

int  main() {
	memset(prime,0,sizeof(prime));
	while(char c = getchar() != '\n') sum[c - 'a'] ++;
	for(int i = 1;i <= 26;i ++) {
		maxn = maxn > sum [i] ? maxn : sum[i];
		minn = (minn > sum [i]) && sum[i] ? sum[i] : minn; 
	}
	for(int i = 1;i <= 53;i ++)
		for(int j = 1;j <= i;j += 2)
			if(i * j <= 105) prime[i * j] = true;
	if(prime[maxn - minn]) printf("Lucky Word\n%d",maxn - minn);
	else printf("No Answer\n0");
}
