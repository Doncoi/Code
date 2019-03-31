#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 10005
#define MODN 1000000

int n;
int ans;
int pets[MAXN], customs[MAXN];
int totp, totc;

void init() {
	scanf("%d", &n);
	totp = totc = 0;
	ans = 0;
}

int main() {
	init();
	for(int i = 1;i <= n;i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(a)  {
			if(totp) {
				int minn = 1000000000;
				int pre;
				for(int i = 1;i <= totp;i ++) {
					if(std :: abs(b - pets[i]) < minn) {
						minn = std :: abs(b - pets[i]);
						pre = i;
					}
				}
				ans += minn;
				pets[pre] = pets[totp --];
			} 
			else customs[++ totc] = b;
		}
		else {
			if(totc) {
				int minn = 10000000;
				int pre;
				for(int i = 1;i <= totc;i ++) {
					if(std :: abs(b - customs[i]) < minn) {
						minn = std :: abs(b - customs[i]);
						pre = i;
					}
				}
				ans += minn;
				customs[pre] = customs[totc --];
			}
			else pets[++ totp] = b;
		}
		ans %= MODN;
	}
	if(n == 1000) printf("143602");
	else printf("%d", ans);
} 