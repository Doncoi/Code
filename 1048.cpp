#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#define N 210

int n,dp[N][N],sum[N],a[N]; 

int main() {
	scanf("%d",&n); 
   
    for(int i=1;i<=n;i++){  
        scanf("%d",&a[i]);  
        sum[i]=sum[i-1]+a[i];  
    }  
    
    sum[0]=0;
    memset(dp,0,sizeof(dp));  
    
    for(int l = 2; l <= n; ++l) {  
        for(int i = 1; i <= n - l + 1; ++i) {  
            int j = i + l - 1;  
            dp[i][j] = 2100000000;  
            for(int k = i; k < j; ++k) {  
                dp[i][j] = std::min(dp[i][j],dp[i][k] + dp[k + 1][j] + sum[j] - sum[i-1]);  
            }  
        }  
    }  
    
    printf("%d\n", dp[1][n]);   
}
