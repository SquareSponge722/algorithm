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
int a[N],n,b[N],num[N],cnt;
bool flag[N],tmpflag[N],can[N];
inline bool dfs(register int x,register int fa)
{
	if (can[x])return true;
	if (tmpflag[x]&&x!=fa)return can[x]=true;
	for (register int i=1;num[i]<x;++i)
	if (dfs(x-num[i],fa)&dfs(num[i],fa))return can[x]=true;
	return false;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	register int T=fast_IO::read();
	while (T--)
	{
		n=fast_IO::read();cnt=0;
		register int maxn=0,tot=0;
		memset(flag,0,sizeof(flag));
		memset(can,0,sizeof(can));
		for (register int i=1;i<=n;++i)flag[a[i]=fast_IO::read()]=true;
		memcpy(tmpflag,flag,sizeof(flag));
		for (register int i=1;i<=n;++i)maxn=max(maxn,a[i]);
		sort(a+1,a+n+1);
		for (register int i=1;i<=n;++i)
		{
			num[++cnt]=a[i];
			for (register int j=2;a[i]*j<=maxn;++j)
			{
				if (flag[a[i]*j])flag[a[i]*j]=false;
				tmpflag[a[i]*j]=true;
				num[++cnt]=a[i]*j;
			}
		}
		sort(num+1,num+cnt+1);
		for (register int i=1;i<=n;++i)
			if (flag[a[i]])b[++tot]=a[i];
		register int ans=tot;
		for (register int i=1;i<=tot;++i)
			if (dfs(b[i],b[i]))--ans;
		printf("%d\n",ans);
	}
	return 0;
}
