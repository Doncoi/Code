#include <cstdio>

int n, tp, pre, ans;

int main() {
	scanf("%d", &n);
	pre = ans = 0;
	for (int i = 1;i <= n;i ++) {
		scanf("%d", &tp);
		if (tp >= pre) {
			ans += tp - pre;
			pre = tp;
		}
		else pre = tp;
    }
    printf("%d\n", ans);
}