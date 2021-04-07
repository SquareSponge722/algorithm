#include<bits/stdc++.h>
#define add(x,y,val) edge[++cnt]=node(y,val,head[x]),head[x]=cnt
struct node {
	long long ver,val,to;
	node(long long ver=0,long long val=0,long long to=0):ver(ver),val(val),to(to) {}
};
struct Node {
	long long val,db;
};
using namespace std;
const long long MAXN=50010;
long long cnt=-1;
inline char nc() {
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
long long read() {
	long long x=0;
	char c=nc();
	while(!isdigit(c))c=nc();
	while(isdigit(c))x=x*10+c-48,c=nc();
	return x;
}
node edge[MAXN<<1];
long long head[MAXN],tot[MAXN],n,m;
long long hh,Val[MAXN];
Node df1s(long long u,long long fa);
bool cmp(long long a,long long b) {
	return a>b;
}
bool judge(long long x) {
	long long L=1,R=n,cc=0,lt=0;
	long long v=Val[L];
	while(L<R&&lt<2) {
		lt++;
		v+=Val[R];
		if(v>=x) {
			cc++,v=Val[++L];
			if(R==n)R++;
			lt=0;
		}
		R--;
	}
	if(cc<m)return false;
	return true;
}
bool judge2(long long x) {
	long long cc=0,r=0;
	long long v=0;
	do {
		v+=Val[++r];
		if(v>=x)cc++,v=0;
	} while(r<n);
	if(cc<m)return false;
	else return true;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.ans","w",stdout);
	memset(head,-1,sizeof(head));
	n=read(),m=read();
	long long u,ver,val,mm=0,nm=9999999999,SUM=0;
	for(long long i=1; i<n; i++) {
		u=read();
		ver=read();
		val=read();
		add(u,ver,val);
		add(ver,u,val);
		tot[ver]++;
		tot[u]++;
		Val[i]=val;
		mm=max(mm,Val[i]);
		nm=min(nm,Val[i]);
		SUM+=val;
	}
	for(long long i=1; i<=n; i++)if(tot[i]==1)hh++;
	if(n==0) {
		puts("0");
		return 0;
	}
	if(n==2) {
		cout<<mm<<endl;
		return 0;
	}
	if(hh==n-1) {
		sort(Val+1,Val+n,cmp);
		long long l=Val[n-1],r=Val[1]*m,mid;
		while(l<r) {
			mid=(l+r+1)>>1;
			if(judge(mid))l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
		return 0;
	}
	if(m==1) {
		Node P=df1s(1,0);
		P=df1s(P.db,0);
		cout<<P.val<<endl;
		return 0;
	} else {
		long long l=nm,r=SUM,mid;
		while(l<r) {
			mid=(l+r+1)>>1;
			if(judge2(mid))l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
		return 0;
	}
}
Node df1s(long long u,long long fa) {
	Node Ans,L;
	Ans.db=u;
	Ans.val=0;
	for(long long i=head[u]; i!=-1; i=edge[i].to)
		if(edge[i].ver!=fa) {
			L=df1s(edge[i].ver,u);
			if(Ans.val<L.val+edge[i].val)
				Ans.val=L.val+edge[i].val,Ans.db=L.db;
		}
	return Ans;
}
