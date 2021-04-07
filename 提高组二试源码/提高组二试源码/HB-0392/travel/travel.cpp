#include<cstdio>
#include<cctype>
using namespace std;
const int maxn=5005;
int n,m;
bool tag;
bool vis[maxn];
int tmp[maxn];
int d[maxn][maxn];
inline int read()
{
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c&15),c=getchar();
	return x;
}
void dfs1(int u)
{
	vis[u]=1;
	tmp[++tmp[0]]=u;
	for(int v=1;v<=n;v++)
	{
		if(d[u][v]&&!vis[v]) dfs1(v);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		d[u][v]=d[v][u]=1;
	}
	dfs1(1);
	for(int i=1;i<=tmp[0];i++) printf("%d ",tmp[i]);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
