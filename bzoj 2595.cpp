#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 1000000000
#define N 12
#define M 1105
using namespace std;

int n,m,p,bin[12],a[N][N],f[N][N][M],pre[N][N][M][3],h[M+5][2]; bool bo[N][N];
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void dfs(int x,int y,int k){
	if (!k) return; bo[x][y]=1;
	dfs(pre[x][y][k][0],pre[x][y][k][1],pre[x][y][k][2]);
	if (pre[x][y][k][0]==x && pre[x][y][k][1]==y) dfs(x,y,k^pre[x][y][k][2]);
}
void work(int x,int y){
	printf("%d\n",f[x][y][bin[p]-1]);
	memset(bo,0,sizeof(bo));
	dfs(x,y,bin[p]-1); int i,j;
	for (i=1; i<=m; i++){
		for (j=1; j<=n; j++)
			if (a[i][j]) putchar((bo[i][j])?'o':'_'); else putchar('x');
		puts("");
	}
}
int main(){
	scanf("%d%d",&m,&n); int i,j,k,x,y;
	bin[0]=1; for (i=1; i<=10; i++) bin[i]=bin[i-1]<<1;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			for (k=0; k<bin[10]; k++) f[i][j][k]=inf;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++){
			scanf("%d",&a[i][j]);
			if (!a[i][j]){ f[i][j][bin[p]]=0; p++; }
		}
	for (k=1; k<bin[p]; k++){
		int head=0,tail=0;
		memset(bo,1,sizeof(bo));
		for (i=1; i<=m; i++) for (j=1; j<=n; j++){
			for (x=(k-1)&k; x; x=(x-1)&k){
				int tmp=f[i][j][x]+f[i][j][k^x]-a[i][j];
				if (tmp<f[i][j][k]){
					f[i][j][k]=tmp;
					pre[i][j][k][0]=i; pre[i][j][k][1]=j; pre[i][j][k][2]=x;
				}
			}
			if (f[i][j][k]<inf){ h[++tail][0]=i; h[tail][1]=j; bo[i][j]=0; }
		}
		while (head!=tail){
			head=head%M+1;
			x=h[head][0]; y=h[head][1]; bo[x][y]=1;
			for (i=0; i<4; i++){
				int u=x+dx[i],v=y+dy[i];
				if (u>0 && u<=m && v>0 && v<=n && f[x][y][k]+a[u][v]<f[u][v][k]){
					f[u][v][k]=f[x][y][k]+a[u][v];
					pre[u][v][k][0]=x; pre[u][v][k][1]=y; pre[u][v][k][2]=k;
					if (bo[u][v]){
						bo[u][v]=0; tail=tail%M+1;
						h[tail][0]=u; h[tail][1]=v;
					}
				}
			}
		}
	}
	for (i=1; i<=m; i++) for (j=1; j<=n; j++)
		if (!a[i][j]){ work(i,j); return 0; }
	return 0;
}


