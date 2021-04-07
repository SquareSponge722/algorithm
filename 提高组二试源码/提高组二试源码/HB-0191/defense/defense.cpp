#include<bits/stdc++.h>
using namespace std;

void splay()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
}

int i1,i2;char ch;
inline int read()
{
	i1=i2=ch=0;
	while(!isdigit(ch))	i1|=ch=='-',ch=getchar();
	while(isdigit(ch))	i2=(i2<<1)+(i2<<3)+(ch^48),ch=getchar();
	return i1? -i2:i2;
}
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define derep(i,j,k) for(int i=j;i>=k;i--)
#define pic(i,j) for(int i=lin[j];i;i=e[i].nxt)

const int maxn=100010;
int que[maxn];
int lin[maxn];
struct edge
{
	int nxt,to;
}e[maxn<<1];

int tot=0;
void insert(int xx,int yy)
{
	e[++tot].nxt=lin[xx];lin[xx]=tot;e[tot].to=yy;
	e[++tot].nxt=lin[yy];lin[yy]=tot;e[tot].to=xx;
}

char opt[3];

int ans=0x3f3f3f3f;
int prob[maxn];
int p[maxn];
int u,v,a,b,x,y,n,m;

bool ojbk;
int sum=0;

void dfs_pic(int at,int frp)
{
	if(prob[at]) sum+=p[at];
	pic(i,at)
	{
		if(e[i].to==frp) continue;
		ojbk&=prob[e[i].to]|prob[at];
		if(!ojbk) return;
		dfs_pic(e[i].to,at);
	}
}

void check()
{
	ojbk=1;sum=0;
	dfs_pic(1,0);
	if(ojbk) ans=min(ans,sum);
}

void dfs(int k){
	if(k==n)
	{
		check();
		return;
	}
	if(k+1==a||k+1==b) dfs(k+1);
	else
	{
		prob[k+1]=0;dfs(k+1);
		prob[k+1]=1;dfs(k+1);
	}
}

int main()
{
	splay();
	
	n=read(),m=read();scanf("%s",opt+1);
	rep(i,1,n) p[i]=read();
	rep(i,2,n)
	{
		u=read(),v=read();
		insert(u,v);
	}
	rep(i,1,m)
	{
		a=read();prob[a]=read();b=read();prob[b]=read();
		ans=0x3f3f3f3f;
		dfs(0);
		printf("%d\n",(ans=(ans==0x3f3f3f3f?-1:ans)));
	}
	
	return 0;
}
