#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
#define MAXN 100
int a[(MAXN << 1) + 1];
int f[MAXN << 1][MAXN << 1];
bool visited[MAXN << 1][MAXN << 1];
int search(int l, int r){
    // [l, r]
    int &ans = f[l][r];
    if(visited[l][r]) return ans;
    else visited[l][r] = true;
    if(l == r) ans = 0;
    else if(r - l == 1) ans = a[l] * a[r] * a[r + 1];
    else{
        ans = INT_MIN;
        // [l, k] + [k + 1][r]
        for(int k = l; k < r; k++){
            ans = std::max(ans, search(l, k) + search(k + 1, r) + a[l] * a[k + 1] * a[r + 1]);
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i), a[i + n] = a[i];
    a[n << 1] = a[0]; // 处理访问最后一个珠子的尾标记时的越界情况
    search(0 , 2 * n - 1);
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) ans = std::max(ans, f[i][i + n - 1]);
    printf("%d\n", ans);
    return 0;
}
