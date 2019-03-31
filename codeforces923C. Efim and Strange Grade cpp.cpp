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
    		c[i - 1] = rom + '0';    //��������
    		judge = 1; n = i - 1; t--;   //�������ҵ������³���,���û����һ
    		break;
    	}
    	if(judge) break;             //���Ը��¹�������Ҫ���¿�ʼ����
    }
    if(!judge || !t) return;        //����Ѿ��Ҳ�������������������ֻ����Ѿ��ľ��˻��ᣬ�򷵻�
    else work();                     //�����������
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


