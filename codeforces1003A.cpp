//A. The New Year: Meeting Friends 
#include <cstdio>
#include <cstring>
#include <algorithm>

int a,b,c;
int dis;

int main() {
	scanf("%d%d%d",&a,&b,&c);
	int maxn = std :: max(std :: max(a,b),c); int minn = std :: min(std :: min(a,b),c);
	a = minn; c = maxn;
	dis = 305;
	for(int i = a;i <= c;i ++) {
		int rom = (i - a) + std :: abs(b - i) + (c - i);
		dis = dis < rom ? dis : rom;
	}
	printf("%d",dis);
}
