#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int T,n,a[100001],f[100001],sum=1,sum1,b[100001],ccc=0,sum2=1;
void ddd(int x)
{
	int dcd=0;
	if(x==sum)return;
	for(int i=1;i<=20;i++)
	{
		if(f[a[x]-i*a[x-1]]!=1)dcd=1;
		
	}
	if(dcd==1)
	{
		sum2++;
		for(int i=1;i<=20;i++)
		{
			f[a[x-1]*i]=1;
		}
		ddd(x+1);
		return;
	}
}
void dfs(int x)
{
	x=a[x];
	int bb=0;
	for(int i=x+1;i<=n;i++)
	{
		if(f[a[i]%x]!=1)
		{
			sum++;
			b[sum]=a[i];
			f[a[i]]=1;
			dfs(i);
		}
	}
	return;
}

int main()
 {
 	freopen("money.in","r",stdin);
 	freopen("money.out","w",stdout);
 	cin>>T;
 	for(int t=1;t<=T;t++)
 	{
 		cin>>n;
 		for(int i=1;i<=n;i++)
 		{
 			cin>>a[i];
 			if(a[i]==1)
 			{
 				ccc=1;
			}
		}
		if(ccc==1)
		{
			ccc=0;
			cout<<1<<endl;
			continue;
		}
		sort(a+1,a+1+n);
		if(n==2)
		{
			if(a[2]%a[1]==0)
			{
				cout<<1<<endl;
				continue;
				
			}
			else
			{
				cout<<2<<endl;
				continue;
			}
		}
		if(n==3)
		{
			if(a[2]%a[1]==0)
			{
				if(a[3]%a[1]==0)
				{
					cout<<1<<endl;
					continue;
				}
				else
				{
					cout<<2<<endl;
					continue;
				}
			}
			else
			{
				for(int i=1;;i++)
				{
					if((a[3]-a[1]*i)%a[2]==0)
					{
						cout<<2<<endl;
						break;
					}
					if(a[1]*i>a[3])
					{
						cout<<3<<endl;
						break;
					}
				}
				continue;
			}
		}
		sum2=1;
		f[0]=1;
		sum=1;
		dfs(1);
		for(int i=1;i<=40;i++)
	{
		f[a[1]*i]=1;
	}
		ddd(3);
		cout<<sum2<<endl;
		
	}
	return 0;
 }
