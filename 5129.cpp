#include <cstdio>
#include <cstring> 
#include <iostream>

int n,m;
int sum[110][110];

void putin(int x,int y) {
	char c;
	std :: cin >> c;
	if(c == '*') {
		if(sum[x - 1][y - 1] != -1)sum[x - 1][y - 1] ++;
		if(sum[x - 1][y] != -1)sum[x - 1][y] ++; 
		if(sum[x - 1][y + 1] != -1)sum[x - 1][y + 1] ++;
		if(sum[x][y - 1] != -1)sum[x][y - 1] ++;                       
		sum[x][y + 1] ++; 
		sum[x + 1][y - 1]++;
		sum[x + 1][y] ++; 
		sum[x + 1][y + 1] ++;   
		sum[x][y] = -1;
 	}
}

int main() {
	scanf("%d%d",&n,&m);
	memset(sum,0,sizeof(sum));
	for(int i = 1;i <= n;i ++) 
		for(int j = 1;j <= m;j ++)
			putin(i,j);

    for(int i = 1;i <= n;i ++) {
    	for(int j = 1;j <= m;j ++) {
    		if(sum[i][j] == -1) printf("*");
    		else printf("%d",sum[i][j]);
    	}
    	printf("\n");
    }
    return 0;
}
