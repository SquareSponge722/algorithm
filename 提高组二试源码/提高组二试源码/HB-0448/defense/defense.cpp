#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,w[100010],ans,sum;
vector<ll> a[100010];
ll a1,b1,a2,b2;
char c1,c2;
bool fw[100010];
bool check() {
	if(b1==1||b2==1)return true;
	int maxx=a[a1].size();
	for(int i=0; i<maxx; i++) {
		if(a[a1][i]==a2)return false;
	}
	return true;
}
void dfs(ll i,ll x,ll now) {
	if(x==1)sum+=w[i];
	if(now==n) {
		ans=min(ans,sum);
		sum-=w[i];
		return;
	}
	if(sum<=ans) {
		int maxx=a[i].size();
		for(int j=0; j<maxx; j++) {
			if(a[i][j]==a2) {
				fw[a2]=1;
				dfs(a2,b2,now+1);
				fw[a2]=0;
			}
			else if(!fw[a[i][j]]) {
				fw[a[i][j]]=1;
				dfs(a[i][j],1,now+1);
				if(x!=0)dfs(a[i][j],0,now+1);
				fw[a[i][j]]=0;
			}
		}
	}

	if(x==1)sum-=w[i];
	return;
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>c1>>c2;
	for(int i=1; i<=n; i++) {
		cin>>w[i];
	}
	for(int i=1; i<n; i++) {
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1; i<=m; i++) {
		cin>>a1>>b1>>a2>>b2;
		if(!check())cout<<-1<<endl;
		else {
			ans=999999999,sum=0,fw[a1]=1;
			dfs(a1,b1,1);
			fw[a1]=0;
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/

