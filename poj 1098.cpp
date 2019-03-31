#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int p1,p2,p3;
char c[105];
int len;

bool type(char c) {
	int x = c;
	if(x <= 57) return 1;        //数字的返回类型为1
	else return 0;               //字母的返回类型为0
}
 
void Putout(int pos) {           //进行字母补全
    int del = c[pos + 1] - c[pos - 1];
    if(del <= 0) std :: cout << "-";
    else {
    	if(p3 == 1)
    		for(int i = 1;i < del;i ++) {
    			if(p1 == 1) for(int j = 1; j <= p2; j++) {
					char rom = c[pos - 1] + i; 
					std :: cout << rom;
				}
    			else if(p1 == 2) for(int j = 1;j <= p2; j++) {char rom = c[pos - 1] + i - 'a' + 'A'; std :: cout << rom;}
    			else for(int j = 1;j <= p2;j ++) std :: cout << "*";
    		}
    	else 
    		for(int i = del - 1;i >= 1;i --){
    			if(p1 == 1) for(int j = 1; j <= p2; j++) {char rom = c[pos - 1] + i; std :: cout << rom;}
    			else if(p1 == 2) for(int j = 1;j <= p2; j++) {char rom = c[pos - 1] + i - 'a' + 'A'; std :: cout << rom;}
    			else for(int j = 1;j <= p2;j ++) std :: cout << "*";
    		}
    }
}

void putout(int pos) {           //进行数字补全
    int del = c[pos + 1] - c[pos - 1];
    if(del <= 0) std :: cout << "-";
    else {
    	if(p3 == 1)
    		for(int i = 1;i < del;i ++) {
    			if(p1 == 1 || p1 == 2) for(int j = 1; j <= p2; j++) {char rom = c[pos - 1] + i; std :: cout << rom;}
    			else for(int j = 1;j <= p2;j ++) std :: cout << "*";
    		}
    	else 
    		for(int i = del - 1;i >= 1;i --){
    			if(p1 == 1 || p1 == 2) for(int j = 1; j <= p2; j++) {char rom = c[pos - 1] + i; std :: cout << rom;}
    			else for(int j = 1;j <= p2;j ++) std :: cout << "*";
    		}
    }
}

void work(int pos) {
	if(!pos || pos == len) std :: cout << "-";
	else {
		int a =  type(c[pos - 1]); int b = type(c[pos + 1]);
   		if(a != b || c[pos - 1] == '-' || c[pos + 1] == '-') std :: cout << "-";
    	else {
        	if(!a) Putout(pos);
        	else putout(pos);
        }
	} 
    
}

int main() {
	scanf("%d%d%d",&p1,&p2,&p3); 
	std :: cin >> c;
    len = strlen(c);
    for(int i = 0;i < len;i ++) {
    	if(c[i] == '-') work(i);
    	else std :: cout << c[i];
    }
}

