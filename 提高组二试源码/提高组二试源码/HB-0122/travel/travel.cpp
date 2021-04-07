#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,t=0,b;
int e[5005][5005],vi[5005],h[5005];
inline int read()
{
	int q=0,w=0;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') q=1,c=getchar();
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}
inline void f(int x)
{
	for(int i=1;i<=n;i++)
	{
	if(e[x][i]==1&&vi[i]==0) cout<<i<<" ",vi[i]=1,f(i);
	}
	return ;
}
inline void huan(int x)
{	
	for(int i=1;i<=n;i++)
	{
	if(e[x][i-1]==1&&vi[i-1]==2) return ;
	if(e[x][i]==1&&vi[i]<2)
		{vi[i]++,e[i][x]=0;
		if(vi[i]==2) 
		t++,h[t]=i;
		if(t==1&&h[t]==i) 
		b=i;		
		huan(i);		
		}
	}
	return ;
}
inline void f2(int x)
{
	for(int i=1;i<=n;i++)
	{int flag=0;
	for(int j=1;j<=t;j++) if(h[j]==i) flag=1;
	if(vi[i]==0&&flag==0) cout<<i<<" ",vi[i]=1,f2(i);
	if(i==b&&vi[b]==0) for(int j=1;j<=t;j++) cout<<h[j]<<" ",vi[h[j]]=1;
	}
	return ;
}
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{int x,y;
	x=read();y=read();
	e[x][y]=e[y][x]=1;	
	}
	if(m==n-1)
	{
		cout<<1<<" ";vi[1]=1;
		f(1);return 0;		
	}
	if(m==n)
	{	
		huan(1);
		sort(h+2,h+t+1);
		memset(vi,0,sizeof(vi));
		f2(1);
	}
	return 0;
}
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
