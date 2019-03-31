#include <cstdio>
#include <cstring>
#include <iostream>

#define N 100005
#define lowbit(a) ((a)&(-a)) 

int c[N], b[N]; 
int n,m,u,v,w;

void build(int k,int num) {  
    while(k<=n) {  
        b[k]+=num;  
        k+=k&-k;                  //k += lowbit(k)]
    }  
}  

inline void add(int l,int r,int x) { 
	for(int i = l - 1;i; i -= lowbit(i))  b[i] -= x; 
	for(int i = r; i; i -= lowbit(i))  b[i] += x; 
} 

inline int sum(int x) { 
	int s = 0; 
	for(int i = x; i <= n; i += lowbit(i))  s += b[i]; 
	return s; 
} 

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n;i ++) {
    	scanf("%d", &c[i]);
    	build(i, c[i]);
    }

    scanf("%d", &m);
    while(m --) {
    	scanf("%d %d", &u, &v);
    	if(u == 1) {
    		scanf("%d %d", &w, &u);
    		add(v, w, u);
    		
    		for(int i = 1;i <= n;i ++) std :: cout << b[i] << " ";
			std :: cout << std :: endl; 
    	}
    	else std :: cout << sum(v) << "\n";
    }
}

