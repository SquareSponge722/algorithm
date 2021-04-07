#include<bits/stdc++.h>
using namespace std;
int m,n;
int ans;
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n-1; i++) {
		int from,to,cost;
		scanf("%d%d%d",&from,&to,&cost);
		ans+=cost;
	}
	printf("%d",ans);
	return 0;
}
