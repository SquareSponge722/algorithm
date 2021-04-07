#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int a[N];
long long ans(0);
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(a[i]>=a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%ld\n",ans);
	return 0;
}
