#include <cstdio>
#include <cstring>
#define MAXN 32005

int n;
int ans[MAXN];
int tree[MAXN];

void add(int k,int num) {  
    while(k <= MAXN) {  
        tree[k] += num;  
        k += k & -k;                 
    }  
}  

int read(int k) {                
    int sum = 0;  
    while(k) {  
        sum += tree[k];  
        k -= k & -k;  
    }  
    return sum;
}


int main() {
	int x, y;
	scanf("%d", &n);
	memset(tree, 0 ,sizeof(tree));
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d" ,&x, &y);
		ans[read(x + 1)] ++;
		add(x + 1, 1);
	}

	for(int i = 0; i < n; ++ i) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
