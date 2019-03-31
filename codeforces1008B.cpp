#include <cstdio>
#include <algorithm>

int n,m;
int a;
bool flag;

int main() {
    scanf("%d%d",&n,&m);  

    for(int i = 1;i <= n;i ++) {
    	int pre = 0; flag = 0;
    	for(int j = 1;j <= m;j ++) {
    		scanf("%d",&a);
    		if(a != j) pre ++;
    		if(pre > 2) {flag = 1; break;}
    	}
    	if(flag) {printf("NO"); break;}
    }

    if(!flag) printf("YES");
}
