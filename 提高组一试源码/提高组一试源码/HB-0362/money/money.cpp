#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,T,a[N];
int num[10000005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		
		int ans=0;
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		if(n==2)
		{
			if((a[1]%a[2]==0) || (a[2]%a[1]==0))
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
			int cnt=0;
			for(int i=0;i<=1000;i++)
				for(int j=0;j<=1000;j++)
				{
					if(a[1]*i+a[2]*j==a[3])
					{
						cnt++;
					}
					else if(a[1]*i+a[3]*j==a[2])
					{
						cnt++;
					}
					else if(a[2]*i+a[3]*j==a[1])
					{
						cnt++;
					}
					if(a[1]*i+a[2]*j>a[3])	
						break;
					if(a[1]*i+a[3]*j>a[2])	
						break;
					if(a[2]*i+a[3]*j>a[1])	
						break;
				}
			if(cnt!=0)
			{
				cout<<cnt+1<<endl;
				continue;
			}
			else
			{
				cout<<n<<endl;
				continue;
			}
		}
		
		if(n==4)
		{
			int cnt=0;
			for(int i=0;i<=500;i++)
				for(int j=0;j<=500;j++)
					for(int k=0;k<=500;k++)
					{
						if(a[1]*i+a[2]*j+a[3]*k==a[4])
						{
							cnt++;
						}
						else if(a[1]*i+a[2]*j+a[4]*k==a[3])
						{
							cnt++;
						}
						else if(a[1]*i+a[3]*j+a[2]*k==a[4])
						{
							cnt++;
						}
						else if(a[1]*i+a[3]*j+a[4]*k==a[2])
						{
							cnt++;
						}
						else if(a[1]*i+a[4]*j+a[2]*k==a[3])
						{
							cnt++;
						}
						else if(a[1]*i+a[4]*j+a[3]*k==a[2])
						{
							cnt++;
						}
						else if(a[2]*i+a[1]*j+a[3]*k==a[4])
						{
							cnt++;
						}
						else if(a[2]*i+a[1]*j+a[4]*k==a[3])
						{
							cnt++;
						}
						else if(a[2]*i+a[3]*j+a[1]*k==a[4])
						{
							cnt++;
						}
						else if(a[2]*i+a[3]*j+a[4]*k>a[1])
						{
							cnt++;
						}
						else if(a[2]*i+a[4]*j+a[1]*k==a[3])
						{
							cnt++;
						}
						else if(a[2]*i+a[4]*j+a[3]*k==a[1])
						{
							cnt++;
						}
						else if(a[3]*i+a[1]*j+a[2]*k==a[4])
						{
							cnt++;
						}
						else if(a[3]*i+a[1]*j+a[4]*k==a[2])
						{
							cnt++;
						}
						else if(a[3]*i+a[2]*j+a[1]*k==a[4])
						{
							cnt++;
						}
						else if(a[3]*i+a[2]*j+a[4]*k==a[1])
						{
							cnt++;
						}
						else if(a[3]*i+a[4]*j+a[1]*k==a[2])
						{
							cnt++;
						}
						else if(a[3]*i+a[4]*j+a[2]*k==a[1])
						{
							cnt++;
						}
						else if(a[4]*i+a[1]*j+a[2]*k==a[3])
						{
							cnt++;
						}
						else if(a[4]*i+a[1]*j+a[3]*k==a[2])
						{
							cnt++;
						}
						else if(a[4]*i+a[2]*j+a[1]*k==a[3])
						{
							cnt++;
						}
						else if(a[4]*i+a[2]*j+a[3]*k==a[1])
						{
							cnt++;
						}
						else if(a[4]*i+a[3]*j+a[1]*k==a[2])
						{
							cnt++;
						}
						else if(a[4]*i+a[3]*j+a[2]*k==a[1])
						{
							cnt++;
						}
						if(cnt==0)
						{
							cout<<n<<endl;
							continue;
						}
						else
						{
							cout<<cnt<<endl;
							continue;
						}
					}
			
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i!=j && a[i]>a[j] && a[i]%a[j]==0)
					ans++;
			}
		if(ans==0)
		{
			cout<<n<<endl;
			continue;
		}
		else
		{
			cout<<ans<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}
