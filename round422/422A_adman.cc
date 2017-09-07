#include <iostream>
#include <algorithm>

using namespace std;

long long fact[13]={1};

int main(){
	long long a, b; cin >> a >> b;
	for(int i = 1 ; i <= 12 ; i++) fact[i] = fact[i-1]*i;

	cout << fact[min(a,b)];
	
}
