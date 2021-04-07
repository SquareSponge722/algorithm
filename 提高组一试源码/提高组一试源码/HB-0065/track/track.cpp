#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,tot=0,ans;
int pos;
int head[50010],next[50010],var[50010],e[50010];
int d[50010],vis[50010],size[50010];
void add(int x,int y,int z){
	var[++tot]=y;
	e[tot]=z;
	next[x]=head[x];
	head[x]=tot;
}
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=next[x]){
		int y=var[i];
		if(!vis[y]) dfs(y);
		ans=max(ans,d[y]+d[x]+e[i]);
		d[y]+=d[x];
	}
}
void dfs1(int x){
	vis[x]=1;
	int max_part=0;
	for(int i=head[x];i;i=next[x]){
		int y=var[i];
		if(!vis[y]) dfs1(y);
		size[y]+=size[x];
		max_part=max(max_part,size[y]);
	}
	if(max_part< n-size[x]){
		pos=x;
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
	}
	if(m==1){
		memset(vis,0,sizeof(0));
		memset(d,0,sizeof(d));
		dfs(1);
		printf("%d\n",ans);
		return 0;
	}
	else{
		memset(vis,0,sizeof(vis));
		size[1]=1;
		dfs1(1);
		for(int i=1;i<=n-1;i++){
			if(head[i]==pos )
			  	head[i]=0;
			if( next[i]==pos)
				next[i]=0;
		}
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++)
			if(!vis[i])
				dfs(i);
		printf("%d\n",ans);
	}
	return 0;
}
