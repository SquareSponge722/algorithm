#include <bits/stdc++.h>
using namespace std;
int n,m,a1[5010][5010];
vector<int>a[5010];
bool fw[5010];
void dfs(int i){
	fw[i]=1;
	cout<<i<<" ";
	int maxx=a[i].size();
	for(int j=0;j<maxx;j++){
	if(!fw[a1[i][j]])dfs(a1[i][j]);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		int maxx=a[i].size();
		for(int j=0;j<maxx;j++){
			a1[i][j]=a[i][j];
		}
		if(maxx<=1)continue;
		sort(a1[i],a1[i]+maxx);
	}
	dfs(1);
	return 0;
}
