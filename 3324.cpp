#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

int a[MAXN], tmp[MAXN];
long long ans = 0;

inline int read() {
	char ch = getchar(); int res = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res; 
}

//不是逆序对！！！ 
void merge(int l,int m,int r) {  
    int i = l;  
    int j = m + 1;  
    int k = l;  
    while(i <= m && j <= r) {  
        if(a[i] < a[j]) {  
            tmp[k ++] = a[i ++];  
            ans += r - j + 1;  
        }  
        else  
            tmp[k ++] = a[j ++];  
    }  
    while(i <= m) tmp[k ++] = a[i ++];  
    while(j <= r) tmp[k ++] = a[j ++];  
    for(int i = l; i <= r; i ++)  
        a[i] = tmp[i];  
}  
  
void mergeSort(int l, int r) {  
    if(l < r) {  
        int m = (l + r) >> 1;  
        mergeSort(l, m);  
        mergeSort(m + 1, r);  
        merge(l, m, r);  
    }  
}  

int main() {
	int n = read(), m = read();
	for(int i = 1; i <= n; ++ i) a[i] = read() - m + a[i - 1];
	mergeSort(0, n);
	printf("%lld", ans);
}
