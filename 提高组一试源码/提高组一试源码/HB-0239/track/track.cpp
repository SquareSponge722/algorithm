#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node_ {
	int v,c,next;
} node[100005];
int head[50005],e;
void addnode(int u,int v,int c) {
	e++;
	node[e].c=c;
	node[e].v=v;
	node[e].next=head[u];
	head[u]=e;
}
int n,m;
bool flag1=1,flag2=1;
int cc[50005];
int sum=0;
bool check(int t) {
	int sum=0;
	int ans=0;
	for(int i=1; i<=n-1; i++) {
		if(sum+cc[i]>=t) {
			sum=0;
			ans++;
		} else {
			sum+=cc[i];
		}
	}
	if(ans>=m) return 1;
	else return 0;
}
bool b[50005];
bool check1(int t) {
	int ans=0;
	for(int i=n-1; i>=1; i--) {
		if(b[i])continue;
		if(cc[i]>=t) {
			b[i]=1;
			ans++;
		} else {
			for(int j=1; j<i; j++) {
				if(b[j])continue;
				if(cc[j]+cc[i]>=t) {
					b[j]=b[i]=1;
					ans++;
					break;
				}
			}
		}
	}
	if(ans>=m) return 1;
	else return 0;
}
int maxlen,poin;
int len=0;
void dfs(int t){
	b[t]=1;
	bool flag3=0;
	for(int i=head[t];i!=0;i=node[i].next){
		if(b[node[i].v])continue;
		flag3=1;
		len+=node[i].c;
		dfs(node[i].v);
		len-=node[i].c;
	}
	if(!flag3){
		if(len>maxlen){
			maxlen=len;
			poin=t;
		}
	}
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; i++) {
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		cc[i]=c;
		sum+=c;
		if(v!=u+1) flag2=0;
		if(u!=1) flag1=0;
		addnode(u,v,c);
		addnode(v,u,c);
	}
	if(flag1) {
		cc[0]=0;
		sort(cc,cc+n);
		if(m==1) {
			printf("%d",cc[n-1]+cc[n-2]);
		} else {
			int l=0,r=sum/m+1,mid;
			while(l<r) {
				for(int i=1;i<n;i++)b[i]=0;
				mid=(l+r+1)>>1;
				if(check1(mid)) l=mid;
				else r=mid-1;
			}
			printf("%d",l);
		}
	} else if(flag2) {
		int l=0,r=sum/m+1,mid;
		while(l<r) {
			mid=(l+r+1)>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d",l);
	}else{
		if(m==1){
			dfs(1);
			memset(b,0,sizeof(b));
			dfs(poin);
			printf("%d",maxlen);
		}
	}
	return 0;
}
