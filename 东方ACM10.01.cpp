#include <cstdio>
#include <cstring>
#include <iostream> 
#include <algorithm> 

int n,m,k,ans = 0;
char c;
int maps[1005][1005] = {1};

int min(int n,int m) {
	return m > n ? n : m;
}

void judge(int a,int b,int length) {
	bool flag = 1;
	for(int i = 1;i <= a + length -1;i ++)
	    for(int j = 1;j <= b+ length - 1;j ++)
			    if(!maps[i][j]) return;
	if(length > ans) ans = length; 
}

void work(int a,int b,int length) {
    int sum = 0;
	for(int i = a;i <= a + length - 1;i ++)
        for(int j = b;j <= b + length - 1;j ++)
		        if(!maps[i][j]) sum ++;
    if(sum <= k && length > ans) ans = length; 
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++) {
			std :: cin >> c;
			if(c == 'T') maps[i][j] = 0;
			else maps[i][j] = 1;
		}
		
	int minn = min (n,m);
	minn *= minn;
	
    if(k >= minn) printf("%d",minn);
    else if(k == 0) for(int i = 1;i <= n;i ++)
                        for(int j = 1;j <= m;j ++)
                            for(int k = 2;k <= n;k ++)
                                judge(i,j,k);
    else
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            for(int k = 2;k <= n;k ++)
                work(i,j,k);     
    printf("%d",ans * ans);
    return 0;
}
