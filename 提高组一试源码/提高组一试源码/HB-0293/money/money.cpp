#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
int n,x,m,a[25010],b[25010],sum;
bool cmp(int s,int t)
{
	return s<t;
}

int main() 
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n;
	while(1)
	{
		sum++;
		cin>>x;
		for (int i=1;i<=x;i++) cin>>a[i];
		sort(a+1,a+1+x,cmp);
		for (int i=x;i>=1;i--)
		{
			int q=0;
			for (int j=1;j<=i-1;j++)
			{
				if (a[i]%a[j]==0&&q==0) 
				{
					q++;
					x--;
					break;
				}
				for (int k=j+1;k<=i-1;k++)
				{
					if (((a[i]-a[j])%a[k]==0&&q==0)||((a[i]-a[k])%a[j]==0&&q==0))
					{
						q++;
						x--;
					}
				}
			}
		}
		b[sum]=x;
		if (sum==n)
		{
			for (int i=1;i<=n;i++) cout<<b[i]<<endl;
			return 0;
		}
	}
	return 0;
}

