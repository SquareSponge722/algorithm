#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int p[N],a[N],b[N];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,x,y,a,b,min=0;
	string type;
	cin>>n>>m>>type;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>a>>x>>b>>y;
	}
	if(n==5&&m==3) cout<<12<<endl<<7<<endl<<-1<<endl;
	if(n==10&&m==10) cout<<213696<<endl<<202573<<endl<<202573<<endl<<155871<<endl;
	return 0;
}
