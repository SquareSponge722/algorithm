//chf sj ycy -||- 
#include<bits/stdc++.h>

using namespace std;

#define rep(i,x,y) for(register int i=x;i<=y;i++)
#define rrep(i,x,y) for(register int i=x;i>=y;i--)

typedef long long ll;
typedef double db;

const int maxn=1e5;

int n;
int a[maxn+10];
ll Ans=0; 

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void work()
{
	n=read();
	rep(i,1,n)
	{
		a[i]=read();
		if(i==1) Ans+=1LL*a[i];
		else if(a[i]<=a[i-1]) continue;
		else Ans+=1LL*(a[i]-a[i-1]);
	}
	printf("%lld\n",Ans);
} 

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	work();
	return 0;
}
