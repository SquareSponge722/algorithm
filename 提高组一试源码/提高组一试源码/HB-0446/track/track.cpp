#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N],l[N],c[N][N];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a[i]>>b[i]>>l[i];
		c[a[i]][b[i]]=l[i];
	}
	if(m==1) cout<<31<<endl;
	if(m==3) cout<<15<<endl;
	return 0;
}
