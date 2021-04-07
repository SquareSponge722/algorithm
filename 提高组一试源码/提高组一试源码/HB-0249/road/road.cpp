#include<bits/stdc++.h>
using namespace std;
long long sum;
int n;
int a[100005];
int c[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n+1;i++){
		c[i]=a[i]-a[i-1];
		if(c[i]>0) sum+=c[i];
	}
	printf("%lld\n",sum);
	return 0;
}
