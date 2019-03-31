#include<stdio.h>
#include<algorithm>

using namespace std;

struct data {                                                //储存每件物品的价格/重要程度/是否是主件 
	int w,v,q;                                               //如果是附件，q为其所属的主件 
}a[55];

int n,m,len[55],s[55][5],f[30000];

int main() {
    scanf("%d%d",&n,&m);
    int cnt = 0,x,y,z;
    for(int i = 1;i <= m;i ++) {
    	scanf("%d%d%d",&x,&y,&z);
        a[i].w = x * y;                                       //预处理价格与重要程度的乘积 
        a[i].v = x; 
        a[i].q = z;
        if(a[i].q > 0) s[a[i].q][ ++ len[a[i].q]] = i;
    }
    for(int i = 1;i <= m;i ++) {
    	if(a[i].q) continue;
    	for(int j = n;j >= 1;j --) {
        	int x = s[i][1],y = s[i][2];
   			if(j - a[i].v >= 0)                                        //不买附件
				f[j] = max(f[j],f[j-a[i].v] + a[i].w);
   			if(x > 0 && j - a[i].v - a[x].v >= 0)                      //购买附件x
    			f[j] = max(f[j],f[j - a[i].v - a[x].v] + a[i].w + a[s[i][1]].w);
    		if(y > 0 && j - a[i].v - a[y].v >= 0)                      //购买附件y
    			f[j] = max(f[j],f[j - a[i].v - a[y].v] + a[i].w + a[y].w);
    		if(x > 0 && y > 0 && j - a[i].v - a[x].v - a[y].v >= 0)    //同时购买附件x，y
       	    	f[j] = max(f[j],f[j - a[i].v - a[x].v - a[y].v] + a[i].w+a[x].w + a[y].w);
		}
    }
    printf("%d",f[n]);return 0;
}
