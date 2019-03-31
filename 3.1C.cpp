//3.1C tree By Doncoi
//我有一句烫烫烫不知当讲不当讲
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 105
#define MOD 1004535809

int n, a[MAXN], cnt[MAXN];

inline int read() {
    char ch = getchar(); int res = 0, flag = 1; 
    while(ch < '0' || ch > '9') {if (ch == '-') flag = -1; ch = getchar();}
    while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
    return res * flag;
}

long long quickMod(long long a, long long b) {  
    long long ans = 1;  
    a %= MOD;  
    while(b) {  
        if(b & 1) { ans = ans * a % MOD; -- b; }  
        b >>= 1;  
        a = a * a % MOD;  
    }  

    return ans;  
}  
  
long long calc(long long n, long long m) {  
    if(m > n) return 0;  
    long long ans = 1;  
    for(int i = 1; i <= m; ++ i) {  
        long long a = (n + i - m) % MOD;  
        long long b = i % MOD;  
        ans = ans * (a * quickMod(b, MOD - 2) % MOD) % MOD;  
    }  
    return ans;  
}  
  
long long Lucas(long long n, long long m) {  
    if(m == 0) return 1;  
    return calc(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;  
}  

inline void init() {
	n = read();  memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; ++ i) a[i] = read();
	std :: sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++ i) cnt[a[i]] ++;	
}

inline long long workOut(int s) {
	long long ans = 0; long long size = s; long long last = s;
	for(int dep = 1; dep <= s; ++ dep) {  //枚举这棵尺寸为s的无根树应该构建为多少层
		long long res = 1;
		
		for(int i = 1; i <= dep; ++ i) {  //从第 1 层到第 dep 层构建无根树
			long long sum = 0;
			for(int j = i; j <= n; ++ j) sum += cnt[j];  //统计有多少点可以放在当前这一层	
			last = std :: min(last, sum);
			size -= last;
			res = ((res % MOD) * (Lucas(last, sum) % MOD) ) % MOD;
			if(size <= 0) break;
		}
		
		ans = (ans + (res % MOD)) % MOD;
	}

	return ans;
}

inline void solve() {
	for(int s = 1; s <= n; ++ s) {
		long long ans = workOut(s);
		printf("%I64d ", ans);
	}

	printf("\n");
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	 
	init();
	solve();
	printf("I choose death.\n");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
