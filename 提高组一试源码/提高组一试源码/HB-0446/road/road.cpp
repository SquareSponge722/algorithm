#include<bits/stdc++.h>
using namespace std;
int d[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,ans=0,x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int a=1,j;a<=n;){
		if(d[a]!=0){
			for(int r=1;r<=n;r++){
				if(d[r]!=0) j=a;
			}
			for(;j<=n;j++){
				if(d[j]>0) d[j]-=1;
				else break;
			}
			ans++;
		}
		else a++;
	}
	cout<<ans<<endl;
	return 0;
}
