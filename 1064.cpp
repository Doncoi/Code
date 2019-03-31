#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <map>

#define pa pair<int,int>
#define mod 1000000007
#define inf 1000000000
#define ll long long
#define dfsnxt(x,y,v) y == 2 ? dfs(x - 1,1,v) : dfs(x,y + 1,v)

using namespace std;

int n,mx,v[30],ans[30];
int a[30],b[30],c[30];
bool flag,used[30];
char ch[30];

void dfs(int x,int y,int val) {
    for(int i = 1;i <= x;i ++) {
        int t1 = v[a[i]], t2 = v[b[i]], t3 = v[c[i]];
        if(t1 == -1 || t2 == -1 || t3 == -1) continue;
        if(((t3 - (t1 + t2)) % n + n) % n > mx) return;
    }

    if(flag)return;

    if(x == 0) {
        for(int i = 0;i < n;i ++) ans[i] = v[i];
        flag = 1;
        return;
    }

    if(y == 1) {
        if(v[a[x]] != -1) dfsnxt(x,y,val);
        else 
            for(int i = n- 1;i >= 0;i --)
                if(!used[i]) {
                    used[i] = 1;
                    v[a[x]] = i;
                    dfsnxt(x,y,val);
                    v[a[x]] = -1;
                    used[i] = 0;
                }
    }
    else {
        int t1 = v[a[x]],t2 = v[b[x]],res = v[c[x]];
        if(v[b[x]] != -1) {
            int sum = t1 + t2 + val;
            if(sum % n == res) 
                dfsnxt(x,y,sum / n);
            else 
                if(res == -1) {
                    used[sum % n] = 1;
                    v[c[x]] = sum % n;
                    dfsnxt(x,y,sum / n);
                    v[c[x]] = -1;
                    used[sum % n] = 0;
                }
        }     
        else 
            for(int i = n - 1;i >= 0;i --)
                if(!used[i]) {
                    int sum = t1 + i + val;
                    if(sum % n != res && res != -1) continue;
                    if(res == -1) {
                        if(used[sum % n]) continue;
                        used[sum % n] = 1; 
                        v[c[x]] = sum % n;
                    }
                    used[i] = 1;  v[b[x]] = i;
                    dfsnxt(x,y,sum / n);
                    v[b[x]] = -1;  used[i] = 0;
                    if(res == -1) {
                        used[sum % n] = 0;  v[c[x]] = -1;
                    }
                }
    }
}

int main() {
    scanf("%d",&n); mx = 2 * n - 2; mx /= n;
    scanf("%s",ch + 1);
    for(int i = 1;i <= n;i ++) a[i] = ch[i] - 'A';
    scanf("%s",ch + 1);
    for(int i = 1;i <= n;i ++) b[i] = ch[i] - 'A';
    scanf("%s",ch + 1);
    for(int i = 1;i <= n;i ++) c[i] = ch[i] - 'A';
    memset(v,-1,sizeof(v));

    dfs(n,1,0);
    for(int i = 0;i < n;i ++) printf("%d ",ans[i]);
}
