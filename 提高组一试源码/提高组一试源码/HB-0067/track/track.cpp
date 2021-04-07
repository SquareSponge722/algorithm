# include <cstdio>
# include <iostream>
# include <cstring>
# define N 105000
# define inf 0x3f3f3f3f
using namespace std;
inline int read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	
	int res=ch-48;
	
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-48;
	return res;
}
int n,m,cnt,boo;

int vis[N],dp[N],f[N];

struct edge{
	int v,w,next;
}e[N];	int head[N];

void add(int u,int v,int w){
	e[++cnt].next =head[u];
	e[cnt].v =v;
	e[cnt].w =w;
	head[u]=cnt;
}

void dfs(int s,int baba){
	int to;
	for(int i=head[s];i;i=e[i].next ){
		to=e[i].v ;
		if(to!=baba){
		dp[to]=max(dp[to],dp[s]+e[i].w );
		dfs(to,s);
		}
	}
}

int _find(int x)	{while(x!=f[x]) x=f[x]=f[f[x]];}
void _merge(int x,int y)	{f[_find(y)]=_find(x);}

void dfs1(int step,int left,int last){
	if(step>4)	return ;
	if(left==0){
		boo=1;
		return ;
	}
	for(int i=last;i<=2*cnt;i+=2){
		dfs1(step+1,left-e[i].w ,i);
	}
}

int check(int flag){
	dfs1(1,0,1);
	if(boo)	return 1;
	else return 0;
}

int main (){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	int u,v,w;
	int minn=inf,tot=0;
	for(int i=1;i<n;++i){
		u=read(),v=read(),w=read();
		minn=min(minn,w);
		tot+=w;
		vis[u]++;
		vis[v]++;
		add(u,v,w);
		add(v,u,w);
	}
	
	if(m==n-1){
		cout<<minn;
	}//直接最小值 
	
	else if(m==1){
		int root;
		for(int i=1;i<=n;++i)
			if(vis[i]==1)	{
				root=i;
				break;
			}
		dfs(root,0);
		int ans=0;
		for(int i=1;i<=n;++i){
			ans=max(ans,dp[i]);
		}
		for(int i=1;i<=cnt*2;++i){
			if(e[i].v ==root){
				ans=max(ans,e[i].w );
				break;
			}
		}
		cout<<ans;
	}//树形dp
	
	else {
		boo=0;
		tot/=3;
		int ans;
		for(int i=tot-1;i>=1;--i){
			if(check(i)){
				ans=i;
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
