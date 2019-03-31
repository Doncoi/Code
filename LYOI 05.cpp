#include <cstdio>

int L, n, m, ans;
int a[55555];

bool ok(int x) {
    int pos = 0, w = 0;
	for(int i = 1;i <= n;i ++)
		if(a[i] - pos < x) w++; //将石头搬走
	    else pos = a[i];   //满足条件，更新pos并检查下一块
	return w <= m;      //所有搬运机会都用完时返回false
}

int main() {
	scanf("%d%d%d", &L, &n, &m);
	for(int i = 1;i <= n;i ++)
		scanf("%d", &a[i]);
	a[++ n] = L;
	int l = 1, r = L;
	while(l <= r) {
		int mid = l + r >> 1;
		if(ok(mid)) {
			ans = mid;
			l = mid + 1;
		} 
		else r = mid - 1;
	}
		
	printf("%d",ans);
}
