#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int n,a[100010];
ll ans;
int k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=a[1];
	k=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>k) ans+=a[i]-k;
		k=a[i];
	}
	printf("%lld\n",ans);
	return 0;
} 
