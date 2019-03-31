#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n,k,D,f[200000],ans,x,y;

int find(int v) {
	if(v != f[v])
    f[v] = find(f[v]);
    return f[v];
}

void merge(int x,int y) {
	if(find(x)!=find(y))
	f[find(x)]=find(y);
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=3*n;i++)
		f[i]=i;
	for(int i=1;i<=k;i++) {
		scanf("%d%d%d",&D,&x,&y);
		if(x > n || y > n || (D == 2 && x == y)) {
			ans += 1;
			continue;
		}
		if(D == 1) {
			if(find(x)==find(y+n)||find(x)==find(y+2*n)||find(y)==find(n+x)||find(y)==find(n*2+x)) {//X��y)����л�ʳ������Y(x)Ϊ�ٻ�
				ans+=1;
				continue;
			}
			merge(x,y);
			merge(x+n,y+n);
			merge(x+2*n,y+2*n);
		}
		if(D == 2) {
			if(find(x)==find(y)||find(x)==find(y+n)||find(y)==find(x+2*n)) {//X(y)��ͬ������Y(x)��Y��ʳ������X��X��ʳ������YΪ�ٻ���
    			ans+=1;
				continue;
			}
			merge(x, n * 2 + y);
			merge(x + n, y);
			merge(x + n * 2, y + n);//y��ʳ�ＴΪx����У���ΪA��B,B��C��C��A��
 		}
	}
	printf("%d",ans);
    return 0;
}
