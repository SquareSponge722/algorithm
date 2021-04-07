#include <cstdio>
#include <algorithm>
#include <cstring>

int n, arr[102];
bool dp[102][25009];

void solve() {
	std::memset(dp, 0, sizeof(dp));
	dp[0][0]=1; int mx=0;
	scanf("%d", &n); int ans=n;
	for (int i=1;i<=n;++i) {
		scanf("%d", &arr[i]);
		mx=std::max(mx, arr[i]);
	}std::sort(arr+1, arr+n+1);
	for (int i=0;i<=n;++i) {
		for (int j=0;j<=mx;++j) {
			if (dp[i][j]) {
				dp[i+1][j]=1;
				if (j+arr[i]<=mx) dp[i][j+arr[i]]=1;
			}
		}
	} for (int i=1;i<=n;++i) {
		if (dp[i-1][arr[i]]) ans--;
	}printf("%d\n", ans);
}
	

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out", "w",stdout);
	int t;
	scanf("%d", &t);
	while (t--)solve();
	return 0;
}
