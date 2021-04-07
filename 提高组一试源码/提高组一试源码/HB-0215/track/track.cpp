#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

const int N=5000000;
int n,m;
int cnt,head[N],nxt[N],to[N],w[N],num,flag[N],in[N],maxv,maxn,fa[N],f[50005][105],h[N];
void qxx(int x,int y,int z){
	cnt++;to[cnt]=y;w[cnt]=z;nxt[cnt]=head[x];head[x]=cnt;
}
bool ju(int x){
	int zhi=0,o=0;
	for(register int i=1;i<=n-1;i++){
		if(zhi+h[i]>x){
			o++;
			zhi=0;
		}
		else
			zhi+=h[i];
	}
	if(o<m){
		return false;
	}
	else{
		return true;
	}
}
void dfs(int x){
	fa[x]=1;
	int kk=0,k=0;
	for(int i=head[x];i!=0;i=nxt[i]){
		if(w[i]>kk&&fa[to[i]]==0){
			kk=w[i];
			k=to[i];
		}
	}
	if(k==0&&kk==0){
		return ;
	}
	maxv+=kk;
	dfs(k);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int judge=0,jjj=0;
	for(register int i=1;i<=n-1;i++){
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		if(b!=a+1){
			judge=1;
		}
		h[a]=l;
		num+=l;
		in[a]++;in[b]++;
		qxx(a,b,l);qxx(b,a,l);
	}
	if(judge==0){
		int l=0,r=num;
		while(l<=r){
			int mid=(l+r)/2;
			if(ju(mid)){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		printf("%d",l);
		return 0;
	}
	if(m==1){
		int p=0,q=0;
		for(register int i=1;i<=n;i++){
			if(in[i]==2){
				int e=head[i];
				qxx(to[e],to[nxt[e]],w[e]+w[nxt[e]]);
				qxx(to[nxt[e]],to[e],w[e]+w[nxt[e]]);
			}
		}
		int llq=0,llp=0;
		for(register int i=1;i<=n;i++){
			if(in[i]==1){
				if(w[head[i]]>llq){
					llq=w[head[i]];
					llp=i;
				}
			}
		}
		dfs(llp);
		printf("%d",maxv);
	}
	return 0;
}
/*
6 3
1 2 4
2 3 5
3 4 2
4 5 4
5 6 3
*/
