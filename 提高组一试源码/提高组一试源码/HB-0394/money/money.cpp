#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define N 100010
using namespace std;
int m,a[N],sum,T,f[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for(int da=1;da<=T;da++)
	{
		cin>>m;
		for(int i=1;i<=m;i++){cin>>a[i];f[a[i]]=1;}
		sort(a+1,a+m+1);
		f[0]=1;
		for(int i=1;i<=25000;i++)
		{
			for(int j=1;j<=m&&a[j]<i;j++)
			{
				if(f[i-a[j]]>0)
				{
					f[i]++;
					break;
				}
			}
		}
		sum=m;
		for(int i=1;i<=m;i++)if(f[a[i]]>1)sum--;
		cout<<sum<<endl;
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
	}
}
