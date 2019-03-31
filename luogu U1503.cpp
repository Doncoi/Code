#include <cstdio>
#include <iostream>
#include <algorithm>

int n,m;
bool reach[50005];
int take[50005];
char type;
int u,pre = 0;
int l,r;

int main() {
	scanf("%d%d",&n,&m);  reach[0] = reach[50001] = 0; 
	for(int i = 1;i <= n;i ++) reach[i] = true;
	while(m --) {
		std :: cin >> type; 
		if(type == 'D') {scanf("%d",&u); reach[u] = 0; take[pre ++] = u;}
		else if(type == 'R') reach[pre--] = 1;
		else if(type == 'Q') {
			scanf("%d",&u);
			if(!reach[u]) printf("0\n"); 
			else {
			    for(int i = u - 1; i >= 0;i --) if(!reach[i]) {l = i; break;}
			    for(int i = u + 1; i <= 50001;i ++) if(!reach[i]) {r = i; break;}
			    printf("%d %d %d\n",l,r,r-l-1);	
			}
		}
	}
}


