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
const int N = 2e5+10;
int nt[N],val[N],p[N],b[N],num,in[N],q[N],dp[N][2],tmpdp[N][2],tmpin[N],fa[N];
bool flag[N];
inline void add(register int x,register int y)
{
	b[++num]=y;nt[num]=p[x];p[x]=num;
	b[++num]=x;nt[num]=p[y];p[y]=num;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	register int n=fast_IO::read(),m=fast_IO::read();
	scanf("%*s");
	for (register int i=1;i<=n;++i)val[i]=fast_IO::read();
	for (register int i=1;i!=n;++i)add(fast_IO::read(),fast_IO::read());
	register int head=0,tail=1;
	q[++head]=1;flag[1]=true;
	while (head>=tail)
	{
		register int k=q[tail++];
		register int e=p[k];
		while (e)
		{
			register int kk=b[e];
			if (!flag[kk])
			{
				++in[k];fa[kk]=k;
				flag[kk]=true;
				q[++head]=kk;
			}
			e=nt[e];
		}
	}
	memcpy(tmpin,in,sizeof(tmpin));head=0;tail=1;
	for (register int i=1;i<=n;++i)if (!in[i])q[++head]=i;
	memset(dp,63,sizeof(dp));
	for (register int i=1;i<=n;++i)if (!in[i])dp[i][1]=val[i];
	while (head>=tail)
	{
		register int k=q[tail++];
		register int e=p[k];
		while (e)
		{
			register int kk=b[e];
			dp[kk][0]=min(dp[kk][0],dp[k][1]);
			dp[kk][1]=min(dp[kk][1],dp[k][0]+val[kk]);
			dp[kk][1]=min(dp[kk][1],dp[k][1]+val[kk]);
			if (!--in[kk])q[++head]=kk;
			e=nt[e];
		}
	}
	register int tmp1=1<<30,tmp2=1<<30;
	memcpy(tmpdp,dp,(sizeof(dp)));
	while (m--)
	{
		register int a=fast_IO::read(),x=fast_IO::read(),bb=fast_IO::read(),y=fast_IO::read();
		memcpy(in,tmpin,sizeof(in));
		head=0,tail=1;
		q[++head]=fa[a];
		if (fa[a]!=fa[bb])q[++head]=fa[bb];
		memcpy(dp,tmpdp,(sizeof(dp)));
		jh(dp[a][x^1],tmp1);jh(dp[bb][y^1],tmp2);
		while (head>=tail)
		{
			register int k=q[tail++];
			register int e=p[k];
			while (e)
			{
				register int kk=b[e];
				dp[kk][0]=dp[k][1];
				dp[kk][1]=dp[k][0]+val[kk];
				dp[kk][1]=min(dp[kk][1],dp[k][1]+val[kk]);
				if (!--in[kk])q[++head]=kk;
				e=nt[e];
			}
		}
		jh(dp[a][x^1],tmp1);jh(dp[bb][y^1],tmp2);
		printf("%d\n",min(dp[1][1],dp[1][0]));
	}
	return 0;
}
