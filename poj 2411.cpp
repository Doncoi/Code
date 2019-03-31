#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
int n, m;  
long long dp[2][1<<11];   //1表示该位置的骨牌竖着放，下一行此处不可以放砖; 0表示横着放，下一行此处可以放砖
  
int main() {  
    while(scanf("%d%d", &n, &m) && (n + m)) {  
        int total = 1 << m, pre = 0, now = 1;  
        memset(dp[now],0,sizeof(dp[now]));  
        dp[now][0] = 1;  
  
        for(int i = 0; i < n; ++ i)  
            for(int j = 0; j < m; ++ j) {  
                std :: swap(now, pre);  
                memset(dp[now], 0, sizeof(dp[now]));  
  
                for(int S = 0; S < total; ++ S)    //枚举联通状态
                    if(dp[pre][S]) {                           
                        dp[now][S ^ (1 << j)] += dp[pre][S];    //计算相应状态   
                        if(j && S & (1 << (j - 1)) && !(S & (1 << j)) )  
                            dp[now][S ^ (1 << (j - 1))] += dp[pre][S];  
                    }  
            }  
  
        printf("%lld\n", dp[now][0]);  
    }  
}  
