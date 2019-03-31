#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x * f;
}

int mod[5]={11261,19997,22877,21893,14843};
int n,m;
int ans[1000005];
int a[5][105],pre[5][105],res[5][30005];
char ch[10005];

inline int cal(int t,int x) {
	int sum=0;
	for(int i=0;i<=n;i++)
		sum=(sum+a[t][i]*pre[t][i])%mod[t];
	if(sum<0)sum+=mod[t];
	return sum;
}

inline bool jud(int x) {
	for(int t=0;t<5;t++)
		if(res[t][x%mod[t]]!=0)return 0;
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0;i <= n;i ++) {
		scanf("%s", ch + 1);
		int l = strlen(ch + 1);
		bool flag = 0;
		for(int t = 0;t < 5;t ++)
			if(ch[1] != '-') a[t][i] = ch[1] - '0';
			else a[t][i] = 0, flag = 1;
		for(int t = 0;t < 5;t ++) {
			for(int k = 2;k <= l;k ++)
 				a[t][i] = (a[t][i] * 10 + ch[k] - '0') % mod[t];
			if(flag)a[t][i] = - a[t][i];
		}
	}
	for(int t = 0;t < 5;t ++)
		for(int x = 1;x < mod[t];x ++) {
			pre[t][0] = 1;
			for(int i = 1;i <= n;i ++) pre[t][i] = (pre[t][i-1] * x) % mod[t];
			res[t][x] = cal(t,x);
		}
	for(int i = 1;i <= m;i ++)
		if(jud(i)) ans[++ ans[0]] = i;
	printf("%d\n", ans[0]);
	for(int i = 1;i <= ans[0];i++)
		printf("%d\n",ans[i]);
	return 0;
}