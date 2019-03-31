#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>

std :: string s;
char variable;
double ans, constant, coefficient;
int res, length, flag, type_flag_con, type_flag_coe, equater_flag;

void init() {
	std :: cin >> s;
	length = s.length();
	res = 0, flag = equater_flag = 1;
	type_flag_con = -1, type_flag_coe = 1;
}

void solve() {
	for(int i = 0; i < length; ++ i) {
		if(s[i] >= '0' && s[i] <= '9') {	
			res = res * 10 + s[i] - '0';
		} else if(s[i] == '-' || s[i] == '+') {
			constant += (res * flag * equater_flag * type_flag_con);
			res = 0, flag = (s[i] == '-' ? -1 : 1);
		} else if(s[i] == '=') {
			constant += (res * flag * equater_flag * type_flag_con);  
			res = 0, flag = 1, equater_flag = -1;
		} else if(s[i] >= 'a' && s[i] <= 'z') {
			variable = s[i];
			coefficient += (res * flag * equater_flag * type_flag_coe);
			res = 0, flag = 1;
		}
	}
	
	ans = (constant == 0 ? 0.000 : (constant / coefficient));
	/*
	std :: cout << "constant : " << constant << std :: endl
				<< "coefficient : " << coefficient << std :: endl
				<< "ans : " << variable << '='
				<< std :: setprecision(4) << ans << std :: endl;
	*/
	printf("%c=%.3lf\n", variable, ans);
}

int main() {
	init();
	solve();
}
