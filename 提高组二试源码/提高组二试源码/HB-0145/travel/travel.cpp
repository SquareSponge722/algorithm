#include <bits/stdc++.h>
#define N 100000+1000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct edge
{
	int fr,to,nxt;
}q[N];
int n,m,num=0,head[N],fa[N],ans[N],in[N],times=0;
bool suc[N];
inline void add(int x,int y)
{
	q[num]=(edge){x,y,head[x]};
	head[x]=num++;
	q[num]=(edge){y,x,head[y]};
	head[y]=num++;
}
vector <int> t[N];
void treedfs(int x)
{
	ans[++ans[0]]=x;
	for(int i=0;i<t[x].size();i++)
	{
		int v=t[x][i];
		if(v!=fa[x])
		{
			fa[v]=x;
			treedfs(v);
		}
	}
}
void dfs(int x,int regret)
{
	if(!suc[x]){ans[++ans[0]]=x;suc[x]=1;}
	for(int i=0;i<t[x].size();i++)
	{
		int v=t[x][i],r;
		if(t[x].size()<=1)r=regret;
		else if(i<t[x].size()-1)r=t[x][i+1];
		else r=regret;
		if(v!=fa[x]&&!suc[v])
		{
			if(regret<v&&regret!=0&&in[v]>=2&&times<1){in[v]--;times++;return ;}
			fa[v]=x;
			dfs(v,r);
		}
	}
}
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		t[x].push_back(y);
		t[y].push_back(x);
		in[x]++;
		in[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		sort(t[i].begin(),t[i].end());
	}
	if(m==n-1)
	{
		treedfs(1);
		for(int i=1;i<=ans[0];i++)
		{
			printf("%d ",ans[i]);
		}
	}
	else if(m==n)
	{
		dfs(1,0);
		for(int i=1;i<=ans[0];i++)
		{
			printf("%d ",ans[i]);
		}
	}
	return 0;
}