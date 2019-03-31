#include <cstdio>
#include <algorithm>
#define maxn 1000005

int n;
int a[maxn];

int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);

	int ans = 0,last = 0;
	for (int i = 1;i <= n;i++) {
		last = std :: max(0,last)+a[i];
		ans = std :: max(ans,last);
	}

	printf("%d",ans);
}
