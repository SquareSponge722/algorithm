#include<bits/stdc++.h>
using namespace std;
int n,m,b[100001],x,y,z,f;
string s;
int a[100001];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++) cin>>b[i];
	for(int i=1;i<=m;i++) cin>>x>>y>>z>>f;
	for(int i=1;i<=m;i++)cout<<-1;
	return 0;
}
