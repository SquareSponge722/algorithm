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
const int N = 1e5+10;
int nt[N],b[N],p[N],num,ling;
bool flag[N],past[N];
inline void add(register int x,register int y)
{
	b[++num]=y;nt[num]=p[x];p[x]=num;
	b[++num]=x;nt[num]=p[y];p[y]=num;
}
inline void dfs(register int x,register int fa)
{
	printf("%d ",x);past[x]=true;
	register int e=p[x],minn=1<<30;
	while (e)
	{
		register int k=b[e];
		if (!past[k]&&k<minn)minn=k;
		e=nt[e];
	}
	if (minn>1e9)return;
	dfs(minn,x);
	while (minn<1e9)
	{
		e=p[x],minn=1<<30;
		while (e)
		{
			register int k=b[e];
			if (!past[k]&&k<minn)minn=k;
			e=nt[e];
		}
		if (minn>1e9)return;
		dfs(minn,x);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	register int n=fast_IO::read(),m=fast_IO::read();
	while (m--)add(fast_IO::read(),fast_IO::read());
	dfs(1,0);
	return 0;
}
