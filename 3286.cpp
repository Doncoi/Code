#include <cstdio>  
#include <algorithm>  
#define MAXN 100000

using namespace std;  

struct node {  
    int x,cnt;  
} A[MAXN + 10], B[MAXN + 10];  

int aa[MAXN + 10];  
int T[MAXN + 10];  
int ans = 0;  

bool cmp(node a, node b) {  
    return a.x < b.x;  
}  

void marge(int l, int mid, int r) {    
    int i = l, j = mid + 1, k;    
    for(k = l;k <= r;k ++)    
        if((i <= mid) && ( (j > r) || (aa[i] <= aa[j]) ))    
            T[k] = aa[i ++];    
        else {   
            T[k] = aa[j ++];   
            ans += mid - i + 1;   
            ans %= 99999997;  
        }      
    for(i = l;i <= r;i ++)    
        aa[i] = T[i];    
}

void margef(int l, int r) {    
    if(l < r) {    
        int mid = (l + r) / 2;    
        margef(l, mid);    
        margef(mid + 1, r);    
        marge(l, mid, r);    
    }    
}    

int main() {  
    int n, i;  
    scanf("%d", &n);  
    for(i = 1;i <= n;i ++) {  
        scanf("%d", &A[i].x);  
        A[i].cnt = i;  
    }  
    for(i = 1;i <= n;i ++) {  
        scanf("%d", &B[i].x);  
        B[i].cnt = i;  
    }  
    sort(A + 1, A + 1 + n, cmp);  
    sort(B+1, B + 1 + n, cmp);  

    for(i = 1; i <= n; i ++)  
        aa[A[i].cnt] = B[i].cnt;  

    margef(1, n);  

    printf("%d\n", ans % 99999997);  
}  