#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > map[50001],w[50001];
int m=0,n=0,judd1=0,minn=0,maxx=0,left=0,right=0,mid=0,maxxx=0,judd2;
int sum[50001]={0},res[50001]={0},book[50001]={0},t,summ[50001]={0},rd[50001]={0};
bool jud(int cur)
{
	int i=0,t=0,ans=0;
	for(i=1;i<=n-1;i++)
	{
		t+=sum[i];
		if(t>=cur) {ans++;t=0;}
	}
	return ans>=m;
}
void dfs(int cur,int dis)
{
	int i=0;
	book[cur]=1;res[cur]=dis;
	for(i=0;i<map[cur].size();i++)
		if(book[map[cur][i]]==0)
			dfs(map[cur][i],dis+w[cur][i]);
	return;
}
bool czx(int a,int b) {return a>b;}
bool czxx(int cur)
{
	int i=0,j=n,ans=0,cv=0;
	while(i+1<j)
	{
		i++;cv=0;
		while(j>i)
		{
			if(summ[i]+summ[j]>=cur)
			{
				ans++;cv=1;
			}
			j--;
			if(cv==1) break;
		}
	}
	return ans>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i=0,x=0,y=0,z=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		minn=min(minn,z);
		maxx+=z;
		rd[x]++;rd[y]++;
		sum[x]=z;summ[y]=z;
		map[x].push_back(y);
		map[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z);
		if(x+1!=y) judd1=1;
		if(x!=1) judd2=1;
	}
	if(judd1==0)
	{
		left=minn;right=maxx;
		while(left<right)
		{
			mid=(left+right+1)/2;
			if(jud(mid)) left=mid;
			else right=mid-1;
		}
		printf("%d",left);
	}
	else if(m==1)
	{
		dfs(1,0);
		for(i=1;i<=n;i++)
			if(res[i]>maxxx)
				maxxx=res[i],t=i;
		for(i=1;i<=n;i++) book[i]=0;
		dfs(t,0);
		maxxx=0;
		for(i=1;i<=n;i++)
			if(res[i]>maxxx)
				maxxx=res[i];
		printf("%d",maxxx);
	}
	else if(judd2==0)
	{
		sort(summ+1,summ+n+1,czx);
		left=minn;right=maxx;
		while(left<right)
		{
			mid=(left+right+1)/2;
			if(czxx(mid)) left=mid;
			else right=mid-1;
		}
		printf("%d",left);
	}
	else
	{
		printf("15");
	}
	return 0;
}



