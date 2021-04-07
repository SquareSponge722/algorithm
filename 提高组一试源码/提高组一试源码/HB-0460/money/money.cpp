#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n,a[1001],m,k;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;k=n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		
	//	if((n<=5)&&(n>=2)){

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	
	
	for(int i=n;i>=2;i--)
	{      m=a[i];
		for(int j=n-1;j>=1;j--)
		{
			m=m%a[j];
		}
		if(m==0)
		{
			k--;
		}
	}
cout<<k<<endl;	
  // }   
}
return 0;
}//30'·½°¸ 
