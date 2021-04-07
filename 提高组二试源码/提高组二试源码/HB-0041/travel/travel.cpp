#include <bits/stdc++.h>
using namespace std;
int read()
{
	int sum=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch<='9'&&ch>='0'){sum=sum*10+ch-'0';ch=getchar();}
	return sum;
}
const int N = 5010;
vector<int>q[N];
struct node
{
	int u,v;
};vector<node>q1;
int n,m,ans[N],fa[N],cnt;
int suc;
void dfs(int x,int id)
{
	cnt++;
	if(x<ans[cnt]){ans[cnt]=x;suc=2;}
	else if(suc==2)ans[cnt]=x;
	else if(x>ans[cnt]){suc=1;return;}
	for(int i=0;i<q[x].size();i++)
	{
		int v=q[x][i];
		if(fa[x]==v)continue;
		if(q1[id].u==x&&q1[id].v==v)continue;
		if(q1[id].v==x&&q1[id].u==v)continue;
		fa[v]=x;
		dfs(v,id);if(suc==1)return;
	}
}
int low[N],dfn[N],tot,top,sta[N];bool insta[N];
void tarjan(int x,int fr)
{
	dfn[x]=low[x]=++tot;
	sta[++top]=x;insta[x]=true;
	for(int i=0;i<q[x].size();i++)
	{
		int v=q[x][i];
		if(v==fr)continue;
		if(!dfn[v])
		{
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
		}
		else if(insta[v])low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		if(sta[top]==x){insta[sta[top]]=false;top--;return;};
		int pre=sta[top];q1.push_back((node){pre,x});
		while(sta[top]!=x)
		{
			q1.push_back((node){sta[top-1],pre});
			insta[sta[top]]=false;top--;pre=sta[top];
		}
		insta[sta[top]]=false;top--;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int ju1=read(),ju2=read();
		q[ju1].push_back(ju2);
		q[ju2].push_back(ju1);
	}
	for(int i=1;i<=n;i++)sort(q[i].begin(),q[i].end());
	memset(ans,0x3f,sizeof(ans));
	if(m==n-1)
	{
		q1.push_back((node){0,0});
		dfs(1,0);
		for(int i=1;i<n;i++)printf("%d ",ans[i]);printf("%d",ans[n]);
		return 0;
	}
	else 
	{
		tarjan(1,0);
		for(int i=0;i<q1.size();i++)
		{
			memset(fa,0,sizeof(fa));suc=0;
			cnt=0;dfs(1,i);
		}
		for(int i=1;i<n;i++)printf("%d ",ans[i]);printf("%d",ans[n]);
	}
	return 0;
}
