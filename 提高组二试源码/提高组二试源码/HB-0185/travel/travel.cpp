#include<bits/stdc++.h>
using namespace std;
int q[10005][10005],sum[10005],rd[10005];
int n,m;
bool v[10005];
bool cmp(int x,int y)
{
	return x<=y;
}
int search(int p)
{
	for(int i=0;i<sum[p];i++)
	if(!v[q[p][i]])return q[p][i];
	return 0x3f;
}
void dfs(int p,int w)
{
	if(!sum[p])
	{
		printf("%d ",p);
		return;
	}
	for(int i=0;i<sum[p];i++)
	{
		if(!v[q[p][i]])
		{
			rd[p]--;
			v[q[p][i]]=1;
			if(q[p][i]<search(w))
			{
				cout<<q[p][i]<<" ";
				dfs(q[p][i],p);
			}
			else
			{
				int num=search(w);
				cout<<num<<" ";
				v[q[p][i]]=0;
				v[num]=1;
				dfs(num,q[p][i]);
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		q[x][sum[x]]=y;
		sum[x]++;
		rd[x]++;
		q[y][sum[y]]=x;
		sum[y]++;
		rd[x]--;
	}
	for(int i=1;i<=n;i++)
	sort(q[i],q[i]+sum[i],cmp);
	cout<<1<<" ";
	v[1]=1;
	dfs(1,1);
	return 0;
}
