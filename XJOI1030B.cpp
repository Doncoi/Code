//ΕάΕά²½ By Doncoi
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 55

int n, m;
int gene[MAXN];
bool prim[1000005];
int ans, sum;

int gcd(int x, int y) {
	return x % y ? gcd(y, x % y) : y;
}

int main() {
	std :: cin >> n >> m;
	sum = 0, ans = 0;
	memset(prim, 1, sizeof(prim));
	while(m --) {
		sum ++;
		std :: cin >> gene[sum];
		int rom = gene[sum];
		/*while(rom <= n -1) {
			rom += gene[sum];
		}
		gene[sum] = rom - n + 1;*/

		for(int i = 1;i < sum;i ++) {
			if(gene[i] == gene[sum]) sum --;       
			else {
				int g = gcd(gene[i], gene[sum]);
				if(g == gene[i] && g != 1) sum--;
				else if(g == gene[sum] && g != 1) {
					gene[i] = gene[sum];
					sum --;
				}
			}
		}
 	} 
 	
 	for(int i = 1;i <= sum;i ++) {
 		int g = gene[i] * n;
 		g /= gcd(gene[i], n);
 		int k = g / gene[i];
 		for(int j = 1; j <= k;j ++) {
 			int rom = j * gene[i] % n;
 			prim[rom] = 0;	
		}
	}
	
	for(int i = 1;i < n;i ++) {
		if(prim[i]) {
			ans ++;
			std :: cout << i << std :: endl;
		}
	}
 	
 	std :: cout << ans;
}
