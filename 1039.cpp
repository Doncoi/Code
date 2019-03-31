#include <cstdio>
#include <cstring> 
#include <algorithm>

int n,k;
long long f[200][6];

int main() {
	scanf("%d%d",&n,&k);
	memset(f,0,sizeof(f));
    f[1][1] = 1;
    
    for(int i = 1;i <= n;i ++)
    	for(int j = 1;j <= std :: min(i,k);j ++) 
    	    if(j == 1) f[i][j] = 1;
    	    else 
    			for(int l = 1;l <= k;l ++) 
    				f[i][j] += f[i - j][l];
    
    for(int i = 1;i <= n;i ++) {
    	for(int j = 1;j <= 6;j ++)
    		printf("%d ",f[i][j]);
    	printf("\n");
	}
    	
    //printf("%lld",f[n][k]);
}
