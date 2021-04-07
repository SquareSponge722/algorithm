#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define R register
using namespace std;

int nowmin,knocked,n,m,answer[5001],went[5001],_map[5001][5001];
int bmin[5001][5001],bminnum[5001]={0};

inline void findbmin(int x){
	int nowhave(0);
	for(R int i=1;i<=n;i++)
		if(_map[x][i]==1){
			bmin[x][nowhave+1]=i;
			++nowhave;
		}
	bminnum[x]=nowhave;
	return;
}

inline void dfs(int x){
	if(knocked==n)	return;
	if(went[x]==0){
		went[x]=1;
		++knocked;
	}
	for(R int i=1;i<=n;i++)
		if(_map[x][i]==1&&went[i]==0)
		{
			if(i<nowmin)
			{
				answer[knocked+1]=i;
				dfs(i);
			}
			else
			{
				answer[knocked+1]=nowmin;
				dfs(nowmin);
			}
		}
	if(n==m){
		for(R int i=1;i<=n;i++)
			for(R int j=1;j<=bminnum[i];j++)
				if(bmin[i][j]<nowmin)	nowmin=bmin[i][j];			
	}
	return;	
}

inline int read(){
	int x(0),f(1);char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;	c=getchar();}
	while(c>='0'&&c<='9')	{x=x*10+c-'0';	c=getchar();}
	return x*f;
}

int main()
{
	nowmin=5003;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	int smallest(5003);
	for(R int i=1;i<=m;i++){
		int a(read()),b(read());
		_map[a][b]=1,_map[b][a]=1;
		if(min(a,b)<smallest)	smallest=min(a,b);
	}
	if(m==n)	for(R int i=1;i<=5000;i++)	findbmin(i);
	for(R int i=1;i<=5000;i++)	findbmin(i);
	answer[1]=smallest;
	dfs(smallest);
	for(R int i=1;i<=n-1;i++)
		cout<<answer[i]<<" ";
	cout<<answer[n];
	return 0;	
}
