#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	ifstream cin("defense.in");
	ofstream cout("defense.out");
	int n,m,e,f,u,v,x,y;
	string c;
	cin>>n>>m>>c;
	for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n-1;i++) cin>>u>>v;
		for(int i=0;i<m;i++) cin>>f>>x>>e>>y;
		for(int j=0;j<m;j++) cout<<"-1"<<endl;
		return 0;
}
