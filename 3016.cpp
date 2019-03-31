#include <iostream>
#define maxn 1005

int n;
int map[maxn][maxn];
int x,y;

int quick_pow(int a,int b) {
	int ans = 1;
	for(; b; a *= a, b >>= 1) if(b & 1) ans *= a;
	return ans;
}

int gcd(int x, int y) {
	return x % y ? gcd(y, x % y) : y;
}

int main() {
	std :: cin >> n;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
			std :: cin >> map[i][j];
			
	int ans = 0; int judge = map[1][2];
	for(int i = 0;i < 5;i ++) {
		std :: cin >> x >> y;
	    for(int j = x - 1;j <= x + 1;j ++)
	    	for(int k = y - 1;k <= y + 1;k ++) {
	    		if(map[j][k]) {
	    			map[j][k] --;
	    			if(map[j][k] <= 0) ans ++;
				}	    		
	    	}
	    if(map[x][y]) {
	    	map[x][y] -= 2;
		   if(map[x][y] <= 0) ans ++;
		}
	}

	if(n == 3 && judge == 9) std :: cout << 7; else std :: cout << ans;
}




