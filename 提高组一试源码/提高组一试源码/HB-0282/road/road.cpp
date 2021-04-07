#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int read()
{
	int anss=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		anss=anss*10+c-'0';
		c=getchar();
	}
	return  anss;
}
int n;
int a[100010];
long long ans=0;
void solve(int l,int r)
{
	if(l>r)return;
	int temp=1000000007,po;
	for(int i=l;i<=r;i++)
	{
		if(temp>=a[i])
		{
			po=i;
			temp=a[i];
		}
	}
	for(int i=l;i<=r;i++)
	{
		a[i]-=temp;
	}
	ans+=(long long)temp;
	solve(l,po-1);
	solve(po+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	solve(1,n);
	cout<<ans;
	return 0;
}
