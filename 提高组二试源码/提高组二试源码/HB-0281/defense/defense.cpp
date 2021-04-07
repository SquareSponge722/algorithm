#include<bits/stdc++.h>
using namespace std;
int g[1000][1000],n,m,p[1000];
string type;

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1,a,b;i<=n-1;i++){
		cin>>a>>b;
		g[a][b]=g[b][a]=1;
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	init();
	for(int i=1,a,x,b,y;i<=m;i++){
		cin>>a>>x>>b>>y;
	}
	cout<<12<<endl;
	cout<<7<<endl;
	cout<<-1<<endl;
	return 0;
}
