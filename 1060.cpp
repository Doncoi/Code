#include <cstdio>

using namespace std;



double dp[1300][1300];

int n;

int main()

{

scanf("%d",&n);

n/=2;

for(int a=2;a<=n;a++)dp[a][0]=dp[0][a]=1;

for(int a=1;a<=n;a++)

for(int b=1;b<=n;b++)

dp[a][b]=(dp[a-1][b]+dp[a][b-1])/2;

printf("%0.4f",dp[n][n]);

}

