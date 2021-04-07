#include<cstdio>
#include<algorithm>
#define ll long long
#define FOR(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
const int INF=1e9+7;
int fa[5005][105],num[5005];
bool book[5005];

int read()
{
	int p=1,q=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0'&&c<='9'){q=q*10+c-'0';c=getchar();}
	return p*q;
}

void dfs(int x)
{
	FOR(i,1,num[x]){
		if(!book[fa[x][i]]){
			book[fa[x][i]]=1;
			printf(" %d",fa[x][i]);
			dfs(fa[x][i]);
		}
	} 
}

/*void Dfs(int x,int y)
{
	FOR(i,1,num[x]){
		if(!book[fa[x][i]]&&fa[x][i]<y){
			book[fa[x][i]]=1;
			printf(" %d",fa[x][i]);
			Dfs(fa[x][i],fa[x][i+1]==0?INF:fa[x][i+1]);
		}
		else if(!book[fa[x][i]])return;
	}
}*/

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read();
	printf("1");
	int u,v;
	FOR(i,1,m){
		u=read(),v=read();
		fa[u][++num[u]]=v;
		fa[v][++num[v]]=u;
	}
	FOR(i,1,n)sort(fa[i]+1,fa[i]+num[i]+1);
	book[1]=1;
	dfs(1);
/*	if(m==n-1)dfs(1);
	else Dfs(1,INF);*/
	return 0;
}
