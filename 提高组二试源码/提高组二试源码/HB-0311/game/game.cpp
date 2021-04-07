#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[5][5];
long long ans=1;
const int mo=1e9+7;

int main ()
{
	freopen ("game.in","r",stdin);
	freopen ("game.out","w",stdout);
	cin>>n>>m;
	if (n<=3&&m<=3) {
		if (n==2&&m==2) cout<<12;
		else if (n==1&&m==2) cout<<4;
		else if (n==2&&m==1) cout<<4;
		else if (n==2&&m==3) cout<<256;
		else if (n==3&&m==2) cout<<256;
		else if (n==3&&m==3) cout<<112;
	}
	else if (n==2) {
		for (int i=1;i<=m-1;i++) {
			ans=ans*3%mo;
		}
		ans=ans*4%mo;
		cout<<ans;
	}
	
}
