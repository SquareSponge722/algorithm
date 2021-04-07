#include <bits/stdc++.h>
#define jh(x,y) x^=y^=x^=y
using namespace std;
namespace fast_IO{
	int read()
	{
		register int num = 0;
		register char ch;
		register bool flag=false;
		while ((ch=getchar())==' '||ch=='\n'||ch=='\r');
		if (ch=='-')flag=true;else num=ch^48;
		while ((ch=getchar())>='0'&&ch<='9')
		num=(num<<1)+(num<<3)+(ch^48);
		if (flag)return -num;return num;
	}
}
const int N = 1e6+10,mod=1e9+7;
inline long long ksm(register long long a,register long long b)
{
	register long long ans=1;
	while (b)
	{
		if (b&1)(ans*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return ans;
}
long long dp[1000][1<<8];//前i列当前列状态为j时产生冲突的方案数 
int a[100],b[100];
inline long long calc(register long long j,register long long k)
{
	register long long ans=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while (j)a[++a[0]]=j&1,j>>=1;
	while (k)b[++b[0]]=k&1,k>>=1;
	if (!a[0])a[0]=1;
	if (!b[0])b[0]=1;
	for (register int i=1;i<a[0]||i<=b[0];++i)
	if (a[i]&&!b[i])++ans;
	return ans;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	register long long n=fast_IO::read(),m=fast_IO::read();
	for (register int i=2;i<=m;++i)
		for (register int j=0;j!=(1<<n);++j)
			for (register int k=0;k!=(1<<n);++k)
			{
				if (calc(j,k>>1))
				{
					(dp[i][j]+=dp[i-1][k]-1+ksm(2,calc(j,k>>1)))%=mod;
				}
			}
	register long long ans=0;
	for (register int i=0;i!=(1<<n);++i)(ans+=dp[n][i])%=mod;
	printf("%I64d",(ksm(2,n*m)-ans+mod)%mod);
	return 0;
}
