#include<bits/stdc++.h>
using namespace std;
int n,l,r,t=1;
long long int m=100001;
int d[10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		if(d[i]<m) m=d[i];
		t+=m;
		d[i]-=m;
		if(d[i]==0) break;
		m=d[i-1];
	}
	int i;
	while(d[i]!=0) 
		{
			if(d[i]<m) m=d[i];
		d[i]-=m;
		if(d[i]==0) break;
	    }
		t+=m;
	cout<<t<<endl;
	return 0;
}
