#include<bits/stdc++.h>
using namespace std;
int n,a;
int d[100005];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	} 
	for(int i=1;i<=n;i++){
		a=d[i]-d[i-1];
		if(a>0) ans+=a;
	}
	printf("%lld\n",ans);
	return 0;
}
