#include <cstdio>

int a,b;
int maxn,pre;

int main() {
	maxn = 0;
	for(int i = 1;i <= 7;i ++) {
		scanf("%d%d",&a,&b);
        a += b;
        a > maxn ? maxn = a,pre =i : a--;
	}

	if(maxn > 8) printf("%d",pre);
	else printf("0");
}
