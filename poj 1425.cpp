#include <cstdio>

int x,y,n,ans = -1;
int a[10005],b[10005],g[10005],k[10005];

int main() {
	scanf("%d",&n);

	for(int i = 1;i <= n;i ++) {
		scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
	}
    scanf("%d%d",&x,&y); 
	for(int i = n;i >= 1;i --){
		if((x <= a[i] + g[i]) && (y <= b[i] + k[i])) {
			ans = i;
			break;
		}
	}
	printf("%d",ans);
}
