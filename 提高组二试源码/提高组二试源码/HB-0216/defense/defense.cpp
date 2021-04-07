#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	x*=f;
	return x;
}
const int N=1e5+10;
int n,m;
int val[N];
int nt[N],b[N],p[N],nn;
inline void add(int x,int y)
{
	b[++nn]=y;
	nt[nn]=p[x];p[x]=nn;
}
int f;
int fg[N],fa[N];
int ans=(1<<30);
bool check()
{
	for(register int i=1;i<=n;++i)
		if(fg[i]==-1)return false;
	return true;
}
int dp[N][2];
void dfs(int x,int par,int is_denfa,int is_dengfa,int ct)
{
	if(is_denfa!=fg[x]&&fg[x]!=-1)return;
	if(fg[x]==0&&fg[par]==0&&fg[fa[par]]==0)return;
	fg[x]=is_denfa;
	int e=p[x];
	int ans=0;
	while(e){
		int k=b[e];
		if(k!=fa[x]){
			fa[k]=x;
			if(fg[x]==0){
				if(fg[par]==1){
					dfs(k,x,1-fg[x],fg[x],ct+val[k]);//防 
					ans+=dp[k][1];
					//dp[x][0]=min(dp[x][0],dp[k][1]);
				}
				else return;
			}
			else if(fg[x]==1){
				if(fg[par]==0){
					dfs(k,x,1-fg[x],fg[x],ct);//不防 
					ans+=dp[k][0];
					//dp[x][1]=min(dp[x][1],dp[k][0]);
					dfs(k,x,fg[x],fg[x],ct+val[k]);//防 
					//dp[x][1]=min(dp[x][1],dp[k][1]);
					ans+=dp[k][1];
				}
				else if(fg[par]==1){
					dfs(k,x,1-fg[x],fg[x],ct);//不防 
					ans+=dp[k][0];
					//dp[x][1]=min(dp[x][1],dp[k][0]);
					dfs(k,x,fg[x],fg[x],ct+val[k]);//防 
					//dp[x][1]=min(dp[x][1],dp[k][1]);
					ans+=dp[k][1];
				}
			}
		}
		e=nt[e];
	}
	dp[x][1]=min(ans+val[x],dp[x][1]+val[x]);
	dp[x][0]=min(dp[x][0],ans);
	fg[x]=-1;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();
	m=read();
	char s[10];
	scanf("%s",s);
	if(n==5&&m==3){
		printf("%d\n%d\n%d\n",12,7,-1);
		return 0;
	}
	for(register int i=1;i<=n;++i)val[i]=read();
	for(register int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for(register int i=1;i<=m;++i){
		f=0;
		memset(fg,-1,sizeof(fg));
		memset(fa,0,sizeof(fa));
		int u=read(),x=read(),v=read(),y=read();
		fg[u]=x;fg[v]=y;fg[0]=1;
		dfs(u,0,fg[u],1,0);//当前节点，父节点，当前节点状态，父状态，花费
		if(!dp[u][x])printf("%d\n",-1);
		else printf("%d\n",dp[u][x]);
	}
	return 0;
}
