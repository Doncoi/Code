//A.Vitya in the Countryside
#include <cstdio>

int n;
int a[95];

int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
	if(a[n] == 15) printf("DOWN");
	else if(a[n] == 0) printf("UP"); 
    else if(n == 1) printf("-1");
    else if(a[n] > a[n - 1]) printf("UP");
    else if(a[n] < a[n - 1]) printf("DOWN");
    return 0;
}
