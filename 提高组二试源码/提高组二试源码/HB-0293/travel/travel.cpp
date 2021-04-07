#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int m,n,a[5010],b[5010],x[5010],k=1,s[5010],q=5001,t=1;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		q=min(q,a[i]);
		q=min(q,b[i]);
	}
	x[1]=q;
	for (int i=1;i<=m;i++)
	{
		int p=5001;
		if (a[i]==x[k]&&s[b[i]]==0) p=min(p,b[i]);
		else
		{
			if (b[i]==x[k]&&s[a[i]]==0) p=min(p,a[i]);
		}
		if (p!=5001) {x[++k]=p;s[p]++;}
		if (p==5001) 
		{
			t++;
			x[++k]=x[k-t];
		}
		
	}
	for (int i=1;i<=n;i++) cout<<x[i]<<' ';
	return 0;
}

