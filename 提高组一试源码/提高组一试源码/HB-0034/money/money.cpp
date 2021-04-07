#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x<y;
}
int hhh(int a,int b)
{
	if(b==0)
		return a;
	else
		return hhh(b,a%b);
}
int a[26500],b[26500];
int t,i,n,j,k,l,c;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		for(j=1;j<=n;j++)
			cin>>a[j];
		sort(a+1,a+n+1,cmp);
		for(j=1;j<=n;j++)
			for(k=j+1;k<=n;k++)
				if(a[k]%a[j]==0&&b[i]==0&&b[j]==0)
					b[k]=1;
				else if(b[j]==0&&b[k]==0&&hhh(a[j],a[k])>1)
				{
					a[j]=a[j]/hhh(a[j],a[k]);
					a[k]=a[k]/hhh(a[j],a[k]);
				}
		for(j=1;j<=n;j++)
			for(k=j+1;k<=n;k++)
				for(l=k+1;l<=n;l++)
					if(b[j]==0&&b[k]==0&&b[l]==0&&a[j]*a[k]-a[j]-a[k]<a[l])
						b[l]=1;
		for(j=1;j<=n;j++)
		{
			if(b[j]==0)
				c++;
			b[j]=0;
		}
		cout<<c<<endl;
		c=0;
	}
	return 0;
}
