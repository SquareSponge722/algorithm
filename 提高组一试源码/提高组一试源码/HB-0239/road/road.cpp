#include<cstdio>
#include<iostream>
using namespace std;
int n;
int a[100005];
long long ans=0;
int bj=0;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>bj){
			ans+=a[i]-bj;
		}
		bj=a[i];
	}
	printf("%lld",ans);
	return 0;
}
