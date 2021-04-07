#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int a[maxn];
int b[maxn];
int n;
long long kokona;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i]-a[i-1];
	}
	for (int i=1;i<=n;i++){
		if(b[i]>0)kokona=kokona+b[i];
	}
	printf("%lld\n",kokona);
	return 0;
}
