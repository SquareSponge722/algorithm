#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn],n,minn;
long long ans;
bool ok=0,ok2;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	if(n<=1000) {
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		ok=1;
		while(ok) {
			ok=0;
			ok2=0;
			for(int i=1; i<=n+1; i++) {
				if(a[i]) {
					a[i]--;
					ok=1;
					ok2=1;
				} else if(ok2) {
					ans++;
					ok2=0;
				}
			}
		}
		printf("%lld",ans);
	} else {
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=2;i<n;i++){
			if((a[i]>a[i-1]&&a[i]>=a[i+1])||(a[i]>=a[i-1]&&a[i]>a[i+1]))ans-=a[i];
			if((a[i]<a[i-1]&&a[i]<=a[i+1])||(a[i]<=a[i-1]&&a[i]<a[i+1]))ans+=a[i];
		}
		
		printf("%lld",ans);
	}
}
/*
13
4 5 4 3 2 3 4 5 4 3 3 4 3
*/
