#include<bits/stdc++.h>
using namespace std;
int f[5005][5005],use[5005],a[5005],ans[5005],fan[5005],fa[5005];
int k=1,n;
void g(int x)
{
	int i;
	if(!a[x])
	return;
	for(i=2;i<=n;i++)
	{
		if(x==fa[i])
		continue;
		if(f[x][i]==1&&use[i]==0)
		{
			use[i]=1;
			k++;
			ans[k]=i;
			fan[i]=k;
			fa[i]=x;
			g(i);
		}
		if(f[x][i]==1&&use[i]==1&&x!=fa[i])
		{
			if(x<i)
			swap(ans[fan[i]],ans[fan[x]]);
			swap(fan[i],fan[x]);
		}
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,j,m,x,y;
	cin>>n>>m;
	
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		f[x][y]=1;
		f[y][x]=1;
		a[x]++;
		a[y]++;
	}
	ans[1]=1;
	g(1);
	for(i=1;i<=n;i++)
	cout<<ans[i]<<" ";
	return 0;
}
