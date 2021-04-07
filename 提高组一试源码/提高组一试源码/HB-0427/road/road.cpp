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
int d[N],last=1;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	register int n=fast_IO::read();
	for (register int i=1;i<=n;++i)d[i]=fast_IO::read();
	register int minn=0,l=0,r=0,ans=0;
	while (l!=n+1)
	{
		minn=1<<30,l=n+1,r=0;
		for (register int i=last;i<=n;++i)
		if (d[i])
		{
			last=l=i;
			break;
		}
		for (register int i=l;i<=n+1;++i)
		if (d[i]==0)
		{
			r=i-1;
			break;
		}
		else minn=min(minn,d[i]);
		for (register int i=l;i<=r;++i)d[i]-=minn;
		if (l!=n+1)ans+=minn;
	}
	printf("%d",ans);
	return 0;
}
