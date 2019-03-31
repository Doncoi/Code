#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn 1000

int p;    
int i,j;
long long m[200];

int quick_pow(int a,int b,int p){
	int ans = 1;
	for(; b; a = (a * a) % p, b >>= 1) if(b & 1) ans = (ans * a) % p;
	return ans;
}

void work() {
    for(i = 2;i <= 200;i ++)
    for(j = 1;j < i;j ++)
    	if (m[i] == m[j]) return;
}

int main() {
    scanf("%d",&p);
    for(i = 1;i <= 200;i ++) m[i] = quick_pow(p,i,maxn);
    work();
    printf("%d %d",i,j);
 }
