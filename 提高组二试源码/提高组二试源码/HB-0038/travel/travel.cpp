#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,u,v;
bool f[5001],g[5001][5001]; 
int read()
{
	int s=0;char ch=getchar();
	while(ch>'9'||ch<'0'){
	ch=getchar();}
	while(ch<='9'&&ch>='0'){s=s*10+ch-'0';ch=getchar();}
	return s;
}
void ser(int k,int tot)
{
	if(tot==n)return;
	for(int i=2;i<=n;i++)
	{
		if(!f[i]&&g[k][i]){
//			for(int j=i;j<=n;j++)
//			if(g[k][j])g[i][j]=1;
			f[i]=1;cout<<i<<" ";tot++;g[k][i]=0;ser(i,tot);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		u=read();v=read();
		g[u][v]=g[v][u]=1;
	}
	cout<<1<<" ";
	ser(1,1);
	return 0;
}
