#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 5001
using namespace std;
int n,m,u,v,t1,t2;
int head[N],ans[N],top,a[N],tt[N],pj;
bool book[N];
struct edge
{
	int to,next;
} e[N<<1];
void dfs(int v,int fa)
{
	int tmp[100],cnt=0;
	for(int i=head[v];i;i=e[i].next)
	{
		int go=e[i].to;
		if(go!=fa)
		tmp[++cnt]=go;
	}
	sort(tmp+1,tmp+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(!book[tmp[i]])
		{
			book[tmp[i]]=1; 
			ans[++top]=tmp[i];
			dfs(tmp[i],v); 
		} 
	}
	return ;
}
bool flag=false;
void Dfs(int v,int fa)
{
	int tmp[100],cnt=0;
	for(int i=head[v];i;i=e[i].next)
	{
		int go=e[i].to;
		if(go!=fa)
		tmp[++cnt]=go;
	}
	sort(tmp+1,tmp+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(!flag && (tmp[i]==t1 || tmp[i]==t2))
		{
			flag=true;
			continue;
		}
		if(!book[tmp[i]])
		{
			book[tmp[i]]=1;
			tt[++pj]=tmp[i];
			Dfs(tmp[i],v);
		}
	}
	return ;
}
int getf(int x)
{return x==a[x]?x:a[x]=getf(a[x]);};
void merge(int x,int y)
{
	a[getf(y)]=getf(x);
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	if(m==n-1)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			e[i]=(edge) {v,head[u]}; head[u]=i;
			e[i+m]=(edge) {u,head[v]}; head[v]=i+m;
		}
		dfs(1,0);
		cout<<'1'<<" ";
		for(int i=1;i<=top;i++)
		cout<<ans[i]<<' ';
		cout<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++) a[i]=i;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v; 
			if(getf(u)==getf(v))
			t1=u,t2=v;
			else merge(u,v);	
			e[i]=(edge) {v,head[u]}; head[u]=i;
			e[i+m]=(edge) {u,head[v]}; head[v]=i+m;
		}
		dfs(1,0);
		memset(book,0,sizeof(book));
	 	Dfs(1,0);
	 	cout<<'1'<<" ";
	 	int i; bool zz;
		for(i=1;i<=top;i++)
		{
			if(ans[i]<tt[i])
			{
				zz=1;
				break;
			}
			else if(ans[i]==tt[i])
			cout<<ans[i]<<' ';
			else
			{
				zz=0;
				break;
			}
		}
		if(zz)
		for( ;i<=top;i++)
		cout<<ans[i]<<' ';
		else
		for( ;i<=top;i++)
		cout<<tt[i]<<' ';
		cout<<endl;
		return 0;
	}
}
