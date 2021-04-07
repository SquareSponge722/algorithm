#include<cstdio>
#include<iostream>
#include<list>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct edge
{
    int weight;
    int to;
};
const int INF=9999999;
const int MAXN=100001;
bool inQ[MAXN];
list<edge>edges[MAXN];
void addedge(int u,int v,int w)
{
     edges[u].push_back((edge){v,w});
}
int a[5001];
queue<int>q;
int n,m;
bool vis[5001];
bool mycheck()
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	addedge(i,i,0);
	}
    for(int i=1;i<=m;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	addedge(x,y,1);
    	addedge(y,x,1);
	}
	inQ[1]=true;
	q.push(1);
	a[1]=1;
	int ans=0;
	vis[1]=1;
	while(!q.empty())
	{
		int b[5001];
		int current=q.front();
		q.pop();
		ans++;
		inQ[current]=false;
		a[ans]=current;
		int tmpp=0;///Ð¡¼ÆÊýÆ÷ 
		for(list<edge>::iterator it=edges[current].begin();it!=edges[current].end();it++)
		{
			cout<<it->to;
			if(vis[it->to]==false&&it->weight!=0)
			{
			   cout<<it->to<<endl;
			   tmpp++;
		       b[tmpp]=it->to;
			}
		}
		sort(b+1,b+tmpp+1);
		for(int i=1;i<=tmpp;i++)
		{
			vis[i]=true;
			for(list<edge>::iterator it=edges[i].begin();it!=edges[i].end();it++)
			{
				if(vis[it->to]&&it->to!=current)
				{
					addedge(i,it->to,0);
				}
			}
			if(!inQ[b[i]])
		    {
			  q.push(b[i]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<' ';
	}
    return 0;
}
