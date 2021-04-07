#include<bits/stdc++.h>
using namespace std;
const int maxn=1006;
int n,d[maxn],ans,b[maxn]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	int mind;
	for(int i=1; i<=n; i++) {
		scanf("%d",&d[i]);
		mind=d[1];
		mind=min(mind,d[i]);
	}
	ans+=mind;	
	for(int i=1; i<=n; i++) d[i]-=mind;
	
	int j;
	for(int i=1; i<=n; i++){
		j=1;
		if(!d[i]) b[j++]=i;}
	ans=ans+4*j+1;
	cout<<ans<<endl;
	return 0;
}
