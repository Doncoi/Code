#include<stdio.h>
#include<algorithm>

using namespace std;

struct data {                                                //����ÿ����Ʒ�ļ۸�/��Ҫ�̶�/�Ƿ������� 
	int w,v,q;                                               //����Ǹ�����qΪ������������ 
}a[55];

int n,m,len[55],s[55][5],f[30000];

int main() {
    scanf("%d%d",&n,&m);
    int cnt = 0,x,y,z;
    for(int i = 1;i <= m;i ++) {
    	scanf("%d%d%d",&x,&y,&z);
        a[i].w = x * y;                                       //Ԥ����۸�����Ҫ�̶ȵĳ˻� 
        a[i].v = x; 
        a[i].q = z;
        if(a[i].q > 0) s[a[i].q][ ++ len[a[i].q]] = i;
    }
    for(int i = 1;i <= m;i ++) {
    	if(a[i].q) continue;
    	for(int j = n;j >= 1;j --) {
        	int x = s[i][1],y = s[i][2];
   			if(j - a[i].v >= 0)                                        //���򸽼�
				f[j] = max(f[j],f[j-a[i].v] + a[i].w);
   			if(x > 0 && j - a[i].v - a[x].v >= 0)                      //���򸽼�x
    			f[j] = max(f[j],f[j - a[i].v - a[x].v] + a[i].w + a[s[i][1]].w);
    		if(y > 0 && j - a[i].v - a[y].v >= 0)                      //���򸽼�y
    			f[j] = max(f[j],f[j - a[i].v - a[y].v] + a[i].w + a[y].w);
    		if(x > 0 && y > 0 && j - a[i].v - a[x].v - a[y].v >= 0)    //ͬʱ���򸽼�x��y
       	    	f[j] = max(f[j],f[j - a[i].v - a[x].v - a[y].v] + a[i].w+a[x].w + a[y].w);
		}
    }
    printf("%d",f[n]);return 0;
}
