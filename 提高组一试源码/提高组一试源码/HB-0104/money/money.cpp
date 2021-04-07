//Fei2Xue@Lian$Tian!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int T,n,m;
int a[1005];
int b[1005];
int c[1005];
int sum;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(b,0,sizeof(b));
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==2)
		{
			int t1,t2;
			t1=min(a[1],a[2]);
			t2=max(a[1],a[2]);
			if(t2%t1==0)
				sum=1;
			else
				sum=2;
		}
		else
		{
			for(int i=1;i<=n-1;i++)
				for(int j=i+1;j<=n;j++)
					if(a[i]>a[j])
						swap(a[i],a[j]);
			for(int i=2;i<=n;i++)
				for(int j=1;j<=i-1;j++)
				{
					if(a[i]%a[j]==0)
						b[i]=1;
				}
			for(int i=1;i<=n;i++)
				if(b[i]==1)
					a[i]=0;/*
			for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";
			cout<<endl;*/
			for(int i=1;i<=n;i++)
				if(a[i]!=0)
					sum++;
			if(sum==3)
			{
				int t=1;
				for(int i=1;i<=n;i++)
					if(a[i]!=0)
					{
						c[t]=a[i];
						t++;
					}
				int t1;
				
				t1=c[3]/c[1];
				//cout<<t1<<endl;
				for(int i=1;i<=t1;i++)
					if((c[3]-i*c[1])%c[2]==0)
					{
						sum--;
						break;
					}/*
				for(int i=1;i<=sum;i++)
					cout<<c[i]<<" ";
				cout<<endl;*/
			}
			else if(sum==4)
			{
				int t=1;
				for(int i=1;i<=n;i++)
					if(a[i]!=0)
					{
						c[t]=a[i];
						t++;
					}
				int t1;
				t1=c[3]/c[1];
				for(int i=1;i<=t1;i++)
					if((c[3]-i*c[1])%c[2]==0)
					{
						sum--;
						break;
					}
				if(sum==3)
				{
					int t3=1;
					for(int i=1;i<=n;i++)
						if(a[i]!=0)
						{
							c[t3]=a[i];
							t3++;
						}
					int t4;
					t4=c[3]/c[1];
					for(int i=1;i<=t4;i++)
						if((c[3]-i*c[1])%c[2]==0)
						{
							sum--;
							break;
						}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

