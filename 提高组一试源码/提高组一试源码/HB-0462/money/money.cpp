#include <bits/stdc++.h>
using namespace std;

int a[105];
int f[105][105];

int dfs(int i, int j, int n){
	if(f[i][j] != -1) return f[i][j];
	if(i == n) return 0;
	for(int k = 0; k <= j/a[i]; k ++){
		f[i][j] = max(f[i][j], dfs(i+1, j - k*a[i], n) + k*a[i]);
	}
	return f[i][j];
}

int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T, ans, n;
	scanf("%d", &T);
	for(int rp = 0; rp < T; rp ++){
		scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		ans = n;
		for(int i = 0; i < n; i ++){
			memset(f, -1, sizeof(f));
			if(dfs(0, a[i], i) == a[i]){
				ans --;
			}
		}
		printf("%d\n", ans);
	}
}

