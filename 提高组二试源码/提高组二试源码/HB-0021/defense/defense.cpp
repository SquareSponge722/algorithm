#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100050
using namespace std;
int _min(int x,int y) {return x<y?x:y;}
struct Edge
{
	int next;
	int to;
} e[N<<1];
int n,m,w[N],f[N][2],in[N];
short book[N];
bool flag;
int head[N],a,b,x,y;
char s[10];
void DP(int x,int baba)
{
	f[x][1]=w[x];
	f[x][0]=0;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==baba) continue;
		DP(v,x);
		if(book[v]==1) 
		{
			f[x][0]+=f[v][1];
			f[x][1]+=f[v][1];
		}
		else if(book[v]==-1)
		{
			f[x][0]+=f[v][0];
			f[x][1]+=f[v][0];
		}
		else 
		{
			f[x][0]+=f[v][1];
			f[x][1]+=_min(f[v][0],f[v][1]);
		}
	}
	return;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	scanf("%d",&w[i]);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[i]=(Edge) {head[u],v};
		head[u]=i;
		e[i+n]=(Edge) {head[v],u};
		head[v]=i+n;
		in[u]++;
		in[v]++;
	}
	e[n]=(Edge) {head[0],1};
	head[0]=n;
	e[n+n]=(Edge) {head[1],0};
	head[1]=n+n;
	while(m--)
	{
		memset(book,0,sizeof(book));
		memset(f,0x3f,sizeof(f));
		flag=false;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x) book[a]=1;
		else book[a]=-1;
		if(y) book[b]=1;
		else book[b]=-1;
		if(x==0&&y==0)
		{
			if(in[a]==1)
			for(int i=head[a];i;i=e[i].next)
			{
				if(e[i].to==b) 
				{
					printf("-1\n");
					flag=true;
				}
			}
			if(in[b]==1)
			for(int i=head[b];i;i=e[i].next)
			{
				if(e[i].to==a) 
				{
					printf("-1\n");
					flag=true;
				}
			}
		}
		if(flag) continue;
		DP(0,-1);
		if(book[1]==1)
		{
			if(f[1][1]!=0x3f3f3f3f)
			printf("%d\n",f[1][1]);
			else printf("-1\n");
		}
		else if(book[1]==-1)
		{
			if(f[1][0]!=0x3f3f3f3f)
			printf("%d\n",f[1][0]);
			else printf("-1\n");
		}
		else 
		{
			if(f[1][0]!=0x3f3f3f3f||f[1][1]!=0x3f3f3f3f)
			printf("%d\n",_min(f[0][0],f[0][1]));
			else printf("-1\n");
		}
	}
	return 0;
}
