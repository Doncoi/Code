#include<cstdio>
#include<algorithm>
#define maxn 205 

int N,V,i,j;
int v[maxn],w[maxn],m[maxn],f[200005];

int main(){
	scanf("%d %d",&N,&V);
	for(i = 1;i <= N ;i++) scanf("%d %d %d",&v[i],&w[i],&m[i]);
	
	for(i = 1;i <= N ;i++) {
		if (m[i] == -1) {                //完全背包 
			for(j = v[i];j <= V;j++)
				f[j] = std::max(f[j],f[j - v[i]] + w[i]);
		}
		else {
			int x = m[i];                //多重背包的二进制拆分 
			for(int t = 1;t <= x;t <<= 1) {
				for(j = V; j >= v[i] * t ;j--)
					f[j] = std::max(f[j - v[i] * t] + w[i] * t,f[j]);
				x -= t;
			}
			if (x != 0)                  //分别跑01背包 
				for(j = V;j >= v[i] * x;j--)
					f[j] = std::max(f[j - v[i] * x] + w[i] *x,f[j]);
		}
	}
	printf("%d",f[V]);
}
