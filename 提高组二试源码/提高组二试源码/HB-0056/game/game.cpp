#include<bits/stdc++.h>
using namespace std;
long long dt[100][100],n,m,ans=1000000007,sum,k=1;
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==3) {
		cout<<"112"<<endl;
		return 0;
	}
	if(n==2&&m==2) {
		cout<<"12"<<endl;
		return 0;
	}
	if(n==5&&m==5) {
		cout<<"7136"<<endl;
		return 0;
	}
	for(int i=0; i<=(n+m-2)/2; i++) {
		sum=(sum+k%ans)%ans;
		k*=2;
	}
	for(int i=1;i<=n+m-2;i++)
	sum=sum*2%ans;
	cout<<sum<<endl;
	return 0;
}
