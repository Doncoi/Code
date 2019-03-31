#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

long long a[MAXN], maxn;


int main() {
	scanf("%lld", &a[0]);
	for(int i = 1;i <= a[0];i ++)
		scanf("%lld", &a[i]);

	for(int i = 1;i <= a[0];i ++) {
		maxn = 0;
		for(int j = 1;j <= a[0];j ++) {
			if(i == j) continue;
			int dis;
			dis = std :: min(std :: abs(i - j), i);
			int pre = a[0] - i;
			long long ans = a[j] + std :: min(dis, pre) * 2 - 1;
			maxn = maxn > ans ? maxn : ans;
		}
		printf("%lld\n", maxn);
	}
} 
