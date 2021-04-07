#include <cstdio>
#include <algorithm>
using namespace std;
int m,n;
int mapd[5010][5010],book[5010],ans[100010];
int tail;
int flag;
void dfs(int id)
{
	printf("%d ",id);
	for(int i=1;i<=n;i++)
	{
		if(!book[i]&&mapd[id][i])
		{
			book[i]=1;
			dfs(i);
		}
	}
}
void judge(int id)
{
	if(book[1]==1)
		flag=1;
	for(int i=1;i<=n;i++)
	{
		if(!book[id]&&mapd[id][i])
		{
			for(int j=1;j<=tail;j++)
			{
				if(ans[j]==i)
					return;
			}
			book[i]=1;
			judge(i);
			book[i]=0;
		}
	}
}
void dfsm(int id,int step)
{
	tail=max(step,tail);
	/*for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");*/
	//printf("%d %d\n",tail,step);
	for(int i=step;i<=tail;i++)
	{
		if(ans[i]>id)
		{
			flag=0;
			judge(id);
			if(flag==0) goto A;
			for(int j=1;j<i;j++)
			{
				if(ans[j]==id) 
				{
					//printf("%d %d\n",id,ans[j]);
					goto A;
				}
			}
			step=i;
			for(int j=step;j<=tail;j++)
			{
				ans[j]=999999999;
			}
			break;
		}
	}
	ans[step]=id;
	for(int i=1;i<=n;i++)
	{
		if(!book[i]&&mapd[id][i])
		{
			book[i]=1;
			dfsm(i,step+1);
			book[i]=0;
		}
	}	
A:;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		mapd[a][b]=mapd[b][a]=1;
	}
	if(m==n-1)
	{
		book[1]=1;
		dfs(1);
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans[i]=999999999;
		}
		book[1]=1;
		dfsm(1,1);
		for(int i=1;i<=n;i++)
		{
			printf("%d ",ans[i]);
		}
	}
	return 0;
}
