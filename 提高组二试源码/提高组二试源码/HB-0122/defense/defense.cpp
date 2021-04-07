#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans,sum;
int p[2005],e[2005][2005],v[2005];
char ty[5];
inline int read()
{
	int q=0,w=0;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') q=1,c=getchar();
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);	
	n=read();m=read();cin>>ty+1;
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n-1;i++) 
	{int u,v;
	u=read();v=read();
	e[u][v]=e[v][u]=1;
	}
	for(int i=1;i<=m;i++)
	{int a,b,c,d;
	a=read();b=read();c=read();d=read();
	v[a]=b;v[c]=d;
	if(b>0) sum+=p[a];
	if(d>0) sum+=p[c];
	if(b==0&&d==0) {cout<<-1<<endl;break;}
	if(ty[1]=='A'&&ty[2]=='3') 
	{	
		for(int i=1;i<=n;i++)
		{
		if(v[i]==1) v[i-1]=v[i+1]=0;
		while(i-1>=1&&i+1<=c) 
		{sum+=p[i-2];
		i=i-2;
		}
		while(i+1>c&&i+1<n) 
		{sum+=p[i-2];
		i=i+2;
		}
		cout<<sum;
		return 0;
	}
	
	
	}
}
	return 0;
}
