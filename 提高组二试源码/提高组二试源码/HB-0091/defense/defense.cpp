#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
string ljwwx;
int n,m,a,b,p[110000];
int x,y;
long long ans;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>ljwwx;
	for(int i=1;i<=n;i++)
	cin>>p[i];
	for(int i=1;i<n;i++)
	cin>>x>>y;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>x>>b>>y;
		if(a>b)
		{
			swap(a,b);
			swap(x,y);
		}
		ans=0;
		if(x==0&&y==0)
		{
			if(a+1==b)
			{
				cout<<-1<<endl;
				continue;
			}
			for(int i=a-1;i>=1;i-=2)
			ans+=p[i];
			for(int i=a+1;i<b-1;i+=2)
			ans+=p[i];
			ans+=p[b-1];
			for(int i=b+1;i<=n;i+=2)
			ans+=p[i];
		}
		else if(x==0&&y==1)
		{
			if(a%2!=b%2)
			{
				for(int i=a-1;i>=1;i-=2)
				ans+=p[i];
				for(int i=a+1;i<=n;i+=2)
				ans+=p[i];
			}
			else
			{
				for(int i=a-1;i>=1;i-=2)
				ans+=p[i];
				for(int i=a+1;i<=b-2;i+=2)
				ans+=p[i];
				ans+=min(p[b-1],p[b-2]);
				for(int i=b;i<=n;i+=2)
				ans+=p[i];
			}
		}
		else if(x==1&&y==0)
		{
			if(a%2!=b%2)
			{
				for(int i=b-1;i>=1;i-=2)
				ans+=p[i];
				for(int i=b+1;i<=n;i+=2)
				ans+=p[i];
			}
			else
			{
				for(int i=b+1;i<=n;i+=2)
				ans+=p[i];
				for(int i=b-1;i>a+2;i-=2)
				ans+=p[i];
				ans+=min(p[a+1],p[a+2]);
				for(int i=a;i>=1;i-=2)
				ans+=p[i];
			}
		}
		else 
		{
			if(a%2==b%2)
			{
				for(int i=b;i>=1;i-=2)
				ans+=p[i];
				for(int i=b;i<=n;i+=2)
				ans+=p[i];
			}
			else 
			{
				for(int i=b;i<=n;i+=2)
				ans+=p[i];
				for(int i=a;i>=1;i-=2)
				ans+=p[i];
				long long lzy,hyf;
				lzy=0;
				hyf=0;
				for(int i=a+2;i<=b-3;i++)
				lzy+=p[i];
				for(int i=a+3;i<=b-2;i++)
				hyf+=p[i];
				ans+=min(hyf,lzy);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
