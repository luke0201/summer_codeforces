#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

int main(){
	int n, x; scanf("%d%d", &n, &x);

	map<int, priority_queue<tuple<int, int ,int>>> chk; 
	vector<tuple<int, int, int>>v(n);

	for(int i = 0 ; i < n ; i++){
		int l, r, cost; scanf("%d%d%d", &l, &r, &cost);
		v[i] = make_tuple(r, l, cost);
		
		if(chk.find(r-l+1) == chk.end()){
			priority_queue<tuple<int, int, int>> temp;
			temp.push(make_tuple(-cost, -l, -r));
			chk[r-l+1] = temp;
		}
		else{
			chk[r-l+1].push(make_tuple(-cost, -l, -r));
		}
	}

	sort(v.begin(), v.end());

	int ans = 0x7fffffff;

	for(int i = 0 ; i < n ; i++){
		int target = x - (get<0>(v[i]) - get<1>(v[i]) + 1);
		int end = get<0>(v[i]);
		int cost = get<2>(v[i]);

		for(;;) {
			if(chk.find(target) == chk.end()) break;
			else if(chk[target].empty()) break;
			else{
				if(-get<1>(chk[target].top()) > end){
					ans = min(ans, cost-get<0>(chk[target].top()));
					break;
				}
				else chk[target].pop();
			}
		}
	}

	if(ans == 0x7fffffff) printf("-1");
	else printf("%d", ans);
}

