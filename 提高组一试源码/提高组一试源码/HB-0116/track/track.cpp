#include<bits/stdc++.h>
using namespace std;
int m,n;
int lk[50000],cntl[50000];
int a[50000],b[50000],l[50000];
int exch(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
	return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	    cin>>a[i]>>b[i]>>l[i];
	if(m==n-1)
	{
		sort(l,l+(n));
		for(int i=0;i<n;i++)
		{
			if(l[i]<l[0]+l[1])
			{
				cout<<l[i];
				return 0;
			}
		}
	}
	else if(m==1)
	{
		for(int i=0;i<n;i++)
		    if(a[i]>b[i]) exch(a[i],b[i]);
		for(int i=0;i<n;i++)
		{
			cntl[a[i]++];
			cntl[b[i]++];
		}
		for(int i=0;i<n+1;i++)
		{
			int max=0;
			for(int j=0;j<n+1;j++)
			{
				if(a[j]==i||b[j]==i)
				{
					if(a[j]==i)
					    if(l[j]+lk[b[j]]>max) max=l[j]+lk[b[j]];
					if(b[j]==i)
					    if(l[j]+lk[a[j]]>max) max=l[j]+lk[a[j]];
				}
			}
		}
		int maxn=0;
		for(int i=0;i<n+1;i++)
		    if(lk[i]>maxn) maxn=lk[i];
		cout<<maxn;
	}
	return 0;
}
