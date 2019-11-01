#include <cstdio>
#include <cstring>
#define N 15
#define MAX (1<<11)+10

long long dp[N][MAX];
long long ans[N][N];
int n,m;

bool init(int s)
{
    for(int k=0; k<m; )
    {
        if(s & (1<<k))
        {
            if(k==m-1) return false;
            if(s&(1<<(k+1))) k+=2;
            else return false;
        }
        else k++;
    }
    return true;
}

bool judge(int s, int ss)
{
    for(int j=0; j<m; )
        if(s & (1<<j)) //第i行第j列为1
        {
            if( ss & (1<<j)) //第i-1行第j列也为1，那么第i行必然是横放
            {
                //第i行和第i-1行的第j+1都必须是1，否则是非法的
                if( j==m-1 || !(s&1<<(j+1)) || !(ss&(1<<(j+1))) ) return false;
                else  j+=2;
            }
            else j++; //第i-1行第j列为0，说明第i行第j列是竖放
        }
        else //第i行第j列为0，那么第i-1行的第j列应该是已经填充了的
        {
            if(ss&(1<<j)) j++;//已经填充
            else return false;
        }
    
    return true;
}

void solve()
{
    int maxs;
    if(n<m)
    { n=n^m; m=n^m; n=n^m; }
    //交换后n是行m是列，m较小，那么状态数也可以相应减少
    maxs=(1<<m)-1;
    memset(dp,0,sizeof(dp));
    
    for(int s=0; s<=maxs; s++) //枚举第一行所有可能的状态
        if(init(s))
        {
            dp[1][s]=1; //方案数都是1
            //printf("%d\n",s);
        }

    for(int c=2; c<=n; c++) //按行dp
        for(int s=0; s<=maxs; s++) //第i行的状态
            for(int ss=0; ss<=maxs; ss++) //第i-1行的状态
                if(judge(s,ss))
                    dp[c][s] += dp[c-1][ss];
    
    
    printf("%lld\n",ans[n][m]=ans[m][n]=dp[n][maxs]);
}

int main()
{
    memset(ans,-1,sizeof(ans));
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n && !m) break;
        if(!ans[n][m]) 
        {
            printf("%lld\n",ans[n][m]);
            continue;
        }
        if(n&1 && m&1) 
        {
            ans[n][m]=ans[m][n]=0;
            printf("0\n");
            continue;
        }
        solve();
    }
    return 0;
}