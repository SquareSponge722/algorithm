#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int x,y,i=1;i<=n;i++){
		scanf("%d",&x);
		if (x>y) ans+=x-y;
		y=x;
	}
	printf("%lld\n",ans);
	return 0;
}
