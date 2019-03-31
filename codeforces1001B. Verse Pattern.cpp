#include <cstdio>
#include <string>
#include <iostream> 

int n,pre = 0;
int verse[105];
bool flag;

void findn() {
	    char s[105];
		std :: cin >> s;
		std :: cout << s[0] ;
		int rom = 0;  verse[0] = 0;
        for(int i = 1;i <= pre;i ++) {
        	bool find = 0;
        	for(int j = 0;j < verse[i];j ++) {
                if(s[rom + j] == 'a' || s[rom + j] == 'e' || s[rom + j] == 'i' || s[rom + j] == 'o' || s[rom + j] == 'u' || s[rom + j] == 'y')
                	if(!find) {find = 1; return;}
                    else {flag = 0; return;}
                rom ++;
        	}
        	if(!find) flag = 0;
        }
}

int main() {
	scanf("%d",&n);
	getchar(); 
	while(char c = getchar() != '\n') {
        if(c != ' ') verse[++pre] = c - '0';
	}
	while(n --) {
		flag = 1;
		findn();
		if(!flag) {printf("NO"); return 0;}
	}
	printf("YES");
}
