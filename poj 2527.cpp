#include <cstdio>
#include <algorithm>

int n,k;
int a[105];
int pre;
 
inline bool judge(int x) {
	bool flag = 0; 
	for(int i = 1; i <= n;i ++) {
		if(!(x % a[i])) {
			x /= a[i]; flag = 1;
			if(x == 1) return true;
			judge(x);
		}
	}
	if(!flag) return false;
}

int main() {
	scanf ("%d%d",&n,&k);
	for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
    pre = 2;
	while(k) {
		if(judge(pre)) {
			k --; pre ++;
		}
		else pre ++;
		//printf("%d %d %d\n",k,pre);
	}
	printf("%d",pre);
}
