#include<bits/stdc++.h>
using namespace std;

#define read(x) scanf("%d",&x)
#define maxn 100000

int n;
int a[maxn+5];

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	
	int ans=0;
	for(int i=1;i<=n;i++) {
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	
	printf("%d",ans);
	
	return 0;
}
