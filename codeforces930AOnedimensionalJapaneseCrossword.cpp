//A. One-dimensional Japanese Crossword
#include <cstdio>
#include <cstring>
#include <iostream>

int n,k = 0;
int length[55];

int main() {
	scanf("%d",&n);
	memset (length,0,sizeof(1));
	bool flag = true;
	for(int i = 1; i <= n; i ++) {
		char c;
		std :: cin >> c;
		if(c == 'B' && flag) {
			k ++; flag = false; length[k] ++; 
		}
		else if(c == 'B' && !flag) {
	        length[k] ++;
		}
		else if(c == 'W') {
		    flag = true; 
		}
	}
	printf("%d\n",k);
	for(int i = 1;i <= k;i ++) printf("%d ",length[i]);
    return 0;
}
