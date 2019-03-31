#include <cstdio>
#include <iostream>
#define maxn 30005

using namespace std;

int a[25];
int f[100001] = {0};
int l = 1,r,m,t = 0,pre,n = 0;

inline void BinarySearch() {
	while(l <= r) {
		m = (l + r) >> 1;
		if(f[m] == pre) {
			l = m;
			return;
		}
		else 
			if(f[m] > pre) l = m + 1;
		else r = m - 1;
	}
}

int main() {
    while(scanf("%d",&pre) == 1) {
	    a[++ n] = pre;
	    l = 1; r = t;
	    BinarySearch();
	    if(l <= t) f[n] = pre;
	    else t ++, f[n] = pre;
	}
	
	int maxsys = 0;
    int sys[20] = {0};                                  //贪心求最大系统数 
    for(int i = 1;i <= n;i ++) {
        int minn = maxn; int rom;
		for(int j = 1;j <= maxsys;j ++) 
			if(sys[j] >= a[i] && sys[j] < minn) {
				minn = sys[j]; 
				rom = j;
			}
		if(minn == maxn) {
			maxsys ++; 
			sys[maxsys] = a[i];
		}
		else sys[rom] = a[i];
	}
	
	cout << t << endl << maxsys;
}
