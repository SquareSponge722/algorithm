#include<bits/stdc++.h>
using namespace std;
int h[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	h[0]=0;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		if(h[i]>h[i-1])ans=ans+h[i]-h[i-1];
	}
	cout<<ans<<endl;
	return 0;
}
