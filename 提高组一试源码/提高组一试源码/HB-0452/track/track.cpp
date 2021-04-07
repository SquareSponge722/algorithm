#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005;
int n,m,en,h[N],maxn,a[N],b[N],l[N];
bool bj1,bj2,bj3,vis2[N];

struct Edge1{
	int to,next,l;
}e1[N];

struct Edge2{
	int a,b,l;
}e2[N];

int read(){
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

void add1(int u,int v,int l){
	e1[++en].to=v;
	e1[en].l=l;
	e1[en].next=h[u];
	h[u]=en;
	
	e1[++en].to=u;
	e1[en].l=l;
	e1[en].next=h[v];
	h[v]=en;
}

void dfs1(int &cnt,int u,int tot){
	vis2[u]=1;
	for(int k=h[u];k!=0;k=e1[k].next){
		if(!vis2[e1[k].to])
		dfs1(cnt,e1[k].to,tot+e1[k].l);
	}
	if(tot>maxn){
		cnt=u;
		maxn=tot;
	}
	vis2[u]=0;
}

void dfs11(int u,int tot){
	vis2[u]=1;
	for(int k=h[u];k!=0;k=e1[k].next){
		if(!vis2[e1[k].to])
		dfs11(e1[k].to,tot+e1[k].l);
	}
	if(tot>maxn){
		maxn=tot;
	}
	vis2[u]=0;
}

void solve1(){
	int cnt=0;
	vis2[1]=1;
	dfs1(cnt,1,0);
	vis2[1]=0;
	maxn=0;
	dfs11(cnt,0);
	printf("%d\n",maxn);
}

bool cmp(Edge2 x,Edge2 y){
	return x.l<y.l;
}

bool work(int mid){
	int x1=1,x2=n-1,top=0;
	while(top<m){
		if(e2[x1].l>mid&&x1<x2){
			x1++;
			top++;
			continue;
		}
		while(e2[x1].l+e2[x2].l<mid&&x1<x2) x1++;
		x2--;
		top++;
		if(x1>=x2&&top<m) return false; 
	}
	return true;
}

void solve3(){
	sort(e2+1,e2+n,cmp);
	int l=0,r=500000000;
	while(l<r){
		int mid=(l+r)>>1;
		if(work(mid)){
			l=mid+1;
		}
		else r=mid;
	}
	printf("%d\n",l);
}

bool done(int mid){
	int tot=0,ans=0;
	for(int i=1;i<=n-1;i++){
		if(tot>=mid) ans++,tot=0;
		tot+=e1[i].l;
	}
	if(ans<m) return false;
	return true;
}

void solve2(){
	int l=0,r=500000000;
	while(l<r){
		int mid=(l+r)>>1;
		if(done(mid)){
			l=mid+1;
		}
		else r=mid;
	}
	printf("%d\n",l);
}

bool dfs(int u,int tot,int mid,int fa){
	vis2[u]=1;
	bool bj=0;
	if(tot>=mid){
		tot=0;
		fa=u;
	}
	for(int k=h[u];k!=0;k=e1[k].next){
		if(!vis2[e1[k].to]){
			if(dfs(e1[k].to,tot+e1[k].l,mid,fa)){
				vis2[u]=0;
				return true;
			}
			else {
				vis2[u]=0;
				if(tot==0){
					continue;
				}
				else return false;
			}
		}
	}
	
	if(tot<mid){
		return false;
	}
	
	return true;
}

bool check(int mid){
	for(int i=1;i<=n;i++){
		if(dfs(i,0,mid,i)) return true;
	}
	return false;
}

void baoli(){
	int l=0,r=500000000;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else r=mid;
	}
	printf("%d\n",l);
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	if(m==1) bj1=1;
	bj2=1;
	bj3=1;
	for(int i=1;i<n;i++){
		a[i]=read(),b[i]=read(),l[i]=read();
		if(b[i]!=a[i]+1) bj2=0;
		if(a[i]!=1) bj3=0;
	}
	if(bj1){
		for(int i=1;i<n;i++) add1(a[i],b[i],l[i]);
		solve1();
	}
	else if(bj3){
		for(int i=1;i<n;i++){
			e2[i].a=a[i];
			e2[i].b=b[i];
			e2[i].l=l[i];
		}
		solve3();
	}
	else if(bj2){
		for(int i=1;i<n;i++) add1(a[i],b[i],l[i]);
		solve2();
	}
	else {
		for(int i=1;i<n;i++) add1(a[i],b[i],l[i]);
		baoli();
	}
	
	return 0;
}
