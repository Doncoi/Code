#include <stack>   
#include <cstdio>  
#include <vector>  
#include <cstring>   
#include <cstdlib>  
#include <iostream>
#include <algorithm>
#define MAXN 200005
#define unlong unsigned long long
#define pairnode std :: pair<unlong, int>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)  

int n;
char optition[10];
unlong power[MAXN];
pairnode node[MAXN];
std :: stack< std :: vector<pairnode> > s;

inline void Push() {
	std :: vector<pairnode> tmp;
	tmp.clear(), s.push(tmp);
}

inline void Dup() {
	s.push(s.top());
}

inline void Union() {
	std :: vector<pairnode> a = s.top();  s.pop(); 
	std :: vector<pairnode> b = s.top();  s.pop();
	int preA = 0, preB = 0, cnt = 0;

	while(preA < a.size() || preB < b.size()) {
		if(preA == a.size())           node[++ cnt] = b[preB ++];
		else if(preB == b.size())      node[++ cnt] = a[preA ++];
		else {
			if(a[preA] < b[preB])      node[++ cnt] = a[preA ++];
			else if(a[preA] > b[preB]) node[++ cnt] = b[preB ++];
			else 					   node[++ cnt] = a[preA ++], ++ preB;
		}
	}

	std :: vector<pairnode> c;
	if(cnt) {
		c.clear();
		for(int  i = 1; i <= cnt; ++ i)
			c.push_back(node[i]);	
	}
	s.push(c);
} 

inline void Intersect() {
    std :: vector<pairnode> a = s.top();  s.pop(); 
	std :: vector<pairnode> b = s.top();  s.pop();
	int preA = 0, preB = 0, cnt = 0; 

	while(preA < a.size() || preB < b.size()) {
		if(preA == a.size())                ++ preB;
		else if(preB == b.size())           ++ preA;
		else {
			if(a[preA] < b[preB])           ++ preA;
			else if(a[preA] > b[preB])      ++ preB;
			else node[++ cnt] = a[preA ++], ++ preB;
		}
	}

	std :: vector<pairnode> c;
	if(cnt) {
		c.clear(); node[cnt + 1].first = -1;
		for(int  i = 1; i <= cnt; ++ i)
			c.push_back(node[i]);	
	}
	s.push(c);
}

inline void Add() {
    std :: vector<pairnode> a = s.top();  s.pop(); 
	std :: vector<pairnode> b = s.top();  s.pop();
	
	unlong hashSize = 5, ll = 2;
    for(int i = 0; i < a.size(); ++ i) {
    	hashSize = hashSize * power[a[i].second] + a[i].first;
		ll = (ll + a[i].second) % 199193;    	
    }
	hashSize= hashSize * power[a.size()] + 7;  
    a.clear();  a.push_back(std :: make_pair(hashSize, ll));  

	int preA = 0, preB = 0, cnt = 0; 
    while(preA < a.size() || preB < b.size()) {
    	if(preA == a.size()) 		   node[++ cnt] = b[preB ++];     
    	else if(preB == b.size()) 	   node[++ cnt] = a[preA ++];
		else {
    		if(a[preA] < b[preB])      node[++ cnt] = a[preA ++];
    		else if(a[preA] > b[preB]) node[++ cnt] = b[preB ++];
    		else 					   node[++ cnt] = a[preA ++], preB ++;
    	}
    }

    std :: vector<pairnode> c;
	c.clear(); c.push_back(node[1]);
	for(int  i = 2; i <= cnt; ++ i)
		c.push_back(node[i]);	
	s.push(c);        
}

inline void init() {
	scanf("%d", &n);  power[0] = 1;
	for(int i = 1; i <= 199900; ++ i) 
		power[i] = power[i - 1] * 107;
}

inline void solve() {
	while(n --) {
		std :: cin >> optition;
		if(optition[0] == 'P') Push();
		if(optition[0] == 'D') Dup();
		if(optition[0] == 'U') Union();
		if(optition[0] == 'I') Intersect();
		if(optition[0] == 'A') Add();
		printf("%d\n", s.top().size());
	}
}

int main() {
	init();
	solve();
}
