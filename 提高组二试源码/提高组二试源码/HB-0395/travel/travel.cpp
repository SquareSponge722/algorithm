#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long int mod=1000000007; 
long int v[1000],u[1000];
int main()
{freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{cout<<i;
	if(i!=m) cout<<" ";}
	return 0;
}
	
	
	
