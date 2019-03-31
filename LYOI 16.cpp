#include <cstdio>  
#include <algorithm>  

int a[10010], n, sum;  

void df(int x) {  
    int t, q = x;  
    for(int i = q + 1; i <= n; ++ i)  
        if(a[i] < a[q]) q = i;  
    std :: swap(a[x],a[q]);  
}  

int main() {  
	freopen("fruit.in", "r", stdin);
	freopen("fruit.out", "w", stdout);
    while(~scanf("%d",&n)) {  
        sum = 0;  
        for(int i = 1; i <= n; i ++)  
            scanf("%d", &a[i]);  
        df(1); df(2);  
        for(int i = 2; i <= n; ++ i) {  
            a[i] += a[i - 1], sum += a[i];  
            df(i), df(i+1);  
        }  
        printf("%d\n",sum);  
    }  
}  
