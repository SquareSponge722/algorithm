# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
# define N 210
# define re register
# define Inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
int T;
int n,a[N],m;
bool flag[N];
bool pd;
int tot,cpy,ed,st,num;

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

void _dfs(int x)
{
	int i;
	if(pd == true)	return;

	for(i = 1; i < x; i++)
	{
		tot += a[i];
		cpy = a[i];
		if(tot > num)	{tot -= a[i]; return;}
		if(tot == num)	{pd = true;return;}
		_dfs(x);
		tot -= a[i];
	}
	return;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T = read();
	while(T--)
	{
		memset(flag,0,sizeof(flag));
		memset(a,0,sizeof(a));
		m = 0;
		n = read();
		m = n;
		for(re int i = 1; i <= n; i++)	a[i] = read();
		sort(a+1,a+n+1);
		for(re int i = 1; i <= n; i++)		
			if(!flag[i])	
			for(re int j = i+1; j <= n; j++)
			{
				if(a[j] % a[i] == 0)
				{
					m--;
					flag[j] = 1;
					break;
				}
			}
				
		for(re int i = 1; i <= n; i++)
		{
			pd = false;
			if(!flag[i])
			{	
				tot = 0 , cpy = 0;
				num = a[i];
				_dfs(i);
				if(pd == true)	m--;
			}
		}		
		printf("%d\n",m);		
	}
	return 0;
}
