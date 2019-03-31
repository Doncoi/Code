//C. Efim and Strange Grade
#include <cstdio>

int n,t;
int x;
char c[200005];

inline void work() {
	bool judge = 0;
    for(int i = x + 2;i <= n;i ++) {
    	if((c[i] - '0') >= 5) {
    		int rom = (c[i - 1] - '0') + 1;
    		c[i - 1] = rom + '0';    //四舍五入
    		judge = 1; n = i - 1; t--;   //表明已找到，更新长度,可用机会减一
    		break;
    	}
    	if(judge) break;             //若以更新过，则需要重新开始搜索
    }
    if(!judge || !t) return;        //如果已经找不到可以四舍五入的数字或者已经耗尽了机会，则返回
    else work();                     //否则继续更新
}

int main() {
	scanf("%d%d",&n,&t);
    for(int i = 1;i <= n;i ++) {
    	char d = getchar();
    	if (d == '.') x = i;
    	c[i] = d;
    }
    
    work();
    if(c[x + 1] - '0' >= 5 && t) {
    	int rom = (c[x - 1] - '0') +1;
    	c[x - 1] = rom  + '0';
    	for(int i = 1; i < x; i ++) printf("%c",c[i]);
    } 
    else for(int i = 1;i <= n;i ++) printf("%c",c[i]);
    return 0;
}


