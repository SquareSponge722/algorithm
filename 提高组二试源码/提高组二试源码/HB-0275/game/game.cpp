#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read()
{
	int k=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+c-'0';return f*k;
}
const int mod=1e9+7,N=1000055;
int n,m,f[N][2];
int cnt,a[500][20],s[500][20],b[20];
void dfs(int x,int y,int dep)
{
	b[dep]=a[x][y];
	if(x==m-1&&y==n-1)
	{
		cnt++;
		for(int i=1;i<=dep;i++)
			s[cnt][i]=b[i];
		return;
	}
	if(x<m-1) dfs(x+1,y,dep+1);
	if(y<n-1) dfs(x,y+1,dep+1);
}
bool cmp(int x,int y)
{
	for(int i=1;i<=n+m-1;i++)
		if(s[x][i]<s[y][i]) 
			return 1;
		else if(s[x][i]>s[y][i])
			return 0;
	return 1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n<=3&&m<=3)
	{
		int al=n*m,res=0;
		for(int i=0;i<(1<<al);i++)
		{
			cnt=0;
			for(int j=0;j<al;j++)
				a[j%3][j/3]=(i>>j)&1;
			dfs(0,0,1);
			int fl=1;
			for(int j=1;j<cnt;j++)
				if(!cmp(j,j+1))
					{fl=0;break;}
			res+=fl;
		}
		cout<<res<<endl;
		return 0;
	}
	if(n==2)
	{
		int as=1;
		for(int i=1;i<m;i++)
			as=3ll*as%mod;
		as=as*4%mod;
		printf("%d\n",as);
		return 0;
	}
	return 0;
}
