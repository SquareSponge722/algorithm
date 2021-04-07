#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int m;
int qian[25003];
int wssb[25003];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>m;
	for(int k=0;k<m;k++)
	{
		int n,ss=0;
		cin>>n;
		for(int j=0;j<n;j++)
			cin>>qian[j];
		sort(qian,qian+n);
		for(int i=0;i<n;i++)
			wssb[i]=i*qian[0];
		for(int q=1;q<n;q++)
			for(int i=q*n;i<(q+1)*n;i++)
				wssb[i]=wssb[i-q*n]+qian[q];
		for(int i=n-1;i>=0;i--)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(qian[j]!=0&&qian[i]%qian[j]==0)
				{
					qian[i]=0;
					ss++;
				}
			}
		}
		sort(qian,qian+n);
		if(qian[ss]==0||qian[ss+1]==0)
			cout<<1;
		else
		{
			int pd=qian[ss]*qian[ss+1]-qian[ss]-qian[ss+1];
			for(int i=0;i<n;i++)
				if(qian[i]>pd)
					qian[i]=0;
			while(n==0)
			{
				int i=0,j=0;
				if(qian[i]==wssb[j])
				{
					qian[i]=0;
					i++;
				}
				else
					j++;
					if(i==n)
						break;
			}
			int ans=0;
			for(int i=0;i<n;i++)
			{
				if(qian[i]!=0)
				ans=ans+1;
			}
			cout<<ans;
		}
	}
	return 0;
}
