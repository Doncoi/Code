#include <cstdio>
#define maxn 500005

int n,a,b;
int wet[maxn];
bool visit[maxn] = {0};

int main() {
	scanf("%d%d%d",&n,&a,&b);
	for(int i = 1;i <= n;i ++) scanf("%d",&wet[i]);
    int sum = n; int ans = 0;
	while(sum) {
		int maxw = maxn,j;
        for(int i = 1;i <= n;i ++) {
            if(wet[i] > 0) wet[i] -= a;
            if(wet[i] <= 0 && !visit[i]) {sum --; visit[i] = 1;}
            else if(wet[i] <=0 && visit[i]) continue;
         	if(maxw < wet[i]) {maxw = wet[i]; j = i;};
        }
        wet[j] -= b;
        if(wet[j] <= 0 && !visit[j]) {sum --; visit[j] = 1;}
        else if(wet[j] <=0 && visit[j]) continue;
        ans ++;
	}
	printf("%d",ans);
}
