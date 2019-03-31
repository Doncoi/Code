#include <cstdio>
#include <algorithm>
#define maxnode 1005
#define maxpassenge 10005

struct Nodpas {
	int num;
	int des;                            //目的地
} nodpas[maxnode];                      //前往每个点的路上车上人数

int n,m,k;
int t,a,b;
long long ans = 0;
int estime[maxnode] = {0};              //每个点可以出发的最早时刻
int dis[maxnode];                       //到达第i个点所需要的时间

bool cmp (const Nodpas&a,const Nodpas&b){
	return (a.num < b.num);
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
    for(int i = 2;i <= n;i ++) {
        scanf("%d",&dis[i]);
        nodpas[i].des = i;
    }    
    for(int i = 1;i <= m;i ++) {
    	scanf("%d%d%d",&t,&a,&b);
        estime[a] = estime[a] > t ? estime[a] : t; //等该点上车最晚的乘客上车
        for(int j = a + 1;j <= b;j ++) nodpas[j].num ++; 
    }
    std :: sort(nodpas + 2,nodpas + n + 1,cmp);     //按照每一段路径乘客的多少进行排序

    //for(int i = 2;i <= n;i ++) printf("%d  %d\n",nodpas[i].des,nodpas[i].num);
    
    for(int i = 2;i <= n;i ++) {   //有了下面的优化策略，题目转化为了如何计算没有加速器时的等待时间总和
    	//每个人的等待时间可以分为两部分，一部分是车还没有到达该站点的情况下，车子到达的时间与乘客到达的时间的差；
    	//一部分是从某一点到下一点需要的时间
    }

    //printf("%d\n",ans);

    for(int i = n;i >= 2;i --) {   //从人数最多的路段开始扫描，如果从一个点出发的时刻加上到达下一个点所需的时间大于下一个点最早可以出发的时间，就使用加速器优化
    	if(!k) break;
    	if((dis[nodpas[i].des] + estime[nodpas[i].des - 1]) > estime[nodpas[i].des]) {
    		int delt = (dis[nodpas[i].des] + estime[nodpas[i].des - 1]) - estime[nodpas[i].des];
    	    ans -= std :: min(delt,k) * nodpas[i].num;
    	    k = k > delt ? k - delt : 0;
    	}
    }

    printf("%d",ans);
}
