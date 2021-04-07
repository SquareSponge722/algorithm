# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <queue>
# define re register
# define N 5050
using namespace std;
int n,m,tot;
int head[N];
int mark[N];//记录到一个点的上一个点 
int pre[N] , vis[N] , book[N];

struct edg
{
	int next;
	int to;
}e[N<<1];

struct VD
{
	int u;
	bool operator < (const VD &a)	const
	{
		return a.u < u;
	}
};

int read()
{
	int ans = 0;
	int fu = 1;
	char ch = getchar();
	while(ch > '9' or ch < '0')
	{
		if(ch == '-')	fu = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		ans *= 10;
		ans += ch - '0';
		ch = getchar();
	}
	return ans * fu;
}

void _dfs(int s)
{
	priority_queue<VD>q;
	VD temp;
	temp.u = s;
	q.push(temp);
	//pre[++tot] = s;
	while(q.size())
	{
		temp = q.top();
		pre[++tot] = temp.u;
		vis[temp.u] = 1;
		q.pop();
		int p = temp.u;
		for(re int i = head[p]; i != -1; i = e[i].next)
		{
			//p = e[i].to;												
				mark[e[i].to] = p;
				if(e[i].to != mark[p] && !vis[e[i].to])	temp.u = e[i].to , q.push(temp);			
		}
	}
} 

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));
	n = read() , m =  read();
	
	int u,v;
	for(re int i = 1; i <= m; i++)
	{
		u = read() , v = read();
		e[i] = (edg){head[u],v};	head[u] = i;
		e[i+m] = (edg){head[v],u};	head[v] = i+m;
	}
	_dfs(1);
	
	for(re int i = 1; i <= tot; i++)
	{
		if(!book[pre[i]])	printf("%d ",pre[i]) , book[pre[i]] = 1;
	}
	return 0;
}
