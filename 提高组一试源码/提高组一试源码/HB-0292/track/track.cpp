#include<cstdio>
#include<iostream>
#include<algorithm>
char buff[100010],*PA(buff),*PB(buff);
#define gc PA==PB&&(PA=buff,PB=fread(buff,1,100000,stdin)+buff,PA==PB)?EOF:*PA++
#define REP(i,u,v) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
using namespace std;
const int N=50001,INF=0x7fffffff;
int getint(){
	char ch__=gc;
	int s__=0,f__=1;
	while(ch__<'0'||ch__>'9')
		f__=(ch__=='-')?-1:1,ch__=gc;
	while(ch__<='9'&&ch__>='0')
		s__=s__*10+ch__-48,ch__=gc;
	return s__*f__;
}
struct edge{
	int t,w,n;
}e[N<<1];
int h[N],tot,n,m,sum,minn=INF,need;
bool flag=false;
int pre[N];
int du[N];
void add_edge(){
	int x,y,w;
	x=getint();y=getint();w=getint();
	e[++tot]=(edge){y,w,h[x]};h[x]=tot;
	e[++tot]=(edge){x,w,h[y]};h[y]=tot;
	sum+=w;
	if(minn>w)minn=w;
}
void input(){
	n=getint();m=getint();
	if(m==n-1)flag=true;
	for(int i=1;i<n;i++)add_edge();
}
void init(int u){
	du[u]=1;
	REP(i,u,v)
		if(pre[u]!=v)
			pre[v]=u,du[u]++,init(v);
}
int dfs(int u){
	int a[du[u]],qwq=0;
	bool b[du[u]];a[0]=0;
	REP(i,u,v)
		if(pre[u]!=v)
			a[++qwq]=dfs(v)+e[i].w,b[qwq]=false;
	sort(a+1,a+1+qwq);
	while(qwq&&a[qwq]>=need)
		qwq--,sum++;
	if(qwq==0)return 0;
	int l=1,r=qwq,out,val=0;
	while(l<r){
		while(l<r&&a[l]+a[r]<need)l++;
		if(l==r)break;
		val++;
		b[l++]=true;r--;
	}
	sum+=val;
	int i=1,j;
	for(int num=0;num<val;i++)
		if(b[i])num++;
	j=i--;
	while(val--){
		while(a[i]+a[j]<need)j++;
		a[i--]=a[j++]=0;
	}
	for(i=qwq;i;i--)
		if(a[i])return a[i];
	return 0;
}
bool check(int orz){
	sum=0,need=orz;
	dfs(1);
	return sum>=m;
}
void work(){
	if(flag)cout<<minn;
	else{
		int l=minn,r=sum/m,mid;
		while(mid=(l+r)>>1,l!=r)
			if(check(mid+1))l=mid+1;
			else r=mid;
		cout<<l;
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	input();
	init(1);
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
