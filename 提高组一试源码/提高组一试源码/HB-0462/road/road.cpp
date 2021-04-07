#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, tt, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
	}
	while(1){
		tt = 0;
		for(int i = 0; i < n; i ++){
			if(a[i] == 0){
				tt ++;
			}else{
				ans ++;
				for(;; i ++){
					if(a[i] == 0){
						i --;
						break;
					}
					a[i]--;
				}
			}
		}
		if(tt == n)break;
	}
	printf("%d", ans);
}

