//B. Passwords
#include <cstdio>
#include <cstring>
#include <iostream>

int n,k;
int soc[105];  //sum of every kind of length's code
int maxn = 1,minn;
char c[105];

int main() {
	scanf("%d%d",&n,&k);
    while(n --) {
        std :: cin >> c;
        soc[strlen(c)] ++;
    }
    std :: cin >> c; int len = strlen(c);
    for(int i = 1;i < len;i ++) maxn += soc[i];
    minn = (maxn + soc[len] - 1)/k;
    minn *= 5;
    minn += maxn + soc[len] - 1;
    printf("%d %d",maxn,minn);
    return 0;
}
