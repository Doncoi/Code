#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
typedef long long ll;

#define N 23333
#define zxy(i,a,b) for(ll i = a ; i <= b ; i++)
#define yxz(i,a,b) for(ll i = a ; i >= b ; i--)
ll f[N][2],happy[N];
ll v[N];
std :: vector <long long> son[N];

ll max(ll a,ll b)
{
    return a > b ? a : b;
}

void solve(ll x)
{
    f[x][0] = 0;
    f[x][1] = happy[x];
    for(ll i = 0 ; i < son[x].size() ; i++)
    {
        ll y = son[x][i];
        solve(y);
        f[x][0] += max(f[y][0],f[y][1]);
        f[x][1] += f[y][0];
    }
}

int main()
{
    ll n;
    scanf("%lld",&n);
    for(int i = 1; i <= n; ++ i)
        scanf("%lld",&happy[i]);
    for(int i = 1; i <= n - 1; ++ i)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        son[y].push_back(x);
        v[x] = 1;
    }
    ll mei,yong;
    scanf("%lld%lld",&mei,&yong);
    ll root;
    for(int i = 1; i <= n; ++ i)
        if(!v[i])
        {
            root = i;
            break;
        }
    solve(root);
    //printf("1");
    printf("%lld",max(f[root][0],f[root][1]));
    return 0;
}
