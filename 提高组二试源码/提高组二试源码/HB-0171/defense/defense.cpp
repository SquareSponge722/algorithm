#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define rg register

using namespace std;

const int N=100000+10;
int n,m;
char type[3];
int w[N],cnt,head[N],nxt[N],to[N];
void qxx(int x,int y){
	++cnt;
	to[y]=cnt;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void add(int x,int y){qxx(x,y);qxx(y,x);}
int main(){
	
 	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,type);
	for(rg int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(rg int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}	
	for(int i=1;i<=m;i++){
		int ans=0;
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(strcmp(type,"A1")==0){
			bool flag[N];
			memset(flag,false,sizeof(flag));
			ans+=w[1];
			flag[1]=true;
			for(int i=2;i<=n;i++){
				if(i==b&&y==0){ans+=w[i-1]+w[i+1];flag[i-1]=flag[i+1]=true;}
				else if(i==b&&y==1){ans+=w[i],flag[i]=true;}
				else{
					if(w[i]<w[i-1]&&!flag[i]){ans+=w[i];flag[i]=true;}
					else {ans+=w[i-1];flag[i-1]=true;}
				}
			}
			cout<<ans<<endl;
			ans=0;
		}
		if(strcmp(type,"A2")==0){
			bool flag[N];
			memset(flag,false,sizeof(flag));
			if(x==0&&y==0)cout<<-1<<endl;
			else{
				if(x==0){ans+=w[b];flag[b]=true;}
				for(int i=1;i<=n;i++){
					if(w[i]<w[i+1]&&!flag[i]){ans+=w[i];flag[i]=true;}
					else if(w[i+1]<w[i]&&!flag[i+1]){ans+=w[i+1],flag[i+1]=true;}
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
	
}
