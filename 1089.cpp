#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN
#define MAXM
#define abs(x) (x > 0 ? x : x * -1)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

const std :: string tdis = "Today is ";
const std :: string w[8] = {" ", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int n, m, p;
int crimer, ncnt;
int tf[30], idea[30][30], dayidea[30];
std :: string name[30];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9'&&ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

void check() {
	int g[30] = {0}, day[8] = {0};
	for(int i = 1; i <= m; ++ i) {
		if(dayidea[i] != 0) {
			if(day[dayidea[i]] == 0 || day[dayidea[i]] == tf[i]) {	
				day[dayidea[i]] = tf[i];
			} else {
				return;
			}
		}
	}

	int dcnt = 0;
	for(int i = 1; i <= 7; ++ i) {
		if(day[i] == 1) dcnt ++;
	} 
	if(dcnt > 1) {
		return;
	}
	for(int i = 1; i <= m; ++ i) {
		for(int j = 1; j <= m; ++ i) {
			int a = idea[i][j] * tf[i];
			int tmp = idea[i][j] * tf[i];
			if(tmp != 0) {
				if(g[j] == 0 || g[j] == tmp) {
					g[j] = a;
				} else {
					return;
				}
			}
		}
	}

	int gua = 0;
	for(int i = 1; i <= m; ++ i) {
		if(g[i] == 1) {
			if(gua == 0) {
				gua = i;
			} else {
				std :: cout << "Cannot Deterrmine";
				exit(0);
			}
		}
	}

	if(crimer = 0 || crimer == gua) {
		crimer = gua;
	} else {
		std :: cout << "Cannot Deterrmine";
		exit(0);
	}
}


void DFS(int x) {
	if(x > m) {
		check();
	} else{
		if(ncnt < n) {
			++ ncnt, tf[x] = -1;
			DFS(x + 1);
			-- ncnt, tf[x] = 0;
		}

		if(n - ncnt <= m - x) {
			tf[x] = 1;
			DFS(x + 1);
			tf[x] = 0;
		}
	}
} 

void analysis(std :: string st) {
	int speakerno = 0, k = 0;
	for(int i = 1; i <= m; ++ i) {
		if(st.find(name[i] + ":", k) == 0) {
			speakerno = i;
			k += name[i].length() + 2;
		}
	}

	if(speakerno == 0) return;

	for(int i = 1; i <= m; ++ i) {
		if( st.substr(k).find(name[i] + " is guilty.") == 0 && 
			st.substr(k).length() - (name[i] + " is guilty.").length() <= 1) {
			if(idea[speakerno][i] == 0 || idea[speakerno][i] == 1) {
				idea[speakerno][i] = 1;
			} else {
				std :: cout << "Impossible";
				exit(0);
			}
			return;
		}
	}

	for(int i = 1; i <= m; ++ i) {
		if( st.substr(k).find(name[i] + " is not guilty.") == 0 && 
			st.substr(k).length() - (name[i] + " is not guilty.").length() <= 1) {
			if(idea[speakerno][i] == 0 || idea[speakerno][i] == -1) {
				idea[speakerno][i] = -1;
			} else {
				std :: cout << "Impossible";
				exit(0);
			}
			return;
		}
	}

	for(int i = 1; i <= m; ++ i) {
		if( st.substr(k).find("I am guilty.") == 0 && 
			st.substr(k).length() - 12 <= 1) {
			if(idea[speakerno][i] == 0 || idea[speakerno][i] == 1) {
				idea[speakerno][i] = 1;
			} else {
				std :: cout << "Impossible";
				exit(0);
			}
			return;
		}
	}

	for(int i = 1; i <= m; ++ i) {
		if( st.substr(k).find("I am not guilty.") == 0 && 
			st.substr(k).length() - 16 <= 1) {
			if(idea[speakerno][i] == 0 || idea[speakerno][i] == -1) {
				idea[speakerno][i] = -1;
			} else {
				std :: cout << "Impossible";
				exit(0);
			}
			return;
		}
	}
}

void init() {
	m = read(), n = read(), p = read();
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> name[i];
	}
}

void solve() {
	std :: string st;
	getline(std :: cin, st);
	for(int i = 1; i <= p; ++ i) {
		getline(std :: cin, st);
		analysis(st);
	}
	DFS(1);
	if(crimer == 0) {
		std :: cout << "Impossible";
	} else {
		std :: cout << name[crimer];
	} 
}

int main() {
	init();
	solve();
}
