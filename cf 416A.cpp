#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int a, b;

inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
    while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
    return (res * flag);
}

int main() {
    a = read(), b = read();
    int res = 1, flag = 1;
    while(true) {
        if(flag) {
			if(a >= res) a -= res; else break;
		} else { 
			if(b >= res) b -= res; else break;
		} 
        flag ^= 1, res ++;
    }
    if(flag) printf("Vladik\n");
    else printf("Valera\n");
}
