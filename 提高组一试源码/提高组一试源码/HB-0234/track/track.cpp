#include <bits/stdc++.h>
using namespace std;
//int f[5000][5000];
bool comp(int x,int y){
	return x>y;
}
int n,m,l[1000000],a[1000000],b[1000000];
int main(){

	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n-1;i++){
	cin>>a[i]>>b[i]>>l[i];
}
sort(l+1,l+n+1,comp);
for(int i=1;i<=m;i++){
	cout<<l[i]<<endl;
}
	return 0;
}
