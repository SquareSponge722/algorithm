#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
inline int read()
{
	register int a(0),p(1);register char ch=getchar();
	while((ch<'0'&&ch>'9')&&ch!='-') ch=getchar();
	ch=='-'?p=-1,ch=getchar():p;
	while(ch>='0'&&ch<='9') a=a*10+ch-48,ch=getchar();
	return a*p;
}
const int N=110;
int t,n,temp,a[N],maxn=0,cun[N];
inline int maax(int x,int y){return x<y?y:x;}
inline bool jian(int xx,int pre)
{
	if(pre==0) return false;
	int tt=(xx/cun[pre]);
	if(tt*cun[pre]==xx) return true;
	for(int i=tt;i>=0;i--) if(jian(xx-i*cun[pre],pre-1)) return true;
	return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();maxn=temp=0;
		for(int i=1;i<=n;++i) maxn=maax(maxn,a[i]=read());
		sort(a+1,a+1+n);
		if(n==2)
		{
			if(a[2]%a[1]==0) printf("1\n");
			else printf("2\n");
		}
		else
		{
			for(int i=1;i<=n;++i) if(!jian(a[i],temp)) cun[++temp]=a[i];
			printf("%d\n",temp);
		}
	}
	return 0;
}
