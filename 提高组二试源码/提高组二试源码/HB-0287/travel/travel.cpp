#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],num,u,vv,sum,bb[10000001];
bool b[10001];
vector <int> v[10001];
void dfs(int k) {
	sum++;
	a[sum]=k;
	for(int i=0; i<v[k].size(); i++) {
		if(!b[v[k][i]]) {
			b[v[k][i]]=1;
			dfs(v[k][i]);
			b[v[k][i]]=0;
		}
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>u>>vv;
		v[u].push_back(vv);
		v[vv].push_back(u);
	}

	for(int i=1; i<=n; i++) {
		int e=0;
		for(int j=0; j<v[i].size(); j++) {
			bb[e]=v[i][j];
			e++;
		}
		sort(bb,bb+e);
		for(int j=0; j<v[i].size(); j++) {
			v[i][j]=bb[j];
		}

	}
	/*
	for(int i=1; i<=n; i++) {
		cout<<"i="<<i<<" ";
		for(int j=0; j<v[i].size(); j++) {
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}*/
	b[1]=1;
	dfs(1);
	for(int i=1; i<=n; i++) cout<<a[i]<<" ";
	return 0;
}
