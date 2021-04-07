#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[6000],b[6000],c[6000];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(c,10000,sizeof(c));
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>b[i];
	for(int i=1;i<=m-1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
				if(b[j]<c[i]) c[i]=b[j];
			}
			else if(b[j]==i)
			{
				if(a[j]<c[i]) c[i]=a[j];
			}
		}
	}
	cout<<"1";
	for(int i=1;i<=m-1;i++)
	cout<<" "<<c[i];
}
