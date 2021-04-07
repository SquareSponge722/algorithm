#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,a[110000],minn;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	minn=a[1];
	ans=a[1];
	for(int i=2;i<=n;++i){
		ans+=max(0,a[i]-minn);
		if(a[i]<minn)minn=min(minn,a[i]);
		else minn=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
