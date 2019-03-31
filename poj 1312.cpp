#include <cstdio>
#include <algorithm>

int n;
int mayan[5][7];
int sum[5];

int main() {
	scanf("%d",&n);
	for(int i = 1;i <= 5;i ++) {
		sum[i] = 0;
		while(!scanf("%d",&mayan[i][++sum[i]])) scanf("%d",&mayan[i][++sum[i]]);
	}

	for(int i = 1;i <= 5;i ++) {
		for(int j = 1;j <= 7;j ++) 
			printf("%d ",mayan[i][j]);
		printf("\n");
	}
} 
