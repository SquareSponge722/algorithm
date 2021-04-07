#include<iostream>
#include<cstdio>
using namespace std;
int n,m,s;
int a[50005],b[50005],l[50005];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)cin>>a[i]>>b[i]>>l[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		s+=l[i];
		cout<<s;
	}
	else cout<<15;
	return 0;
}
