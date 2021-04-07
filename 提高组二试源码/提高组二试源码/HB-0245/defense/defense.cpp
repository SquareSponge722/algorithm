#include<bits/stdc++.h>
using namespace std;
int n,m,g;
string st;
int a[100001];
long long f[100001][2];
struct bian{
	int next,to;
}o[200001];
int head[100001];
void add(int x,int y)
{
	o[++g].to=y;
	o[g].next=head[x];
	head[x]=g;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		int x,p,y,s;
		f[1][0]=0;
		f[1][1]=a[1];
		cin>>p>>x>>s>>y;
		f[p][1-x]=-1;
		f[s][1-y]=-1;
		if((p==s+1||p==s-1)&&x==0&&y==0)
		cout<<-1<<endl;
		for(int i=2;i<=n;i++)
		for(int j=0;j<=1;j++)
		{
			if(f[i][j]!=-1&&f[i-1][0]!=-1&&f[i-1][1]!=-1)
			{
				f[i][j]=min(f[i-1][0]+a[i],f[i-1][1]);
			}
			if(f[i][j]==-1)
			continue;
			if(f[i-1][0]==-1&&f[i][0]!=-1)
			f[i][j]=f[i-1][1];
			else
			f[i][j]=f[i-1][0]+a[i];
			if(f[i][0]==-1&&f[i-1][0]==-1)
			f[i][1]=f[i-1][1]+a[i];
		}
		long long ans=min(f[n][0],f[n][1]);
		cout<<ans<<endl;
	}
	return 0;
}

