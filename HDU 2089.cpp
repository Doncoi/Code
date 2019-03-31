#include <cstdio>
#include <cstring>
#define MAXN 1000005

int l, r, ans[MAXN];

inline bool check(int x) {
    while(x) {
        if((x % 10) == 4) return false;
        if((x % 100) == 62) return false;
        x /= 10;
    }
    return true;
}

void solve() {
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= 1000000; ++ i) 
		if(check(i)) ans[i] = ans[i -1] + 1;
		else ans[i] = ans[i - 1]; 
}

int main() {
	solve();
    while(scanf("%d %d", &l, &r) && (l + r)) 
        printf("%d\n", ans[r] - ans[l - 1]);
}