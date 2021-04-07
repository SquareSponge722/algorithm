#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
	freopen("money.txt","r",stdin);
	freopen("money.txt","w",stdout);
	int a[25001],b[25001],k,i,j;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n,sum=0;cin>>n;
		for(int i=1;i<=n;i++){cin>>a[i];b[i]=1;}
		for(int i=1;i<=n-1;i++)                              
		for(int j=i;j<=n;j++)
		if(a[i]>a[j])swap(a[i],a[j]);
		
		for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
		if(b[i]!=0){if(a[i]%a[j]==0)b[i]=0;}                    
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<=i-1;j++)
		{
			if(b[i]!=0)
			{
				int v;v=a[i]%a[j];
				for(int i=1;i<=n;i++)
				if(b[i]!=0){if(v==a[i])b[i]=0;}
			}
		}
		
		for(int i=1;i<=n;i++)
		sum+=b[i];
		cout<<sum;
	}return 0;
}
