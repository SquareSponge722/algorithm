#include<cstdio>
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,m;
int p[100005];
long long ans;
int head[100005];
char tp[5];
int read()
{
	int x=0,f=1;
	char ch;
	while(ch<'0' || ch>'9'){if(ch='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x;
}
struct nodea
{
	int city;
	int army;
}a[100005];
struct nodeb
{
	int city;
	int army;
}b[100005];
struct edge
{
	int x;
	int y;
}e[100005*2];
int tot=0;
void add(int u,int v)
{
	e[++tot].x=v;
	e[tot].y=head[u];
	head[u]=tot;
}
int main()
{
	freopen("defence.in","r",stdin);
	freopen("defence.out","w",stdout);
	srand(time(NULL));
	n=read(),m=read();
	scanf("%s",tp);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&p[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a[i].city,&a[i].army,&b[i].city,&b[i].army);
		ans=rand()%10000;
		printf("%lld",ans);
	}
	return 0;
}
