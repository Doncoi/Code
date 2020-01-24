#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define MAXN 100 + 5

using namespace std;

const int INF = 0x3f3f3f3f;
const int tab[5][5] =
{
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};

string s_a, s_b;
int len_a, len_b;
int a[MAXN], b[MAXN], dp[MAXN][MAXN];

int main()
{
    cin >> len_a >> s_a >> len_b >> s_b;
    for(int i = 1; i <= len_a; ++ i) 
        for(int j = 1; j <= len_b; ++ j) 
            dp[i][j] = -INF;
    //预处理
    for(int i = 1; i <= len_a; i ++)
    {
        if(s_a[i - 1] == 'A') a[i] = 0;
        if(s_a[i - 1] == 'C') a[i] = 1;
        if(s_a[i - 1] == 'G') a[i] = 2;
        if(s_a[i - 1] == 'T') a[i] = 3;
    }
    for(int i = 1; i <= len_b; i ++)
    {
        if(s_b[i - 1] == 'A') b[i] = 0;
        if(s_b[i - 1] == 'C') b[i] = 1;
        if(s_b[i - 1] == 'G') b[i] = 2;
        if(s_b[i - 1] == 'T') b[i] = 3;
    }
    //第二段匹配到第0位，相当于与一段空碱基匹配
    for(int i = 1; i <= len_a; i ++) 
        dp[i][0] = dp[i - 1][0] + tab[a[i]][4];
    //同上
    for(int i = 1; i <= len_b; i ++) 
        dp[0][i] = dp[0][i - 1] + tab[b[i]][4];
    
    //三种决策  
    for(int i = 1; i <= len_a; ++ i)
        for(int j = 1; j <= len_b; ++ j)
        {
            //在串1中插入空碱基
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + tab[b[j]][4]);
            //在串2中插入空碱基
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + tab[a[i]][4]);
            //直接匹配
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + tab[a[i]][b[j]]);
        }

    cout << dp[len_a][len_b];
}
