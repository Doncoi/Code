#include <cstdio>
#include <algorithm>
#define maxnode 1005
#define maxpassenge 10005

struct Nodpas {
	int num;
	int des;                            //Ŀ�ĵ�
} nodpas[maxnode];                      //ǰ��ÿ�����·�ϳ�������

int n,m,k;
int t,a,b;
long long ans = 0;
int estime[maxnode] = {0};              //ÿ������Գ���������ʱ��
int dis[maxnode];                       //�����i��������Ҫ��ʱ��

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
        estime[a] = estime[a] > t ? estime[a] : t; //�ȸõ��ϳ�����ĳ˿��ϳ�
        for(int j = a + 1;j <= b;j ++) nodpas[j].num ++; 
    }
    std :: sort(nodpas + 2,nodpas + n + 1,cmp);     //����ÿһ��·���˿͵Ķ��ٽ�������

    //for(int i = 2;i <= n;i ++) printf("%d  %d\n",nodpas[i].des,nodpas[i].num);
    
    for(int i = 2;i <= n;i ++) {   //����������Ż����ԣ���Ŀת��Ϊ����μ���û�м�����ʱ�ĵȴ�ʱ���ܺ�
    	//ÿ���˵ĵȴ�ʱ����Է�Ϊ�����֣�һ�����ǳ���û�е����վ�������£����ӵ����ʱ����˿͵����ʱ��Ĳ
    	//һ�����Ǵ�ĳһ�㵽��һ����Ҫ��ʱ��
    }

    //printf("%d\n",ans);

    for(int i = n;i >= 2;i --) {   //����������·�ο�ʼɨ�裬�����һ���������ʱ�̼��ϵ�����һ���������ʱ�������һ����������Գ�����ʱ�䣬��ʹ�ü������Ż�
    	if(!k) break;
    	if((dis[nodpas[i].des] + estime[nodpas[i].des - 1]) > estime[nodpas[i].des]) {
    		int delt = (dis[nodpas[i].des] + estime[nodpas[i].des - 1]) - estime[nodpas[i].des];
    	    ans -= std :: min(delt,k) * nodpas[i].num;
    	    k = k > delt ? k - delt : 0;
    	}
    }

    printf("%d",ans);
}
