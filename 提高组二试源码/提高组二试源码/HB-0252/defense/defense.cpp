//回首向来萧瑟处，
//归去,
//从此O I 陌路人。
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int N,M;
char type[4];
long long p[100005];
struct edge {
	int to;
	int next;
} E[200010];
int first[100005],nl;
long long f[100005],g[100005];
int book[100005],flag;
void add(int a,int b)  {
	E[++nl].to=b;
	E[nl].next=first[a];
	first[a]=nl;
}
void dfs(int u,int fa);
int main()  {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>N>>M>>type;
	for(int i=1;i<=N;i++)  {
		cin>>p[i];
	}
	int a,b;
	for(int i=1;i<N;i++)  {
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	int x,y;
	while(M--)  {
		cin>>a>>x>>b>>y;
		book[a]=x+1;
		book[b]=y+1;
		memset(f,0x7f,sizeof(f));
		memset(g,0x7f,sizeof(g));
		flag=true;
		dfs(1,0);
		if(!flag)  {
			cout<<-1<<endl;
		}
		else  {
			if(book[1]==2)  cout<<f[1]<<endl;
			else if(book[1]==1)  cout<<g[1]<<endl;
			else  cout<<min(f[1],g[1])<<endl;
		}
		memset(book,0,sizeof(book));
	}
	return 0;
}
void dfs(int u,int fa)  {
	g[u]=0;
	f[u]=p[u];
	for(int i=first[u];i;i=E[i].next)  {
		int v=E[i].to;
		if(v==fa)  {
			if(book[v]==1)  book[u]=2;
			continue;
		}
		if(book[u]==1 && book[v]==1)  {
			flag=false;
			return;
		}
		dfs(v,u);
		if(book[v]==2)  {
			f[u]+=f[v];
			g[u]+=f[v];
		}
		else if(book[v]==1)  {
			f[u]+=g[v];
			book[u]=2;
		}
		else  {
			f[u]+=min(f[v],g[v]);
			g[u]+=f[v];
		}
	}
}
