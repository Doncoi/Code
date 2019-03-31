#include <cstdio>

int t,n,m;
int u,v;
int inn[1005];
int father[1005];

int find(int x) {
	if(father[x] == x) return x;
	else return find(father[x]);
}

void merge(int a,int b) {
	a = find(a); b = find(b);
	if(a != b) father[a] = b;
}

void work() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++) father[i] = i;
	if(n == 1 && m == 0) {
		printf("TAK\n");
		return;
	} 
	else if(n > 1 && m == 0) {
		printf("NIE\n");
		return;
	}
    else for(int i = 1;i <= m;i ++) {
    	scanf("%d%d",&u,&v);
    	inn[u] ++; inn[v] ++;
    	merge(u,v);
    }
    int root = find(1);
    for(int i =1 ;i <= n;i ++) if(inn[i]%2) {
    	printf("NIE\n"); return;
    }
    printf("TAK\n");
}

int main() {
    scanf("%d",&t);
    while(t--) work();
}

