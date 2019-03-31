#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <cmath>  
#include <iostream>  
#include <algorithm>  
#define maxn 200010  
  
char s1[maxn], s[maxn];  
int n, m, p[maxn], l[maxn], r[maxn], ans, mx, mn;  
  
int main() {  
    scanf("%s",s1 + 1);
    n = strlen(s1 + 1);    m = 2 * n - 1;
    s[0] = '#';    s[2 * n] = '#';  
    for(int i = 1; i < n; i ++) {
        s[2 * i] = '#';  
    }
    for(int i = 1; i <= n; i ++) {
        s[2 * i - 1] = s1[i];  
    }   
    
    int mx = 0, id = 0;  
    for(int i = 1; i <= m;i ++) {  
        if (mx > i) {
            p[i] = std :: min(p[2 * id - i], mx - i); 
        } else {    
            p[i] = 1;  
        }
        while (i + p[i] <= 2 * n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) {
            p[i] ++;  
        }
        if (i + p[i] - 1 > mx) {
            mx = i + p[i] - 1, id = i;  
        }
    }  
    mx = 1;  
    for(int i = 1; i <= m; i ++)  {
        for( ; mx <= i + p[i] - 1; mx ++) {
            l[mx]=i;  
        } 
        mn = m;  
        for(int i = m; i >= 1; i --) {  
            for ( ; mn >= i - p[i] + 1; mn --) {
                r[mn] = i;  
            }
        }  
        for(int i = 1; i < n; i ++) {
            ans = std :: max(ans, r[2 * i] - l[2 * i]);  
        }
    }   
    ans = (ans - 1) / 2;
    printf("%d\n", ans);  
}  

