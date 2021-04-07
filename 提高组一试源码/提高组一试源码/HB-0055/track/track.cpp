# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <queue>
# define N 50010
# define re register
# define Inf 0x3f3f3f3f
using namespace std;
int n,num,maxn;
int head[N];
int dis[N];

struct edg
{
	int next;
	int to;
	int w;
}e[N<<1];

struct VD
{
	int v;
	int dis;
	bool operator < (const VD &a)	const
	{
		return a.dis < dis;
	}
};

int _max(int x,int y)	{return x > y ? x : y;}

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

void D(int s)
{
	priority_queue<VD>q;	
	for(re int i = 1; i <= n; i++)	dis[i] = Inf;
	dis[s] = 0;
	VD temp;
	temp.v = s , temp.dis = dis[s];
	q.push(temp);
	while(q.size())
	{
		temp = q.top();
		q.pop();
		int p = temp.v;
		if(dis[p] < temp.dis)	continue;
		for(re int i = head[p]; i != -1; i = e[i].next)
		{
			if(dis[e[i].to] > dis[p] + e[i].w)
			{
				dis[e[i].to] = dis[p] + e[i].w;
				temp.v = e[i].to , temp.dis = dis[e[i].to];
				q.push(temp);
			}
		}
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	n = read() , num = read();
	
	int u,v,w;
	for(re int i = 1; i <= n-1; i++)
	{
		u = read() , v = read() , w = read();
		e[i] = (edg){head[u],v,w};	head[u] = i;	
		e[i+n] = (edg){head[v],u,w};	head[v] = i+n;
	}	
	
	if(num == 1)
	{	
		for(re int i = 1; i <= n; i++)
		{
			D(i);
			for(re int j = 1; j <= n; j++)	
				if(dis[j] != Inf)
					maxn = _max(maxn , dis[j]); 
		}
		printf("%d\n",maxn);
		return 0;
	}
	else
	{
		D(1);
		for(re int i = 1; i <= n; i++)
			maxn = _max(maxn , dis[i]);
		printf("%d\n",maxn/num);	
	}
	return 0;
}
