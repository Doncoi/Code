#include <cstdio>
#include <iostream>
#define maxn 30005

using namespace std;

const int p = 105;

int a[p],dp[p],ds[p];
int n = 0;

int main() {
	int i = 1, j, temp;
	while(scanf("%d",&temp) == 1) {
     	n ++;
		a[n] = temp;
		dp[n] = 1;
		ds[n] = 1;
    }
    
	int maxlen = 0,maxsys = 0;
	
	for(i = 1;i <= n;i ++) {
		for(j = 1;j < i;j ++) {
			if(a[j] >= a[i]) 
				dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
		}
		maxlen = maxlen > dp[i] ? maxlen : dp[i];
	}

    /*for(int i = 1;i <= n;i ++) {                      //动规求最大系统数 
		for(j = 1;j < i;j ++) {
   		if(a[j] < a[i])
				ds[i] = ds[j] + 1 > ds[i] ? ds[j] + 1 : ds[i];
		}
    	maxsys = maxsys > ds[i] ? maxsys : ds[i];
    }*/
    
    int sys[20] = {0};                                  //贪心求最大系统数 
    for(int i = 1;i <= n;i ++) {
        int minn = maxn; int rom;
		for(int j = 1;j <= maxsys;j ++) 
			if(sys[j] >= a[i] && sys[j] < minn) {
				minn = sys[j]; 
				rom = j;
			}
		if(minn == maxn) {
			maxsys ++; 
			sys[maxsys] = a[i];
		}
		else sys[rom] = a[i];
	}

    cout << maxlen << endl << maxsys << endl;
}
