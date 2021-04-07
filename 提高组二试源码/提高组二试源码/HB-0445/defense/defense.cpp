#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,ans=0;
int f[N][N]={0},p[N];
char rp[5];
bool vis[N]={0};

inline int read(){
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') k=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*k;
}//RP++

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=2;i++) cin>>rp[i];
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		f[u][v]=1;
	}	
	while(m--){
		int a,b,x,y;
		a=read(),x=read(),b=read(),y=read();
		if(a>b) swap(a,b),swap(x,y);
		if((x==0&&y==0)&&(f[a][b]||f[b][a])){
			puts("-1");continue;
		}
		if(rp[1]=='A'&&rp[2]=='3'){
			vis[a]=x,vis[b]=y;
			if(x) ans+=p[a];if(y) ans+=p[b];
			for(int i=2;i<=n;i++){
				if(a==1){
					if(x==1){vis[1]=1,i=2;continue;}
					if(x==0){vis[2]=1,i=3;ans+=p[2];continue;}
				}
				else if(i<n){
					if(vis[i-1]&&vis[i+1]) continue;
					if(!vis[i-1]&&vis[i+1]&&!vis[i])
						ans+=p[i-1]<p[i]?p[i-1]:p[i],vis[p[i-1]<p[i]?(i-1):i]=1;
					if(!vis[i+1]&&vis[i-1]&&!vis[i])
						ans+=p[i+1]<p[i]?p[i+1]:p[i],vis[p[i+1]<p[i]?(i+1):i]=1;
				}
				else if(i==n){
					if(!vis[n-1]) ans+=p[n]<p[n-1]?p[n]:p[n-1];
				}
			}
			printf("%d\n",ans);	continue;
		}
		else printf("19260817\n");
	}
	return 0;
}
