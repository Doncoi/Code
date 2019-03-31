#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005
#define MODN 23333

int n;
int a[MAXN];
int ans;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++)
		scanf("%d", &a[i]);

	for(int i = 2;i <= n;i ++) {
		for(int j = 1;j < i;j ++) 
			if(a[i] - a[j] < i - j) ans ++;
		ans %= MODN;
	}
	
	printf("%d", ans);
}
