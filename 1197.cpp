#include <iostream>
#include <string>

std :: string k, a;

int main() {
	std :: cin >> k >> a;
	for(int i = 0; i < k.length(); i++)
 		if(k[i] >= 'A' && k[i] <= 'Z') 
 			k[i] = k[i] - 'A' + 'a'; 
	for(int i = 0; i < a.length(); i += k.length())
 		for(int j = 0; j < k.length(); j ++)
  			if(a[i + j] >= 'A' && a[i + j] <= 'Z') 
  				a[i + j] = 'A' + (a[i + j] - 'A' - (k[j] - 'a') + 26) % 26;
  			else a[i + j] = 'a' + (a[i + j] - k[j] + 26) % 26;
 	std :: cout << a;
}