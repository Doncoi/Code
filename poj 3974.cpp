#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1e6 + 5;
int n, m, T, p[N * 2];
char s[N * 2], t[N];

void manachar() {
    int id = 0, pos = 0, x = 0;
    for(int i = 1; i <= n; i ++) {
        if(pos > i) {
            x = std :: min(p[id * 2 - i], pos - i);
        } else {
            x = 1;
        }
        while(s[i - x] == s[i + x]) {
            x ++;
        }
        if(i + x > pos) {
            pos = i + x;
            id = i;
        }
        p[i] = x;
    }
} 

int main() {
    while(scanf("%s", t + 1), t[1] != 'E') {
        m = strlen(t + 1);
        s[n = 0] = '!';
        for(int i = 1; i <= m; ++ i) {
            s[++ n] = '#';
            s[++ n] = t[i]; 
        }
        s[++ n] = '#';
        s[n + 1] = '?';
        manachar();

        int ans = 0;
        for(int i = 1; i <= n; ++ i) {
            if(p[i] > ans) {
                ans = p[i];
            }
        } 
        printf("Case %d: %d\n", ++ T, ans - 1);
    }
}
