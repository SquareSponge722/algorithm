#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100100;
struct node
{
	int to,nex;
}ed[N*4];
int n,m,tot,x,y,a,b;
int head[N],val[N];
long long f[N][2];
char s[10];
inline void add(int u,int v){
	ed[tot].nex=head[u];
	ed[tot].to=v,head[u]=tot++;
}
bool leg();
void dfs(int,int);
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d %d %s",&n,&m,s);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&a,&x,&b,&y);
		if(!leg()) continue;
		dfs(1,1);
		printf("%d\n",min(f[1][0],f[1][1]));
	}
	return 0;
}
bool leg()
{
	bool f1=x,f2=y,ff=true;
	if(!f1 && !f2)
	{
		for(int j=head[a];j!=-1;j=ed[j].nex)
		{
			int to=ed[j].to;
			if(to==b)
			{
				ff=false;
				break;
			}
		}
	}
	else
	{
		return true;
	}
	if(!ff)
	{
		printf("-1\n");
		return false;
	}
	return true;
}
void dfs(int u,int fa)
{
	f[u][0]=val[u],f[u][1]=0;
	for(int i=head[u];i!=-1;i=ed[i].nex)
	{
		int to=ed[i].to;
		if(to==fa) continue;
		dfs(to,u);
		f[u][0]+=min(f[to][0],f[to][1]);
		f[u][1]+=f[to][0];
	}
	if((u==a && !x) || (u==b && !y))
	{
		f[u][0]=0x3f3f3f3f3f3f3f3f;
		return ;
	}
	if((u==a && x) || (u==b && y))
	{
		f[u][1]=0x3f3f3f3f3f3f3f3f;
		return ;
	}
}
