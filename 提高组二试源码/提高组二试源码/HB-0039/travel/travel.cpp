#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
bool map[5101][5101]={false},book[5101]={false},book2[5101]={false},book1[5101]={false};
int q[5100]={0},k=0,m,n,s[5100]={0},sum=0,jud=0,juddd=0,ans=5001;
void dfs1(int cur)
{
	int i;
	book[cur]=true;
	k++;q[k]=cur;
	for(i=1;i<=n;i++)
	{
		if(book[i]==false && map[cur][i]==true)
		{
			dfs1(i);
		}
	}
}
void dfs2(int cur,int last)
{
	int i,l;
	book[cur]=true;
	k++;q[k]=cur;
	for(i=1;i<=n;i++)
	{
		if(jud==1) break;
		if(book[i]==true && i!=last && map[cur][i]==true)
		{
			l=k;
			while(q[l+1]!=i)
			{
				book2[q[l]]=true;
				l--;
			}
			jud=1;break;
		}
		if(book[i]==false && map[cur][i]==true)
		{
			dfs2(i,cur);
		}
	}
	q[k]=0;k--;
}
void dfs3(int cur)
{
	int i,t,b,judd=0,h,asd=0;
	book1[cur]=true;
	sum++;s[sum]=cur;
	if(book2[cur]==true && ans<=n && juddd==0) h=ans;
	else h=n;
	if(h!=n && juddd==0){
		for(i=1;i<=n;i++)
			if(book1[i]==false && map[cur][i]==true && book2[i]==false)
				asd=1;
			}
	if(asd!=0) h=n;
	for(i=1;i<=h;i++)
	{
		if(book1[i]==false && map[cur][i]==true)
		{
			t=i;b=n+1;judd=1;
			while(t<=n && book2[cur]==true)
			{
				t++;
				if(map[cur][t]==true && book2[t]==false)
				{
					b=t;break;
				}
			}
			ans=min(ans,b);
			dfs3(i);
		}
	}
	if(judd==0 && i!=n+1) juddd=1;
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,x,y;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		map[x][y]=true;map[y][x]=true;
	}
	if(m==n-1)
	{
		dfs1(1);
		for(i=1;i<=n;i++) printf("%d ",q[i]);
	}
	else
	{
		dfs2(1,1);
		dfs3(1);
		for(i=1;i<=n;i++) printf("%d ",s[i]);
	}
	return 0;
}
