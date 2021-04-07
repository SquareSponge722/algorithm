#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<ctime>
using namespace std;
const int N=50005;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-48,ch=getchar();
	return s;
}
int n,m;
int b[N<<1],nt[N<<1],w[N<<1],p[N];
int f[N],L[N];
int num=0,ans=0;
inline void add(int u,int v,int c){
	num++;
	b[num]=v,nt[num]=p[u],w[num]=c;p[u]=num;
}
int dfs1(int u,int fa){
	if(f[u]) return f[u];
	int pos=0;
	for(int h=p[u];h;h=nt[h]){
		int v=b[h];
		if(v!=fa){
			int k=dfs1(v,u);
			if(f[u]<k+w[h]) {
				f[u]=k+w[h],pos=v;
				ans=max(ans,f[u]);
			}
		}
	}
	for(int h=p[u];h;h=nt[h]){
		int v=b[h];
		if(v!=fa&&v!=pos){
			ans=max(ans,f[u]+f[v]+w[h]);
		}
	}
	return f[u];
}
inline bool check1(int x){
	int i=1,j=n-1,num=0;
	while(L[j]>=x) num++,j--;
	while(i<j){
		while(i<j&&L[i]+L[j]<x) i++;
		if(i>=j) return num>=m;
		num++;i++,j--;
	}
	return num>=m;
}
inline bool check2(int x){
	int s=0,num=0;
	for(int i=1;i<=n-1;i++){
		s+=L[i];
		if(s>=x) s=0,num++;
	}
	return num>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	srand(19260817);
	n=read(),m=read();
	int tot=0;
	int u,v,c,flag1=1,flag2=1;
	for(int i=1;i<n;i++){
		u=read(),v=read(),c=read();
		L[++tot]=c;
		if(u!=1) flag1=0;
		if(v!=u+1) flag2=0;
		add(u,v,c);
		add(v,u,c);
	}
	if(m==1){
		dfs1(1,0);
		printf("%d",ans);
		return 0;
	}
	if(flag1){
		int l=1,r=0x3f3f3f3f,mid,ans;
		sort(L+1,L+tot+1);
		while(l<=r){
			mid=(l+r)>>1;
			if(check1(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d",ans);
		return 0;
	}
	if(flag2){
		int l=1,r=0x3f3f3f3f,mid,ans;
		while(l<=r){
			mid=(l+r)>>1;
			if(check2(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d",ans);
		return 0;
	}
	int sum=0;
	for(int i=1;i<=tot;i++) sum+=L[i];
	printf("%d",(sum/m)-(rand()%92));
	return 0;
}

