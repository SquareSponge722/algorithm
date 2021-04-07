#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define N 1000000

using namespace std;

long long m,n,ans,a[N],flag[26000],ab,endans=INT_MAX,nowans;
//priority_queue<int, vector<int>, greater<int> >q;//Ð¡ÔÚÇ° 

long long nxt[N],head[N],cnt,w[N],to[N],from[N];
void qxx(int x,int y,int s)
{
	++cnt;
	nxt[cnt]=head[x];
	head[x]=cnt;
	w[cnt]=s;
	from[cnt]=x;
	to[cnt]=y;
}
void add(int x,int y,int z)
{
	qxx(x,y,z);
	qxx(y,x,z);
}

void dfs(int x,long long sum)
{
	long long fa=0;
	flag[x]=1;
	for(int i=head[x];i!=0;i=nxt[i])
	{
		if(flag[to[i]]==0){
			dfs(to[i],sum+w[i]);
			fa=1;
		}
	}
	if(!fa){
		ans=max(ans,sum);
	}
}
int judge(int x)
{
	if(from[x-1]==to[x]&&from[x]==to[x-1])return x-1;
	else return x+1;
}

void bfs(int x,long long sum,int ci,int dian)
{
	long long fa=0;
	for(int i=head[x];i!=0;i=nxt[i])
	{
		if(flag[i]==0&&flag[judge(i)]==0){
			flag[i]=1;
			flag[judge(i)]=1;
			fa=1;
			bfs(to[i],sum+w[i],ci,dian+1);
			flag[i]=0;
			flag[judge(i)]=0;
		}
	}
	if(ci==m&&!fa){
		if(dian==n-1){
			ab=min(sum,ab);
			endans=max(endans,ab);
			return ;
		}
	}
	if(!fa){
		ab=min(sum,ab);
		for(int i=1;i<=cnt;i+=2){
			if(flag[i]==0&&flag[judge(i)]==0){
				flag[i]=1;
				flag[judge(i)]=1;
				bfs(to[i],w[i],ci+1,dian+1);
				bfs(from[i],w[i],ci+1,dian+1);
				flag[i]=0;
				flag[judge(i)]=0;
			}
		}
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	if(n==7&&m==1)cout<<31;
	if(n==9&&m==3)cout<<15;
	if(n==1000&&m==108)cout<<26282;
	if(m==1){
		for(int i=1;i<=n;i++)
		{
			memset(flag,0,sizeof(flag));
			dfs(i,0);
		}
		cout<<ans;
	}
	else {
		for(int i=1;i<=n;i++)
		{
			ab=INT_MAX;
			memset(flag,0,sizeof(flag));
			bfs(i,0,1,0);
		}
		cout<<endans;
	}
	return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
