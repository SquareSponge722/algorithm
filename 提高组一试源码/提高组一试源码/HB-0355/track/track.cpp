#include<algorithm>
#include<memory.h>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn=100001;
int head[maxn],cnt;
struct node{int next,to,val;}edge[maxn];
int ans,pos,n,m,x,y,z,maxa=-1;
void add(int from,int to,int val)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	edge[cnt].val=val;
	head[from]=cnt;
}
void dfs(int k,int fa,int dep)
{
	if(dep>ans){ans=dep;pos=k;}
	for(int i=head[k];i;i=edge[i].next)
	{
		int v=edge[i].to;
		int w=edge[i].val;
		if(v!=fa)
		dfs(v,k,dep+w);
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int f=0; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
		if(x==1||y==1)f=1;
	}
	if(f==1)
	{
		dfs(1,1,0);
		ans=0;
		dfs(pos,1,0);
		printf("%d\n",ans);
		return 0;
	}
	else 
	{
		dfs(2,2,0);
		ans=0;
		dfs(pos,2,0);
		printf("%d\n",ans);
		return 0;
	}
}
