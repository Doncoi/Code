#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100005
 
int lena, lenb;
char c[MAXN];
int a[MAXN], b[MAXN];

int main() {	
	memset(a, 0, sizeof(a));    memset(b, 0, sizeof(b));
	
	std :: cin >> c;
	lena = strlen(c);  
    for(int i = lena;i >= 1;i --) 
    	a[(lena - i) + 1] = c[i - 1] - '0';
    	
    std :: cin >> c;
	lenb = strlen(c);
    for(int i = lenb;i >= 1;i --) 
    	b[(lenb) - i + 1] = c[i - 1] - '0';

    //for(int i = lena;i >= 1;i --)
    //	std ::cout << a[i];
    //std :: cout << std :: endl;
    //for(int i = lenb;i >= 1;i --) 
    //	std :: cout << b[i];
    
    int len = std :: max(lena, lenb);
    for(int i = 1;i <= len;i ++) {
    	a[i] += b[i];
    	a[i + 1] += a[i] / 10;
    	a[i] %= 10; 
    }
    //std :: cout << lena << std :: endl << a[len + 1] << std :: endl;
    if(a[len + 1]) len ++;
    for(int i = len;i >= 1;i --)
    	std ::cout << a[i];
}
