//chf sj ycy -||-
#include<bits/stdc++.h>

using namespace std;

#define rep(i,x,y) for(register int i=x;i<=y;i++)
#define rrep(i,x,y) for(register int i=x;i>=y;i--)

typedef long long ll;
typedef double db;

//const int maxn=;

int n,m;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void work()
{
	n=read();m=read();
	rep(i,1,m) printf("-1\n");
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	work();
	return 0;
}
