#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int d[N],n;
long long ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	d[0] = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if (d[i]>d[i-1]) ans += d[i]-d[i-1];
	}
	printf("%lld\n",ans);
	return 0;
}
