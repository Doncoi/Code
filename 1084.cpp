#include<iostream>
#include<string>

using namespace std;

int main(){
	int a[1000], m, j = 0, sum = 0;
	char b[1000];
	cin >> b;
	cin >> m;
	if(m >= 10) {	
		for(int i = 0; b[i] != '\0'; ++ i) {
			if(b[i] >= 65)
				a[++ j] = b[i] - 55;
			else 
				a[++ j] = b[i] - 48;
			sum = sum * m + a[j];
		}
	} else {
		for(int i = 0; b[i] != '\0'; ++ i) {
			sum = sum * m + b[i] - 48;	
		}
	}
	cout << sum << endl;
	return 0;	
}
