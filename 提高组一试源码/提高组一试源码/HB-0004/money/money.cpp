#include<bits/stdc++.h>
using namespace std;
int a[1000],b[500000];
int sum;
void sortn(int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			if(a[k]>a[j])
			k=j;
		}
		swap(a[i],a[k]);
	}
}
void f(int x)
{
	int i,j;
	for(i=1;i<=sum;i++)
	{
		if(b[i])
		b[i+a[x]]++;
	}
	j=sum/a[x];
	for(i=1;i<=j;i++)
	b[i*a[x]]++;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,tt,i,j,n,m;
	cin>>tt;
	for(t=1;t<=tt;t++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		sum=0;
		cin>>n;
		m=n;
		for(i=1;i<=n;i++)
		cin>>a[i];
		sortn(n);
		sum=a[n];
		for(i=1;i<=n;i++)
		{
			if(b[a[i]]==0)
			f(i);
			else
			m--;
		}
		cout<<m<<endl;
	}
	return 0;
}
