//B. Text Document Analysis
#include <cstring>
#include <iostream>
#include <algorithm>

int n;
int length = 0,sum = 0;   //����������ʵĳ��Ⱥ������ڵ��ʵĸ���
bool flag_p = 0,flag_w = 0;      //�Ƿ��������ں��Ƿ����ڶ�����
char c;

int main() {
	std :: cin >> n;
    int rom = 0;
	while(n --) {
        std :: cin >> c;     //rom��ʱ��¼���ڶ�ȡ�ĵ��ʳ���
        if(c == '(') {flag_p = 1; flag_w = 0;length = length > rom ? length : rom; rom = 0;}
	
        else if(c == ')' && !flag_w) {flag_p = 0; }
        else if(c == ')' && flag_w) {sum ++; flag_w = 0; flag_p = 0; }

        else {                        //���������ĸ���»���
        	if(flag_p) {              //�����������
                 if(c == '_' && flag_w) {sum ++; flag_w = 0; }
                 else if(c != '_') {flag_w = 1;}
            }

            if(!flag_p) {             //�����������
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
