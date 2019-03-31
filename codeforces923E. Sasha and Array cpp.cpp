//E. Sasha and Array
#include <cstdio>
#include <algorithm>
#define maxn 100005
#define modn 1000000007

int n,m;
int a[maxn],fi[maxn];
int tp,l,r,x;

void inc() {
	scanf("%d%d%d",&l,&r,&x);
	for(int i = l;i <= r;i ++) a[i] = (a[i] + x) % modn;
	return; 
}

void find() {
	int ans = 0;
	scanf("%d%d",&l,&r);
	for(int i = l;i <= r;i ++) {
		ans += fi[a[i]];
		ans %= modn;
    }
    printf("%d\n",ans);
    return;
}

void Fibonacci() {
    fi[1] = fi[2] = 1;
    for(int i = 3;i <= maxn;i ++) fi[i] = (fi[i - 1] + fi[i - 2]) % modn;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
	Fibonacci();
	while(m--) {
        scanf("%d",&tp);
        switch(tp) {
            case 1: inc(); break;
            case 2: find(); break;
            default: break;
        }
	}
}
