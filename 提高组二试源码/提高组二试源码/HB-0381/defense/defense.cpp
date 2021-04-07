#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m;
int ans=0;
struct str{
	int to,next;
}e[100010];
int head[100010],book[100010],flag[100010],sum[100010],cnt=0;
int map[1001][1001];
int p[100010];
char aa,bb;
void add(int u, int v)
{
	cnt++;
	e[cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void dfs(int x,int flag)
{
	if(book[x]==1)
		return;
	for(int i=head[x];i!=0;i=e[i].next)
	{
		int v=e[i].to;
		if(book[i])continue;
		
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	scanf("%c%c",&aa,&bb);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
		sum[u]++;sum[v]++;
	}
	while(m--)
	{
		ans=0;
		memset(book,0,sizeof(book));
		memset(flag,0,sizeof(flag));
		int a1,x1,b1,y1;
		scanf("%d%d%d%d",&a1,&x1,&b1,&y1);
		if(aa=='A')
		{
			flag[a1]=x1;flag[b1]=y1;
			book[a1]=book[b1]=1;
			if(abs(a1-b1)==1&&x1==0&&y1==0)
			{
				printf("-1\n");
				continue;
			}
			dfs(a1,flag[a1]);dfs(b1,flag[b1]);
			printf("%d",ans);
		}
	}
}
