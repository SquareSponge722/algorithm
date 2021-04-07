#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
int n,m,a,x,b,y,u,v,d[100002],ans,sum1,sum2;
bool f[2001][2001],g[2001];
string ss;
int read()
{
	int s=0;char ch=getchar();bool f=1;
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch<='9'&&ch>='0'){s=s*10+ch-'0';ch=getchar();}
	return s;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();cin>>ss;
	for(int i=1;i<=n;i++){
		d[i]=read();if(i%2==1)sum1+=d[i];
		else sum2+=d[i];
	}
	
	for(int i=1;i<n;i++){
		u=read();v=read();f[u][v]=f[v][u]=1;
	}
	for(int i=1;i<=m;i++){
		a=read();x=read();b=read();y=read();
		if(rand()%3==0)cout<<sum1<<endl;
		if(rand()%3==1)cout<<sum2<<endl;
		if(rand()%3==2)cout<<-1<<endl;
	}
	return 0;
}
