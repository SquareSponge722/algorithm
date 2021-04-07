#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int maxx=5010;
const int inf=0x3f3f3f3f;
int head[maxx],tot=0,w[maxx],p=0,c=0;
char aa[5010];
int n,m;
bool vis[maxx],book[maxx];
struct data
{
	int x,y,z;
}a[maxx];
void add(int start,int end,int dit)
{
	a[++tot].x=head[start];
	a[tot].y=end;
	a[tot].z=dit;
	head[start]=tot;
}
void fafa(int s)
{
	for(int i=1;i<=n;i++)
	{
		book[i]=0;
	}
	queue<int> q;
	q.push(s);book[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();book[u]=1;
		int ans=0x3f3f3f3f;
		for(int i=head[u];i;i=a[i].x)
		{
			int v=a[i].y;
			//printf("v=%d ",v);
			if(v<ans && book[v]==0)
			{
				ans=v;
			}
			w[++p]=v;
			//printf("wp=%d ",w[p]);
		}
		//printf("ans=%d ",ans);
		if(ans==1061109567)
		{
			//printf("1");
			//printf("wc=%d book=%d",w[c],book[w[c]]);
			c++;
			if(book[w[++c]]==0)
			{
				//printf("wc=%d ",w[c]);
				printf("%d ",w[c]);
				q.push(w[c]);
			}
		}
		else if(book[ans]==0) 
		{
				book[ans]=1;
				q.push(ans);
		}
		if(ans!=1061109567)printf("%d ",ans);
		//fafa(ans);
	}
}
void dfs(int step,int u)
{
	if(step==n)
	{
		return ;
	}
	int ans=0x3f3f3f3f;
	for(int i=head[u];i;i=a[i].x)
	{
		int v=a[i].y;
		//printf("v=%d ",v);
		if(ans>v&& book[v]==0)
		{
			ans=v;
			book[ans]=1;
	printf("%d ",ans);
	dfs(step+1,ans);
	book[ans]=0;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		add(t1,t2,t2);
		add(t2,t1,t1);
	}
	printf("1 ");
	book[1]=1;
	fafa(1);
	return 0;
}
