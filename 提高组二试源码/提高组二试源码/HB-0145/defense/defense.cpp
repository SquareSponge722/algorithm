#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#define N 100000+1000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<pair<int,int> ,bool> mp;
struct node
{
	int to,nxt;
}q[N];
struct point
{
	int id;
}a[N];
int n,m,data[N],head[N],num=0,fa[N],deep[N],in[N],cnt=0,dealin[N];
char ask[10];
bool noarmy[N],gotarmy[N];
void add(int x,int y)
{
	q[num]=(node){y,head[x]};
	head[x]=num++;
	q[num]=(node){x,head[y]};
	head[y]=num++;
}
void dfs(int x,int father,int dep)
{
	fa[x]=father;
	deep[x]=dep;
	for(int i=head[x];i!=-1;i=q[i].nxt)
	{
		int v=q[i].to;
		if(v!=fa[x])
		{
			dfs(v,x,dep+1);
		}
	}
}
bool cmp(point x,point y)
{
	return deep[x.id]>deep[y.id];
}
void gettag(int x)
{
	for(int i=head[x];i!=-1;i=q[i].nxt)
	{
		int v=q[i].to;
		in[v]--;
	}
	in[x]=0;
	cnt+=data[x];
}
int main() 
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d%s",&n,&m,ask);
	for(int i=1;i<=n;i++)
	{
		data[i]=read();
		a[i].id=i;
	}
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();
		add(x,y);
		in[x]++;
		in[y]++;
		mp[make_pair(x,y)]=1;
		mp[make_pair(y,x)]=1;
	}
	dfs(1,0,1);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++)
	{
		cnt=0;
		int aa=read(),x=read(),b=read(),y=read();
		if(x==0&&y==0&&mp[make_pair(aa,b)]){printf("-1\n");continue;}
		for(int j=1;j<=n;j++)dealin[j]=in[j];
		if(x==1){gettag(aa);gotarmy[aa]=1;}
		else if(x==0){noarmy[aa]=1;}
		if(y==1){gettag(b);gotarmy[b]=1;}
		else if(y==0){noarmy[b]=1;}
		for(int j=1;j<=n;j++)
		{
			int xx=a[j].id;
			if(!in[xx]||noarmy[xx]||gotarmy[xx])continue;
			if(!noarmy[fa[xx]]&&!gotarmy[fa[xx]]&&in[fa[xx]])gettag(fa[xx]);
			else gettag(xx);
		}
		printf("%d\n",cnt);
		for(int j=1;j<=n;j++)in[j]=dealin[j];
		noarmy[aa]=noarmy[b]=gotarmy[aa]=gotarmy[b]=0;
	}
	return 0;
}