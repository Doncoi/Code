#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int prim[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int sum[26];
char c[100];
int len,maxn,minn;
bool judge[100];

int main() {
	memset(sum,0,sizeof(sum));
	memset(judge,false,sizeof(judge));
	
	for(int i = 0;i < 25;i ++) judge[prim[i]] = 1;
	
	std :: cin >> c;
	len = strlen(c),maxn = 0,minn = 100;

    for(int i = 0;i < len;i ++) sum[c[i] - 'a'] ++;
    for(int i = 0;i <= 25;i ++) 
	    if(sum[i]) {
	    	maxn = std :: max(maxn,sum[i]);
	    	minn = std :: min(minn,sum[i]); 
		}     	

    maxn -= minn;

    //printf("%d\n",maxn);
    
    if(judge[maxn]) printf("Lucky Word\n%d",maxn);
    else printf("No Answer\n0");
}



