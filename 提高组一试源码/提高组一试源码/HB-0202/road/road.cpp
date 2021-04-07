#include<iostream>
#include<cstdio>
using namespace std;
int a[1000010];
int t=0;
void my(int m,int n)
{
	
	if(m<n)
	{
		int b=0;
		for(int i=m;i<=n;i++)
		if(a[i]==0) b=-1;
		if(b==-1)
		{
			for(int i=m;i<=n;i++)
			{if(a[i]==0)
			{
				if(i==m) my(m+1,n);
			 else if(i==n) my(m,n-1);
			 else 
			 {
				my(m,i-1);
				my(i+1,n);
			 }
			}
			}	
		}
		else
		{
			for(int i=m;i<=n;i++)
			a[i]--;
			t++;
			my(m,n);
		 } 
	}
	while(m==n&&a[m]>0) {a[m]--;t++;
	}
}
int main()
{
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	my(1,m);
	cout<<t;
	return 0;
}

