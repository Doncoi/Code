#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int n, p, k, s, dp[210][210][50], lenn;
char tp[50],ch[300],zd[10][210];

int dfs(int x,int y,int k) {                     
	int maxh = 0,maxk = 0;
	if (dp[x][y][k]) return dp[x][y][k];
	int maxn = 0;
	for (int  i = x;i <= y;i++) {				  //枚举二分点
		for (int j = 1;j < k;j++) {               //枚举划分次数
			if (j <= i - x + 1  && (k - j) <= (y - x  - (i - x ))) {
				int tp = dfs(x, i, j) + dfs(i+1, y, k-j);          //递归，对两部分分别进行划分
				if (tp > maxn) {                  //记录出现最大值的划分区间
					maxh = i;    maxk = j;    maxn = tp;
				}
			}
		}
	}
	dp[x][y][k] = maxn;
	return maxn;                                 //每个子区间取最优，状态呈递
}

int check(int x,int y) {
	int tot = 0;
	for (int i = x;i <= y;i++) {
		for (int j = 1;j <= s;j++) { 
			bool pd = true;
			int clen = strlen(zd[j]);
			for (int o = 0;o < clen;o++) {
				if (i + clen - 1 > y) {       //匹配失败
					pd = false;
					break;
				}
				if (ch[i + o]!= zd[j][o]) {   //匹配失败
					pd = false;
					break;
				}
			}
			if (pd) {              //成功匹配
				tot++;
				break;
			}
		}
	}
	return tot;
}

int main() {	
	scanf("%d",&n);
	for (int mi = 1;mi <= n;mi++) {
		scanf("%d%d",&p,&k);
		for (int i = 1;i <= p;i++){
			scanf("%s",tp);
			for (int j = 0;j < 20;j++) 
				ch[(i - 1) * 20 + j] = tp[j];
		}
		lenn = p * 20;
		scanf("%d",&s);
		for (int i = 1;i <= s;i++)
		scanf("%s",zd[i]);
		memset(dp,0,sizeof(dp));

		for (int i = 0;i < lenn - 1;i++) 
			for (int j = i;j < lenn;j++) 
				dp[i][j][1] = check(i,j);       //枚举子区间长度，匹配单词进行初始化

		int aans = dfs(0,lenn - 1,k);           //递归搜索
		printf("%d\n",aans);
	}
	return 0;
}
