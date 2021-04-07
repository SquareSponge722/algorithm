#include<bits/stdc++.h>
using namespace std;

int n,m;
int fa[30010];
vector <int> nxt[30010];
int flr[30010];
int ff[30010];
int maxf=0;
vector<int>leaf;
void add(int u,int v,int w)
{
	fa[v]=u;
	nxt[u].push_back(v);
	ff[v]=w;
	flr[v]=flr[u]+1;
}
int read()
{
	int anss=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		anss=anss*10+c-'0';
		c=getchar();
	}
	return  anss;
}

void dfs(int x)
{
	if(!nxt[x].size())
	{
		leaf.push_back(x);
		return;
	}
	for(unsigned int i=0;i<nxt[x].size();i++)
	{
		dfs(nxt[x][i]);
	}
}
int ans=0;
void LCA()
{
	dfs(1);

	for(unsigned int i=0;i<leaf.size();i++)
	{
		for(unsigned int j=0;j<leaf.size();j++)
		{		
			int temp=0;
			int tempi=leaf[i],tempj=leaf[j],tppi=flr[leaf[i]],tppj=flr[leaf[j]];
			if(leaf[i]==leaf[j] )continue;
			if(flr[leaf[i]]<flr[leaf[j]] )
			{
				while(flr[leaf[i]]<flr[leaf[j]])
				{
					temp+=ff[leaf[j]];
					leaf[j]=fa[leaf[j]];
					flr[leaf[j]]--;
				}
			}
			if(flr[leaf[i]]>flr[leaf[j]] )
			{
				while(flr[leaf[i]]>flr[leaf[j]])
				{
					temp+=ff[leaf[i]];
					leaf[i]=fa[leaf[i]];
					flr[leaf[i]]--;
				}
			}
			while(leaf[i]!=leaf[j])
			{
				temp+=ff[leaf[i]]+ff[leaf[j]];
				leaf[i]=fa[leaf[i]];
				leaf[j]=fa[leaf[j]];
			}
			leaf[i]=tempi;
			leaf[j]=tempj;
			flr[leaf[i]]=tppi;
			flr[leaf[j]]=tppj;
			ans=max(ans,temp);
		}
	}
}
priority_queue<int>pq;
void LCA1()
{
	dfs(1);

	for(unsigned int i=0;i<leaf.size();i++)
	{
		for(unsigned int j=0;j<leaf.size();j++)
		{		
			int temp=0;
			int tempi=leaf[i],tempj=leaf[j],tppi=flr[leaf[i]],tppj=flr[leaf[j]];
			if(leaf[i]==leaf[j] )continue;
			if(flr[leaf[i]]<flr[leaf[j]] )
			{
				while(flr[leaf[i]]<flr[leaf[j]])
				{
					temp+=ff[leaf[j]];
					leaf[j]=fa[leaf[j]];
					flr[leaf[j]]--;
				}
			}
			if(flr[leaf[i]]>flr[leaf[j]] )
			{
				while(flr[leaf[i]]>flr[leaf[j]])
				{
					temp+=ff[leaf[i]];
					leaf[i]=fa[leaf[i]];
					flr[leaf[i]]--;
				}
			}
			while(leaf[i]!=leaf[j])
			{
				temp+=ff[leaf[i]]+ff[leaf[j]];
				leaf[i]=fa[leaf[i]];
				leaf[j]=fa[leaf[j]];
			}
			leaf[i]=tempi;
			leaf[j]=tempj;
			flr[leaf[i]]=tppi;
			flr[leaf[j]]=tppj;
			pq.push(temp);
		}
	}
}
void solve1()
{
	LCA();
	cout<<ans<<endl;
}
int flag1=0;
int flag2=0;

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();
	m=read();
	int a1,a2,a3;
	
	for(int i=1;i<n;i++)
	{
		a1=read();a2=read();a3=read();
		add(a1,a2,a3);
		if(a1!=1)flag1=1;
		if(a1!=a2-1)flag2=1;
	}
	if(m==1)
	{
		solve1();
		return 0;
	}
else if(!flag1)
	{
		sort(ff+2,ff+n+1);
		for(int i=2;n-i+2>i;i++)
		{
			pq.push(ff[i]+ff[n-i+2]);
		}
		for(int i=2;i<=n;i++)
		{
			pq.push(ff[i]);
		}
		int ansx;
		for(int i=0;i<m;i++)
		{
			ansx=pq.top();
			pq.pop();
		}
		cout<<ansx<<endl;
		return 0;
	}
	else
	{
		LCA1();
		int anxx;
		for(int i=0;i<m;i++)
		{
			anxx=pq.top();
			pq.pop();
		}
		cout<<anxx<<endl;
	}
	return 0;
}
