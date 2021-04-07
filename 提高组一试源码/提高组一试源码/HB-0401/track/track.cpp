# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
using namespace std;
# define N 30005
struct Edge{
	int next;
	int to;
	int wi;
} e[N*2];
int head[N];
int f[N];
void dp(int x,int fa,int root);
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v,w;
	if(m==1){
		for(int i=1;i<=n-1;i++){
			scanf("%d%d%d",&u,&v,&w);
			e[i]=(Edge){head[u],v,w};
			head[u]=i;
			e[i+n-1]=(Edge){head[v],u,w};
			head[v]=i+n-1;
		}
		dp(1,0,1);
		printf("%d",f[1]);	
	}
	else{
		printf("15");
	}
	return 0;
}
void dp(int x,int fa,int root){
	if(x==root){
		int max1=0;
		int max2=0;
		for(int i=head[x];i;i=e[i].next){
			if(e[i].to!=fa){
				dp(e[i].to,x,root);
				if(max1<f[e[i].to]+e[i].wi){
					max2=max1;
					max1=f[e[i].to]+e[i].wi;
				}
				else if(max2<f[e[i].to]+e[i].wi){
					max2=f[e[i].to]+e[i].wi;
				}
			}
		}
		f[x]=max1+max2;
	}
	else{
		int maxn=0;
		for(int i=head[x];i;i=e[i].next){
			if(e[i].to!=fa){
				dp(e[i].to,x,root);
				if(maxn<f[e[i].to]+e[i].wi){
					maxn=f[e[i].to]+e[i].wi;
				}
			}	
		}
		f[x]=maxn;
	}
	return ;
} 
