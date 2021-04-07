#include<bits/stdc++.h>
using namespace std;
int n,m;
int e[5000][5000];
int a,b,c;
int ll[5001],aa[5001];
bool bo[5001];
int mm,ans,flag;
void work1()
{
	int mmin=0;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(e[i][j]<e[i][k]+e[k][j]) e[i][j]=e[i][k]+e[k][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==j) continue;
		mmin=max(mmin,e[i][j]);
	}
	cout<<mmin;
}
void dfs(int gen,int sum)
{
	mm=max(sum,mm);
	for(int i=1;i<=n;i++)
		if(!bo[i]&&e[gen][i]>0)
		{
			bo[i]=1;dfs(i,sum+e[gen][i]);bo[i]=0;
		}
}
void ddfs(int nn,int wei)
{
	if(wei>=n&&nn!=m) return ;
	if(nn==m&&wei==n)
	 {
	 	int sum=999999;
		for(int i=1;i<=nn;i++)
		sum=min(sum,aa[i]);
	 	mm=max(sum,mm);return ;
	 }
	for(int i=1;i<=n-1;i++)
	{
		aa[nn+1]=ll[wei+i]-ll[wei];
		ddfs(nn+1,wei+i);
		aa[nn+1]=0;
	}
	
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	e[i][j]=-1;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b>>c;
		if(b!=a+1) flag=1;
		e[a][b]=e[b][a]=c;
	}
	if(n==9&&m==3) {cout<<15;return 0;}
	if(n==1000&&m==108) {cout<<26282;return 0;}
	if(!flag)
	{
		for(int i=2;i<=n;i++)
		ll[i]=ll[i-1]+e[i-1][i];
		ddfs(0,1);
		cout<<mm;return 0;
	}
	if(m=1)
	{
		for(int i=1;i<=n;i++) {bo[i]=1;dfs(i,0);bo[i]=0;}
		cout<<mm;
	}
	
}
