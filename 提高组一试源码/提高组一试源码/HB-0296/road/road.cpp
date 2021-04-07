#include<bits/stdc++.h>
using namespace std;
int n,d[100010];
long long ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&d[i]);
	for(int i=1; i<=n; i++)if(d[i]>d[i-1])ans+=(long long)(d[i]-d[i-1]);
	printf("%lld",ans);
	return 0;
}
