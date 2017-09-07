#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;

	int ans = 0x7fffffff;
	int flag = -1;

	for(int i = 0 ; i <= m - n ; i++){
		int count = 0;
		for(int j = 0 ; j < n ; j++){
			if(a[j] != b[j+i]) count++;
		}
		if(ans > count){
			ans = count; flag = i;
		}
	}

	cout << ans << "\n";

	for(int i = 0 ; i < n ; i++){
		if(a[i] != b[i+flag]) cout << i+1 << " ";
	}
}
