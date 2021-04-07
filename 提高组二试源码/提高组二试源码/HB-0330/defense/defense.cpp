#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define R register
using namespace std;

int n,m,_map[100001][100001],p[100001];
string inputtemp;

inline int read(){
	int x(0),f(1);char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;	c=getchar();}
	while(c>='0'&&c<='9')	{x=x*10+c-'0';	c=getchar();}
	return x*f;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
	for(R int i=1;i<=n;i++)	p[i]=read();
	for(R int i=1;i<=n-1;i++){
		int a(read()),b(read());
		_map[a][b]=1,_map[b][a]=1;
	}
	for(R int j=1;j<=m;j++){
		int a(read()),x(read()),b(read()),y(read());
	}
	return 0;	
}
