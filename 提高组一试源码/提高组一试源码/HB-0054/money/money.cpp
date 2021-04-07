#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=110;
int t,n;
int a[N],f[N];
int read ()
{
	int val=0;
	char c=getchar();
	while (c!=' ' && c!='\n')
	{
		if (c>='0'&&c<='9')
			val=val*10+(c-'0');
		c=getchar();
	}
	return val;
}
int main ()
{
	freopen ("money.in","r",stdin);
	freopen ("money.out","w",stdout);
	t=read ();
	while (t--)
	{
		n=read();
		for (int i=0; i<n; i++)
			a[i]=read ();
		sort (a,a+n);
		for (int i=1 ;i<n ;i++)
			for (int j=0; j<i; j++)
			{
				if(a[i]%a[j]==0)
					n--;
			}
		printf("%d\n",n);
	}
	return 0;
}
