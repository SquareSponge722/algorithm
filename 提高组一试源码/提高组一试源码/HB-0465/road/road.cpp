#include <cstdio>

int arr[100005],n,ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d", &arr[i]);
	arr[0]=0; ans=0;
	for (int i=1;i<=n;++i) {
		ans+=arr[i]>arr[i-1]?arr[i]-arr[i-1]:0;
	}printf("%d", ans);
	return 0;
}
