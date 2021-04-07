#include <iostream> 
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[1000],f[50000];

inline int read ()
{
	int s=0;
	char ch=getchar ();
	while (ch<'0'||ch>'9') ch=getchar ();
	while (ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar ();}
	return s;
}

void work ()
{
	int nmax=0,ans=0,x;
	for (int i=1;i<=n;i++) a[i]=read (),nmax=max (nmax,a[i]);
	for (int i=1;i<=nmax;i++) f[i]=0;
	sort (a+1,a+n+1);
	x=unique (a+1,a+n+1)-a-1;
	f[0]=1;
	for (int i=1;i<=x;i++) {
		if (f[a[i]]) continue;
		ans++;
		for (int j=0;j<=nmax-a[i];j++) {
			if (f[j]) f[j+a[i]]=1;
		}
	}
	cout<<ans<<'\n';
	return ;
}

int main ()
{
	freopen ("money.in","r",stdin);
	freopen ("money.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++) {
		cin>>n;
		work ();
	}
}
