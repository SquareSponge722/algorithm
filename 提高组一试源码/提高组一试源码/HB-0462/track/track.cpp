#include <bits/stdc++.h>
using namespace std;

int n, m;
int l[500005];
int ans[500005];

bool slove(int num){
	int tot;
	for(int i = 0; i < n; i ++){
		ans[tot] += l[i];
		if(ans[tot] + l[i] > num){
			tot ++;
		}
	}
	return tot >= m;
}

int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int a, b, mid, left, r;
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i ++){
		scanf("%d%d%d", &a, &b, &l[i]);
	}
	sort(l, l + n);
	left = 0;
	r = n;
	while(left < r){
		mid = (left + r)/2;
		if(slove(mid)) left = mid;
		else r = mid;
	}
	printf("%d", r);
	return 0;
	int rp;
	rp ++;
}

