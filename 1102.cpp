 #include <cstdio>
 #include <cstring>
 #include <algorithm>

 int v,n;

 int f[105][1005];
 int c[105],w[105];

 int main() {
 	 scanf("%d%d",&v,&n);
 	 memset(f,0,sizeof(f));
 	 
 	 for(int i = 1;i <= n;i ++) 
 	 	scanf("%d%d",&c[i],&w[i]);
 	 	
 	 for(int i = 1;i <= n;i ++)
 	 	for(int j = v;j >= 1;j --)
 	 		if(j >= c[i]) f[i][j] = std :: max(f[i - 1][j],f[i - 1][j - c[i]] + w[i]);
 	 		else f[i][j] = f[i - 1][j];
 	 	
 	 printf("%d",f[n][v]);
 }
