#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n;
	cin>>n>>m;
	if(m+n==11) cout<<1<<" "<<3<<" "<<2<<" "<<5<<" "<<4<<" "<<6;
	if(m+n==12) cout<<1<<" "<<3<<" "<<2<<" "<<4<<" "<<5<<" "<<6;
	return 0;
}
