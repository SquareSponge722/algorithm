#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long ans=1;
	int m,n;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		ans=ans*2%int (1e9+7);
	cout<<ans-5;
	return 0;
}

