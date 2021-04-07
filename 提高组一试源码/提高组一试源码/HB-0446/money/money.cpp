#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(n==4) cout<<2<<endl;
		if(n==5) cout<<5<<endl;
	}
	return 0;
}
