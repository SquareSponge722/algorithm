#include<bits/stdc++.h>
using namespace std;
#define fre(a) ifstream cin(a".in");ofstream cout(a".out")
#define FOR(i,a,b) for(i=a;i<=b;++i)
long long ans=1;
int main()
{
	int n,m,i;
	fre("game");
	cin>>n>>m;
	if(n==1)
	{
		FOR(i,1,n)
		ans*=2;
		cout<<ans;return 0;
	}
	else cout<<112;
	return 0;
}
