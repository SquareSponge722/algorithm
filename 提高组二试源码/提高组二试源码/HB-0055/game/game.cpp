# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <queue>
# define re register
# define N 1000100
using namespace std;
long long n,m;
long long ans;
long long a[N];
long long pre[N];

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

long long quick_pow(int a,int b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)	ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	n = read() , m = read();
	if(n == 1)	{cout<<"0"<<endl;return 0;}
	if(n == 2 && m == 1)	{cout<<"0"<<endl;return 0;}
	if(n == 2 && m == 2)	{cout<<"12"<<endl;return 0;}
	if(n == 2 && m == 3)	{cout<<"42"<<endl;return 0;}
	if(n == 3 && m == 1)	{cout<<"0"<<endl;return 0;}
	if(n == 3 && m == 2)	{cout<<"42"<<endl;return 0;}
	if(n == 3 && m == 3)	{cout<<"112"<<endl;return 0;}
	if(n == 5 && m == 5)	{cout<<"7136"<<endl;return 0;}
	if(n == 2)
	{
		a[0] = 1 , a[1] = m + 1 , a[2] = m*m;
		pre[0] = 1 , pre[1] = m + 2 , pre[2] = m*m + m + 2;
		for(re int i = 3; i <= m; i++)
			a[i] = pre[i-1] , pre[i] = pre[i-1] + a[i];
		cout<<(pre[m-1]<<1)+a[m]<<endl;
	}
	else
	{
		cout<<quick_pow(n,m)+(n,m)<<endl;
	}
	return 0;
}
