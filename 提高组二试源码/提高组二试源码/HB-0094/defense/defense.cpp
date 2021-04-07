//defense
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#define MAXN 100100
using namespace std;
int n,m;
int next[MAXN],w[MAXN],book[MAXN];
int f[MAXN][2];

int read()
{
	char ch=getchar();
	int sum=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum;
}

int ask()
{
	f[1][1]=w[1];
	for(int i=1;i<n;++i)
	{
		if(book[i]==-1)
		{
			f[i+1][0]=f[i][1];
			f[i+1][1]=min(f[i][0],f[i][1])+w[i+1];
		}
		else if(book[i]==0)
		{
			if(book[i+1]==0)return -1;
			else 
			{
				f[i+1][1]=f[i+1][0]=f[i][0]+w[i+1];
				f[i+2][1]=f[i+1][1]+w[i+2];
				f[i+2][0]=f[i+1][1];
				++i;
			}
		}
		else 
		{
			f[i+1][1]=f[i][1]+w[i+1];
			f[i+1][0]=f[i][1];
		}
	}
	return book[n]==-1?min(f[n][0],f[n][1]):f[n][book[n]];
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
//	cin>>n>>m;
	char aa=getchar();
	while(aa!='A'&&aa!='B'&&aa!='C')aa=getchar();
	while(aa<'0'||aa>'9')aa=getchar();
	for(int i=1;i<=n;++i)
	w[i]=read();
	for(int i=1;i<n;++i)
	next[i]=read(),next[i]=read();
	int a,b,x,y;
	memset(book,-1,sizeof(book));
	for(int i=1;i<=m;++i)
	{
		a=read(),x=read(),b=read(),y=read();
		book[a]=x,book[b]=y;
		cout<<ask()<<endl;
		book[a]=-1,book[b]=-1;
	}
}
/*
4 3 A2
1 2 3 4
1 2
2 3
3 4
1 1 2 1

*/
