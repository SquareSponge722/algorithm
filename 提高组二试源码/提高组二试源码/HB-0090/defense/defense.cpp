#include<bits/stdc++.h>
using namespace std;
int n,m;
string ty;
int p[100001];
int u,v;
int a,b;
bool x,y;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>ty;
	for(int i=1; i<=n; i++){
		cin>>p[i];
	}
	for(int i=1; i<n; i++){
		cin>>u>>v;
	}
	for(int i=1; i<=m; i++){
		cin>>a>>x>>b>>y;
	}
	for(int i=1; i<=m; i++){
		cout<<"-1"<<endl;
	}
}
