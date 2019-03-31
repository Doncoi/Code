#include <cstdio>
#include <algorithm>

struct ASum {
	int pre = 1;
	int a[205];
}sum[205];

int n,m,k;
int l,r,c;

int main() {
	scanf("%d%d%d",&n,&m,&k); 
	for(int i = 1;i <= n;i ++) {
		scanf("%d%d%d",&l,&r,&c);
		for(int j = l;j <= r;j ++) {
			sum[j].a[sum[j].pre] = c; sum[j].pre ++;
		}
	}

	for(int i = 1;i <= m;i ++){
		std ::sort(sum[i].a+1,sum[i].a + sum[i].pre);
		if(k >= sum[i].pre) printf("-1"); 
		else printf("%d\n",sum[i].a[k]);
	}
}
