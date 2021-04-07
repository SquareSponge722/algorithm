# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <queue>
# define re register
# define Inf 0x3f3f3f3f
# define N 100010
using namespace std;
int n,m;
char s;
int a[N],b[N];
int head[N];
int rd[N],cd[N];
int _a,_x,_b,_y;
int dp[N],_dp[N];//节点i处的最小值 
int mark[N];
bool _pd;
int tot,minn = Inf;

struct edg
{
	int next;
	int to;
}e[N<<1];

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
	if(minn < tot)	return;
	for(re int i = head[s]; i != -1; i = e[i].next)
	{		
		if(mark[s] != Inf || !mark[s])
		{
			mark[s] = 1;
			int p = e[i].to;
			mark[p] = 1;
			tot += a[s];
			int cpy = a[s];
			_dfs(p);
			mark[s] = 0;
			tot -= a[s];
		}	
	}	
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(head,-1,sizeof(head));
	ios::sync_with_stdio(false);
	n = read() , m = read() , cin>>s;
	
	int u,v,w;
	for(re int i = 1; i <= n; i++)	a[i] = read() , b[i] = a[i] , dp[i] = a[i] , _dp[i] = dp[i];
	for(re int i = 1; i <= n-1; i++)
	{
		u = read() , v = read() , w = read();
		e[i] = (edg){head[u],v};	head[u] = i;
		e[i+n] = (edg){head[v],u};	head[v] = i+m;
	}
	
	for(re int i = 1; i <= m; i++)
	{
		memset(mark,0,sizeof(mark));
		for(re int i = 1; i <= n; i++)	a[i] = b[i];
		_a = read() , _x = read() , _b = read() , _y = read();
		if(_x == 0)	a[_x] = Inf , mark[_x] = Inf;
		if(_y == 0)	a[_y] = Inf , mark[_y] = Inf;
		for(re int i = 1; i <= n; i++)
		{
			_dfs(i);
			minn = min(minn , tot);
		}
		if(minn == Inf)	{cout<<"-1"<<endl;}
		else cout<<minn<<endl;
	}
	return 0;
	
}
