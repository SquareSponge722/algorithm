#include<bits/stdc++.h>
using namespace std;
int n,m,u,v;
int a[5001],b[5001],d[5001];
bool c[5001]={0};
int search(int);
int print();
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		c[u]=1;c[v]=1;
	}
	int i=1;
	while(i<=n)
	{
			d[i]=i;
			if(!c[i]) swap(d[i],d[i+1]);
			i++;
	}
}
	int search(int m)
	{
		for(int i=1;i<=m;i++)
		if(!c[i])
		{
			search(1);
			d[i]=i;
			c[i]=1;
			if(i==m) cout<<d[i]<<endl;
			else search(m+1);
			c[i]=0;
		}
	}
	int print(int n)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<d[i]<<endl;
		}
		return 0;
	}
