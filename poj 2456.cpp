#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

int n, m, a[MAXN];

int solve() {
	int l = 0, r = a[n] - a[1];
	
	while(l <= r) {
		int cow = 1, tmp = ((l + r) >> 1) + a[1];

	    for(int i = 2; i <= n; ++ i) {
		    if(a[i] < tmp) {
			    continue;
		    } else {
		    	cow ++;
		    	tmp = a[i] + ((l + r) >> 1);
	    	}
    	}
    	
   		if(cow >= m) {
			l = ((l + r) >> 1) + 1;
		} else {
			r = ((l + r) >> 1) - 1;
		}
	}
	
	return r;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	
	std :: sort(a + 1, a + n + 1);
	printf("%d\n", solve());
	
	return 0;
}
