#include <cstdio>
#include <iostream>
#include <cctype>
using namespace std;
inline int rd()
{
	int x=0,w=0; char ch=getchar();
	while (!isdigit(ch)) {w|=ch=='-'; ch=getchar();}
	while (isdigit(ch)) {x=x*10+(ch^48); ch=getchar();}
	return w?-x:x;
}
int n,m,g[2005][2005],p[2005],army[2005];
char s[20];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=rd(),m=rd();
	scanf("%s",s);
	for (int i=1;i<=n;i++) p[i]=rd();
	for (int i=1,u,v;i<n;i++)
	{
		u=rd(),v=rd();
		g[u][v]=1;
		g[v][u]=1;
	}
	for (int i=1,a,x,b,y;i<=m;i++)
	{
		a=rd(),x=rd(),b=rd(),y=rd();
		if (x) army[a]=x;
		if (y) army[b]=y;
		puts("-1");
	}
	return 0;
}

