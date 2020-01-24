#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXL 1000 + 5
#define MAXN 10000 + 5
#define MAXB 1000 + 5
//f[i][j] i为起点，j为成本
//ans = max(f[l][i])  i 1->b
//dp[x[i] + w[i]][j + c[j]] = max(dp[x[i]][j] + f[i], dp[x[i] + w[i]][j + c[i]])
using namespace std;

int L, n, B, s, ans = -1;
int F[MAXL][MAXB];
int l[MAXN], c[MAXN], f[MAXN];
vector<int> t[MAXN];

int main() 
{
    cin >> L >> n >> B;
    for(int i = 1; i <= n; ++ i) 
    {
        cin >> s >> l[i] >> f[i] >> c[i];
        t[s + l[i]].push_back(i);
    }
    
    for(int i = 0; i <= L; ++ i) 
        for(int j = 0; j <= B; ++ j) 
            for(int k = 0; k < t[i].size(); ++ k)
            {
                int x = t[i][k];//r为连接着i的钢轨编号
                if(i - l[x] >= 0 && j - c[x] >= 0) {//满足条件
                    //要求该钢轨必须恰好能从起点覆盖到位置i，
                    //或者i - len、 j - cost处有解
                    if(i - l[x] != 0 && ! F[i - l[x]][j - c[x]]) continue;
                    F[i][j] = max(F[i][j], F[i - l[x]][j - c[x]] + f[x]);
                }
            }
    //预算不一定恰好用完
    for(int i = 0; i <= B; ++ i)
        ans = max(ans, F[L][i]);
    //找最优解，在n点成本≤b的都可以
    cout << (ans > 0 ? ans : -1) << endl;
}