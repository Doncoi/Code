//B. Text Document Analysis
#include <cstring>
#include <iostream>
#include <algorithm>

int n;
int length = 0,sum = 0;   //括号外最长单词的长度和括号内单词的个数
bool flag_p = 0,flag_w = 0;      //是否在括号内和是否正在读单词
char c;

int main() {
	std :: cin >> n;
    int rom = 0;
	while(n --) {
        std :: cin >> c;     //rom临时记录正在读取的单词长度
        if(c == '(') {flag_p = 1; flag_w = 0;length = length > rom ? length : rom; rom = 0;}
	
        else if(c == ')' && !flag_w) {flag_p = 0; }
        else if(c == ')' && flag_w) {sum ++; flag_w = 0; flag_p = 0; }

        else {                        //如果读到字母和下划线
        	if(flag_p) {              //如果在括号内
                 if(c == '_' && flag_w) {sum ++; flag_w = 0; }
                 else if(c != '_') {flag_w = 1;}
            }

            if(!flag_p) {             //如果在括号外
                 if(c == '_' && flag_w) {flag_w = 0; length = length > rom ? length : rom; rom = 0;}
                 else if(c == '_' && !flag_w) {continue;}
                 else if(c != '_'){
                      flag_w = 1;
                      rom ++; 
                 }
            }
        }

	}

    std :: cout << length << " " << sum;
}
