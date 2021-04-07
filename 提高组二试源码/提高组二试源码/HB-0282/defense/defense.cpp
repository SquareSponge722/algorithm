#include<bits/stdc++.h>
using namespace std;

long long read()
{
	long long anxs=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		anxs=anxs*10+c-'0';
		c=getchar();
	}
	return anxs;
}

long long n;
long long q;
string s;
long long V[100010];
long long f[100010];
long long g[100010];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();q=read();
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		V[i]=read();
	}
	long long a1,a2,b1,b2;
	for(int i=1;i<n;i++)
	{
		a1=read();a2=read();
	}
	while(q--)
	{
		a1=read();a2=read();b1=read();b2=read();
		if(abs(a1-b1)==1&&!a2&&!b2)
		{
			cout<<-1<<endl;
			continue;
		}
		f[1]=V[1];
		g[1]=0;
		for(int i=2;i<=n;i++)
		{
			if(i==a1+1)
			{
				if(a2==0)
				{
					g[i]=f[i]=g[i-1]+V[i];
				}
				else
				{
					f[i]=f[i-1]+V[i];
					g[i]=f[i-1];
				}
				continue;
			}
			if(i==b1+1)
			{
				if(b2==0)
				{
					g[i]=f[i]=g[i-1]+V[i];
				}
				else
				{
					f[i]=f[i-1]+V[i];
					g[i]=f[i-1];
				}
				continue;
			}
			
			f[i]=min(f[i-1],g[i-1])+V[i];
			g[i]=f[i-1];
		}
		cout<<min(f[n],g[n])<<endl;
	}
	return 0;
}
