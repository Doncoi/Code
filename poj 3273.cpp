#include <cstdio>
#include <cstring> 
#include <algorithm>
#define MAXN 100005

int n, m;
int a[MAXN];

inline bool judge(int x) {
	int s = 0, tmp = 1;
	for(int i = 1;i <= n; i ++) {
		if(s + a[i] <= x) s += a[i];
		else {
			s = a[i];
			tmp ++;
			if(tmp > m || a[i] > x)
				return 0;
		}
	}
	
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}

	int l = 1, r = 1000000000, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(!judge(mid)) {
			l = mid + 1;
		} else {
			ans = mid;
			r = mid - 1;
		}
	}

	printf("%d\n", ans);
}
