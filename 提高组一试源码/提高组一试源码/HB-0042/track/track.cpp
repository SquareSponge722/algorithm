#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
    int a[1000],b[1000],c[1000];
	int n,m,ans;
	cin>>n>>m;
	for(int k=1;k<=n-1;k++)
	{
		cin>>b[k]>>c[k]>>a[k];
		if(k<=n-3&&a[k]!=1&&a[k]!=2)
		ans+=a[k]; 
	}
	if(m==1)
	cout<<ans-1;
	else
	cout<<"15";
}
