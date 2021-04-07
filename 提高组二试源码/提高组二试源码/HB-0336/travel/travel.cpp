#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m,cnt=1;
int t[1010],s[1010];
int e[2010][2010],book[1010];

int stringcmp(int a[],int b[])
{
	int big=1,same=0,small=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<b[i])
			return small;
		if(a[i]>b[i])
			return big;
	}
	return same;
}

void debug(int r)
{
	cout<<"number:"<<r;
	for(int p=1;p<=n;p++)
		printf("%d",t[p]);
	cout<<endl;
}

void init()
{
	for(int i=1;i<=1009;i++)
		s[i]=100;
}

void dfs(int cur,int step)
{
	if(cnt==n+1)
		return;
	for(int i=1;i<=n;i++)
		if(e[cur][i]==1 && book[i]==0)
		{
			book[i]=1;
			t[cnt++]=i;
			dfs(i,step+1);
			book[i]=0;
		}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		e[u][v]=e[v][u]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cnt=1;
		memset(t,0,sizeof(t));
		book[i]=1;
		t[cnt]=i;
		cnt=2;
		dfs(i,2);
		book[i]=0;
		//debug(i);
		if(stringcmp(t,s)<0)
		{
			for(int j=1;j<=n;j++)
				s[j]=t[j];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",s[i]);
	return 0;
}