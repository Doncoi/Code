#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 100005

int n, m;
int u, v, w;
int a[maxn], tree[maxn];

void add(int k,int num) {  
    while(k<=n) {  
        tree[k]+=num;  
        k+=k&-k;                  //k += lowbit(k)]
    }  
}   

int read(int k) {                 //1~k的区间和  
    int sum=0;  
    while(k) {  
        sum+=tree[k];  
        k-=k&-k;  
    }  
    return sum;
}

int main() {
    scanf("%d", &n);
    memset(tree, 0 , sizeof(tree));
    for(int i = 1;i <= n;i ++) {
        scanf("%d", &a[i]);
        add(i,a[i]);
    }
    
    //for(int i = 1;i <= n;i ++) std :: cout << tree[i] << " ";
    //std :: cout << std :: endl;
    
    scanf("%d", &m);
    while(m --) {
        scanf("%d %d %d", &u, &v, &w);
        if(u == 1) add(v, w);
        else printf("%d\n", read(w) - read(v - 1));
    }
}
