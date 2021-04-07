#include<bits/stdc++.h>
using namespace std;

void splay()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
}

int i1,i2;char ch;
inline int read()
{
	i1=i2=ch=0;
	while(!isdigit(ch))	i1|=ch=='-',ch=getchar();
	while(isdigit(ch))	i2=(i2<<1)+(i2<<3)+(ch^48),ch=getchar();
	return i1? -i2:i2;
}
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define derep(i,j,k) for(int i=j;i>=k;i--)
#define pic(i,j) for(int i=lin[j];i;i=e[i].nxt)

bool can_be_[500000000];
int n,a[101],tot,maxx;

int main()
{
	splay();
	
	int T=read();
	while(T--)
	{
		n=read();
		memset(can_be_,0,sizeof(can_be_));
		can_be_[0]=1;
		rep(i,1,n) a[i]=read();
		sort(a+1,a+1+n);
		
		if(a[1]==1) {puts("1");continue;}
		if(n==1) {puts("1");continue;}
		if(n==2) {puts("2");continue;}
		
		tot=0;
		maxx=a[n]*a[n-1]-a[n]-a[n-1];
		rep(k,1,n)
		{
			if(can_be_[a[k]]) continue;
			tot++;
			rep(i,a[k],maxx) can_be_[i]|=can_be_[i-a[k]];
		}
		
		printf("%d\n",tot);
	}
	
	return 0;
}
