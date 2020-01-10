/*
//写法1 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define MAXN 1000000 + 5 

using namespace std;

int n, m;
int next[MAXN];
//string s, p;
char s[MAXN], p[MAXN];

//void getNext(string p)
void getNext(char *p)
{
	int pre = 0;
	for(int i = 2; i <= m; ++ i) {
		while(pre > 0 && p[pre + 1] != p[i]) pre = next[pre];
		if(p[pre + 1] == p[i]) ++ pre;
		next[i] = pre;
	}
}

//void KMP(string s, string p)
void KMP(char *s, char *p)
{
	int pre = 0;
	for(int i = 1; i <= n; ++ i) {
		//失配会导致模式串按照next数组不断回溯
		while(pre > 0 && p[pre + 1] != s[i]) pre = next[pre];
		//匹配成功，模式串移动一位
		if(p[pre + 1] == s[i]) ++ pre;
		if(pre == m) {
			cout << i - m + 1 << endl;
			pre = next[pre];
		}
	}
}

int main()
{
	cin >> s + 1 >> p + 1;
	n = strlen(s + 1), m = strlen(p + 1);
	getNext(p);
	KMP(s, p);

	for(int i = 1; i <= m; ++ i)
	{
		cout << next[i] << " ";
	}
}
*/
//写法2 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define MAXN 1000000 + 5 

using namespace std;

int n, m;
int next[MAXN];
string s, p;

void getNext(string p)
//void getNext(char *p)
{
	next[0] = -1;
	int i = 0, j = -1;
	while(i < m)
	{
		if(j == -1 || p[i] == p[j])
			next[++ i] = ++ j;
		else
			j = next[j];
	}
}

void KMP(string s, string p)
//void KMP(char *s, char *p)
{
	int i = 0, j = 0;
	while(i < n)
	{
		if(j == -1 || s[i] == p[j])
			++ i, ++ j;
		else
			j = next[j];
		if(j == m)
		{
			cout << i - m + 1 << endl;
			j = next[j];
		}
	}
}

int main()
{
	cin >> s >> p;
	n = s.length(), m = p.length();
	getNext(p);
	KMP(s, p);

	for(int i = 1; i <= m; ++ i)
	{
		cout << next[i] << " ";
	}
}
