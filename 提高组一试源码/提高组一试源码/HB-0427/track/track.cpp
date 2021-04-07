#include <bits/stdc++.h>
const int N=1e5+10;
using namespace std;
namespace fast_IO{
	int read()
	{
		register int num=0;
		register char ch;
		register bool flag=false;
		while ((ch=getchar())==' '||ch=='\n'||ch=='\r');
		if (ch=='-')flag=true;else num=ch^48;
		while ((ch=getchar())!=' '&&ch!='\n'&&ch!='\r'&&~ch)
		num=(num<<1)+(num<<3)+(ch^48);
		if (flag)return -num;return num;
	}
};
int nt[N],b[N],p[N],num,w[N],du[N],q[N],dp[N];
bool flag[N],is=true,ok=true;
inline void add(register int z,register int y,register int x)
{
	b[++num]=y;w[num]=z;++du[x];
	nt[num]=p[x];p[x]=num;
	b[++num]=x;w[num]=z;++du[y];
	nt[num]=p[y];p[y]=num;
	if (x!=1&&y!=1)is=false;
	if (abs(x-y)!=1)ok=false;
}
inline bool cmp(register int a,register int b){return a>b;}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	register int n=fast_IO::read(),m=fast_IO::read();
	for (register int i=1;i!=n;++i)add(fast_IO::read(),fast_IO::read(),fast_IO::read());
	if (m==1)
	{
		register int head=0,tail=1,ans=0;
		for (register int i=1;i<=n;++i)if (du[i]==1)q[++head]=i,flag[i]=true;
		while (head>=tail)
		{
			register int k=q[tail++];
			register int e=p[k];
			flag[k]=false;
			while (e)
			{
				register int kk=b[e];
				if (flag[kk])ans=max(ans,dp[kk]+dp[k]+w[e]);
				if (du[kk]==1){e=nt[e];continue;}
				dp[kk]=max(dp[kk],dp[k]+w[e]);
				if (--du[kk]==1)q[++head]=kk,flag[kk]=true;
				e=nt[e];
			}
		}
		printf("%d",ans);
	}
	else if (is)
	{
		register int e=p[1],cnt=0,ans=1<<30;
		while (e)
		{
			register int k=b[e];
			dp[++cnt]=w[e];
			e=nt[e];
		}
		sort(dp+1,dp+cnt+1,cmp);
		for (register int i=m+1;i<=n&&m-(i-m)+1>=1;++i)dp[m-(i-m)+1]+=dp[i];
		for (register int i=1;i<=m;++i)ans=min(ans,dp[i]);
		printf("%d",ans);
	}
	return 0;
}
