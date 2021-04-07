#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define N 10005
using namespace std;
int book[N],head[N],minn=1;
struct E
{
	int nxt,to;
}  e[N];
int n,m,sum;
void add(int u,int v)
{
	e[++sum].nxt=head[u];
	e[sum].to=v;
	head[u]=sum;
}
void F1(int s)
{
	book[s]=1;
	for(int i=head[s];i;i=e[i].nxt)
	   if(book[e[i].to]==0)
		{
		  	book[e[i].to]=1;
		  	printf("%d ",e[i].to);
		  	F1(e[i].to);
		}
}
void F(int s)
{
	int maxn=N;
	int x=0;
	for(int i=1;i<=n;i++)
	  if(book[i]==1)
	    x++;
	if(x==n)   return;
	for(int i=head[s];i;i=e[i].nxt)
	   if(book[e[i].to]==0)
	     maxn=min(maxn,e[i].to);
	if(maxn!=N)
	{		
	    minn=maxn;
		book[minn]=1;
	    printf("%d ",minn);
	    F(minn);
	}
	else 
	{
		book[e[minn].nxt]=0;
		F1(e[minn].nxt);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	book[1]=1;
	printf("%d ",1);
	F(1);
	return 0;
}
