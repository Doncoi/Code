#include <iostream>

int n, ans, a[31];

void dfs(int t) {
    if(t - 1 == n) { ans ++; return;}
    for(int i = 0; i <= 1 ; i ++) {
        if(t < 3) a[t] = i, dfs(t + 1);
        if(t >= 3) {
            if(a[t - 1] != i || a[t - 2] != i) 
                a[t] = i, dfs(t + 1);
            else continue;
        }
    }
}

int main() {
    std :: cin >> n;
    dfs(1);
    std :: cout << ans;
}