#include <bits/stdc++.h>
using namespace std;
#define N 51000
struct node{
	int to,v,nxt;
}e[N*2];
int head[N],n,m,ans,x,y,v,dis[N],tot,maxx,rt;
void add(int x,int y,int v){
	e[++tot].to=y;
	e[tot].nxt=head[x];
	e[tot].v=v;
	head[x]=tot;
} 
void dfs(int u,int f){
	for(int i=head[u];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==f)
			continue;
		dis[to]=dis[u]+e[i].v;
		if(maxx<dis[to]){
			rt=to;
			maxx=dis[to];
		}
		dfs(to,u);
	}
}
bool check1(int v){
	int pos=1;
	int tot=0;
	for(int i=n;i>=1;i--){
		while(1){
			if(pos>=i)
				return false;
			if(dis[pos]+dis[i]>=v){
				tot++;
				if(tot==m)
					return true;
				if(pos!=1)
					pos++;
				break;
			}
			pos++;
		}
		
	}
	return false;
}
bool check2(int v){
	int tot=m;
	int now=0;
	while(tot--){
		if(now+v>maxx)
			return false;
		else{
			int pos=lower_bound(dis+1,dis+1+n,now+v)-dis;
			now=dis[pos];
		}
	}
	return true;
}
bool flag2,flag1;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	flag2=true;
	flag1=true;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&v);
		if(x+1!=y)
			flag2=false;
		if(x!=1)
			flag1=false;
		add(x,y,v);
		add(y,x,v);
	}
	if(m==1){
		dfs(1,0);
		dis[rt]=0;
		dfs(rt,0);
		ans=maxx;
		printf("%d",ans);
		return 0;
	}
	if(flag2){
		dfs(1,0);
		int l=0,r=50000000;
		while(l<r){
			int mid=(l+r)/2;
			if(check2(mid))	{
				l=mid+1;
				ans=mid;
			}
			else
				r=mid;
		}
		printf("%d",ans);
		return 0;
	}
	if(flag1){
		dfs(1,0);
		sort(dis+1,dis+1+n);
		int l=0,r=50000001;
		while(l<r){
			int mid=(l+r)/2;
			if(check1(mid))	{
				l=mid+1;
				ans=mid;
			}
			else
				r=mid;
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}
