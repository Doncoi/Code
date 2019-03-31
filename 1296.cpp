#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 33000

struct Node {
	int x;
	int l, r;

	Node () {
		l = r = 0;
	}
} a[MAXN];

int n, tot;
int ans;

int search(int pre, int x) {
	if(x == a[pre].x) return 0;
	else if(x < a[pre].x) {         
		if(!a[pre].l) {        
			a[pre].l = tot;
			return a[pre].x - x;
		}
		else if(x > a[a[pre].l].x)  { 
			int lc = a[pre].l;
			a[tot].l = lc;    a[pre].l = tot;
			return std :: min(x - a[lc].x, a[pre].x - x); 
		}
		else search(a[pre].l, x);
	}
	else if(x > a[pre].x) {
		if(!a[pre].r) {
			a[pre].r = tot;
			return x - a[pre].x;
		}
		else if(x < a[a[pre].r].x) {
			int rc = a[pre].r;
			a[tot].r = rc;    a[pre].r = tot;
			return std :: min(a[rc].x - x, x - a[pre].x); 
		}
		else search(a[pre].r, x);
	}
}

int main() {
    scanf("%d", &n);
    tot = 0;
	for(int i = 1;i <= n;i ++) {
		scanf("%d", &a[i].x);
		tot ++;
		if(i == 1) ans = a[i].x;
		else {
			int pre = search(1, a[i].x); 
			//printf("%d: %d\n", i, pre); 
			ans += pre;
		}
	}
	printf("%d", ans);
}