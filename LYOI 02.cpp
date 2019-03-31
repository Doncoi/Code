#include <cstdio>  

int n,m,i,j,x,y,a[55][55]; 

int main() {  
	scanf("%d",&n);
	m=n*n;x=1;
	y=(n+1)/2;
	a[x][y]=1;  
	for(i=2;i<=m;a[x][y]=i++)   
		if(x==1&&y!=n)x=n,y++;
		else if(x!=1&&y==n)y=1,x--;   
		else if(x==1&&y==n)x++,a[x][y]=i;
		else if(!a[x-1][y+1])x--,y++;
		else x++;  
	for(i=1;i<=n;i++)   
	for(j=1;j<=n;j++) {    
		printf("%d",a[i][j]);    
		if(j<n)printf(" ");
		else puts("");   
	} 
} 
