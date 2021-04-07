# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
# define N 100010
# define re register
# define Inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
int n;
int a[N];
int minn = Inf,tmp;
LL tot;

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

int _min(int x,int y)	{return x > y ? y : x;}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	for(re int i = 1; i <= n; i++)	a[i] = read() , minn = _min(minn , a[i]);
	a[n+1] = minn;
	
	for(re int i = 1; i <= n; i++)
	{
		while(a[i] != minn)
		{
			tmp = i;
			while(1)
			{
				a[tmp]--;
				tmp++;
				if(a[tmp] == minn)	{tot++;break;}
			}
		}
	}
	printf("%lld\n",tot + minn);
	return 0;
}
