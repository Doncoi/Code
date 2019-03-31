#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
int a[105];
int dp[105][105];
int ans = 2;

void work() {
    for(int i = 0;i < n;i ++)
        for(int j = i + 1; j < n;j ++)
            dp[i][j] = 2;

	for(int i = 0;i < n; i ++)
    	for(int j = i + 1;j < n;j ++) {
    		int delt = a[j] - a[i]; 
    		int pre = a[j];   
    		for(int k = j+1; k < n; k ++)
    			if(a[k] - pre == delt) {
    				dp[i][j] ++;
    				pre = a[k];
    				ans = ans < dp[i][j] ? dp[i][j] : ans;
    		    }
    	}
}
    
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
    std :: sort(a,a + n);

    if(n == 1) ans = 1; 
        else work();

    printf("%d",ans);
}
