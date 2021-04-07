// NOIP 2018 Day 1 ∆Ã…Ëµ¿¬∑

#include <bits/stdc++.h>
using namespace std;

// !!!!!!!!!!! LOCAL DEFINE
bool __LOCAL = false;
// !!!!!!!!!!! LOCAL DEFINE

int road_hole[100005];
bool is_filled[100005];

int main() {
	// File Manage
	if (__LOCAL == false) {
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		ios::sync_with_stdio(false);
	}
	// File Manage

	int n,chain = 0,start_point,search_start = 0,true_loop,ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> road_hole[i];
	}

	for (true_loop = 0;; true_loop++) {
		bool is_all_clear = true;
		for (int i = search_start; i<n; i++) {
			if (road_hole[i] > 0) {
				if (chain == 0) {
					start_point = i;
				}
				chain++;
				road_hole[i]--;
			} 
			else if (chain != 0) {
				break;
			}
			
		}
		
		if (chain != 0)ans++; 
		chain = 0;

		for (int i = search_start; i < n; i++) {
			if (road_hole[i] > 0) {
				if (i == 0)search_start = 0;
				else search_start = i-1;
				is_all_clear = false;
				break;
			}
		}
		if (is_all_clear) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
