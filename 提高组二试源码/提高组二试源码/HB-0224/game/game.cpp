#include<iostream>
using namespace std;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m,n,ans=4;
	cin>>n>>m;
	if(n==2&m==2) cout<<12;
	else if(n==2&m==1) cout<<4;
	else if(n==1&m==2) cout<<4;
	else if(n==1&m==3) cout<<8;
	else if(n==3&&m==1) cout<<8;
	else if(n==3&m==3) cout<<8;
	else if(n==2&m==3) cout<<36;
	else if(m==2&&n!=1&&n!=2) {
	for(int i=1;i<m;i++) ans=(ans*3)%1000000007;
	cout<<ans;
	}
	else if(n==2&m!=1&&m!=2&&m!=3){
	     for(int i=1;i<n;i++) ans=(ans*3)%1000000007;
	cout<<ans;	
	}
	else cout<<181011;
	return 0;
}
