#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,c[100010],d[100010];
string type;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout)''
	long long ans=0;
	cin>>n>>m;
	cin>>type;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		a[c][++b[c]]=d;
		a[d][++b[d]]=c;
	}
	if(type[0]=='A')
	{
		if(type[1]=='2')
		{
			for(int i=1;i<=m;i++)
			{
				int e,f,x,y;
				scanf("%d%d%d%d",&e,&x,&f,&y);
				if(x==0&&y==0)
				{
					cout<<-1<<endl;
					continue;
				}
				if(x==1)
				{
					ans+=c[e];
					d[e]=1;
				}
				if(y==1)
				{
					 ans+=c[f];
					 d[f]=1;
				}
			}
			for(int i=2;i<=n;i++)
			{
				if(d[i-1]=0)
				{
					d[i]=1;
					ans+=d[i];
				}
			}
			cout<<ans<<endl;
		}
		if(type[1]=='1')
		{
			for(int i=1;i<=m;i++)
			{
				int e,f,x,y;
				scanf("%d%d%d%d",&e,&x,&f,&y);
				if((f==e+1||e==f+1)&&x==0&&y==0)
				{
					cout<<-1<<endl;
					continue;
				}
				if(x==1)
				{
					ans+=c[e];
					d[e]=1;
				}
				if(y==1)
				{
					 ans+=c[f];
					 d[f]=1;
				}
			}
			for(int i=2;i<=n;i++)
			{
				if(d[i-1]=0)
				{
					d[i]=1;
					ans+=d[i];
				}
			}
			cout<<ans<<endl;
		}
	}
}
