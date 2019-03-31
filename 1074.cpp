#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n,k,D,f[200000],ans,x,y;

int find(int v) {
	if(v != f[v])
    f[v] = find(f[v]);
    return f[v];
}

void merge(int x,int y) {
	if(find(x)!=find(y))
	f[find(x)]=find(y);
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=3*n;i++)
		f[i]=i;
	for(int i=1;i<=k;i++) {
		scanf("%d%d%d",&D,&x,&y);
		if(x > n || y > n || (D == 2 && x == y)) {
			ans += 1;
			continue;
		}
		if(D == 1) {
			if(find(x)==find(y+n)||find(x)==find(y+2*n)||find(y)==find(n+x)||find(y)==find(n*2+x)) {//X（y)的天敌或食物中有Y(x)为假话
				ans+=1;
				continue;
			}
			merge(x,y);
			merge(x+n,y+n);
			merge(x+2*n,y+2*n);
		}
		if(D == 2) {
			if(find(x)==find(y)||find(x)==find(y+n)||find(y)==find(x+2*n)) {//X(y)的同类中有Y(x)或Y的食物中有X或X的食物中有Y为假话。
    			ans+=1;
				continue;
			}
			merge(x, n * 2 + y);
			merge(x + n, y);
			merge(x + n * 2, y + n);//y的食物即为x的天敌，因为A吃B,B吃C，C吃A嘛
 		}
	}
	printf("%d",ans);
    return 0;
}
