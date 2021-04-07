#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXM 25000
#define MAXN 100
bool f[MAXN];
int a[MAXN],m[MAXN],n,k,d;
using namespace std;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>d;
	for(int l=1;l<=d;l++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			{
				f[0]=1;
				for(int j=a[i];j<=MAXN;j++)
				{
					f[j]=f[j-a[i]]||f[j];
				}
				for(int j=i+1;j<=n;j++)
				{
					if(f[a[j]]==1)
					{
						a[j]=0;
					}
				}
			}
			for(int j=1;j<=MAXN;j++)
					f[j]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
				m[k]++;
		}
		k++;
	}
	for(int i=0;i<=k-1;i++)
		cout<<m[i]<<endl;
	return 0;
}
