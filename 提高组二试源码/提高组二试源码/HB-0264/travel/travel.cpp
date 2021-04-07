#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=5000+100;
const int inf=99999999;
int head[maxn]={0},to[maxn]={0},vis[maxn]={0},book[maxn]={0},ans[maxn]={0},Ans[maxn]={0};
int in[maxn]={0},next[maxn]={0},kk[maxn]={0};
struct node{
	int next,to;
}edge[maxn]={0};
int n,m,cnt,top,topn,flag=0;
void add(int a,int b)
{
	edge[++cnt].next=head[a];
	edge[cnt].to=b;
	head[a]=cnt;
}
void change()
{
	for(int i=1;i<=n;i++)
	{
		Ans[i]=ans[i];
	}
}
void jud()
{
	for(int i=1;i<=n;i++)
	{
		if(ans[i]<Ans[i])
		{
			change();
			return;
		}
		else if(ans[i]>Ans[i])
			return;
	}
}
void dfs(int x,int deep,int num)
{
	if(num==n){jud(); flag=1; return;}
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(book[y]==0)
		{
			book[y]=1;
			ans[++top]=y;
			dfs(y,deep+1,num+1);
			book[y]--;
			ans[top]=0;
			top--;
		}
		dfs(ans[deep-1],deep-1,num);
	}	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d",&a,&b),add(a,b),add(b,a);
		in[b]++,in[a]++;
	}
	ans[1]=1; top++;
	for(int i=1;i<=n;i++) Ans[i]=99999999,in[i]--;
	book[1]=1;
	dfs(1,0,1);
	for(int i=1;i<=n;i++) printf("%d ",Ans[i]);
	return 0;
}