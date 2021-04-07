#include<bits/stdc++.h>
using namespace std;
int n;
int d[100001];
int ans,mid;
long long sum;
void dfs(int l, int r) {
	if(l>r)return ;
	ans=100001;
	for(int i=l; i<=r; i++) {
		if(ans>d[i]) {
			ans=d[i];
			mid=i;
		}
	}
	for(int i=l; i<=r; i++){
		d[i]-=ans;
	}
	sum+=ans;
	dfs(l, mid-1);
	dfs(mid+1, r);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&d[i]);
	}
	dfs(1,n);
	printf("%lld",sum);
}
