#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,h[100001],a[100001],b[100001],c[10001],sum;
string type;
struct request
{
	int a,b,x,y;
}r[100001];
int main() 
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	for (int i=1;i<=n;i++) cin>>h[i];
	for (int i=1;i<n;i++) cin>>a[i]>>b[i];
	for (int i=1;i<=m;i++) cin>>r[i].a>>r[i].x>>r[i].b>>r[i].y;
	for (int i=1;i<=m;i++)
	{
		if (r[i].x==0) 
		{
			for (int j=1;j<n;j++)
			{
				if (a[i]==r[i].x&&c[b[i]]==0) c[b[i]]==h[i];
				if (b[i]==r[i].x&&c[a[i]]==0) c[a[i]]==h[i];
			}
		}
		if (r[i].x==1) c[r[i].a]+=h[r[i].a];
		if (r[i].y==0)
		{
			for (int j=1;j<n;j++)
			{
				if (a[i]==r[i].y&&c[b[i]]==0) c[b[i]]==h[i];
				if (b[i]==r[i].y&&c[a[i]]==0) c[a[i]]==h[i];
			}
		}
		if (r[i].y==1) c[r[i].b]+=h[r[i].a];
		for (int i=1;i<=n;i++)
		{
			sum+=c[i];
			if (c[a[i]]==0&&c[b[i]]==0&&i!=n) cout<<"-1"<<endl;
			else cout<<"-1"<<endl;
			
		}
		
	}
	return 0;
}
