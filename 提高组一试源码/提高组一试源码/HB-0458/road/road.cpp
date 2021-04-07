#include<iostream>
using namespace std;
long long a[100005];
long long ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n+1;i++){
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	}
	cout<<ans;
	return 0;
}
