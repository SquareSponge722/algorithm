#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read()
{
	char ch=getchar(),last=' ';ll ans=0;
	while(!isdigit(ch)) last=ch,ch=getchar();
	while(isdigit(ch)) ans=ans*10+ch-'0',ch=getchar();
	if(last=='-') ans=-ans;
	return ans;
}
const int N=300005;
int n,m;
string type;
int val[N];
struct node{
	int to,nxt;
}e[N*2];
int head[N],tot;
void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].nxt=head[x];
	head[x]=tot;
}
namespace task1
{
	ll solve(int l,int r)
	{
		if(l>r) return 0;
		if(l==r) return 0;
		ll ans1=0,ans2=0;
		for(int i=l;i<=r;i+=2) ans1+=val[i];
		for(int i=l+1;i<=r;i+=2) ans2+=val[i]; 
		return min(ans1,ans2);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();cin>>type;
	for(int i=1;i<=n;i++) val[i]=read();
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();		
		add(x,y),add(y,x);
	}
	if(type[0]=='A'){
		while(m--)
		{
		int a=read(),x=read(),b=read(),y=read();
		if(a>b) swap(a,b),swap(x,y);
		if(b-a==1&&x==0&&y==0) {puts("-1");continue;}
		ll ans=0;
		if(x==1&&y==1) {
			ans+=task1::solve(1,a-1);
			if(b-a>=3) ans+=task1::solve(a+1,b-1);
			ans+=task1::solve(b+1,n);
			ans+=val[a]+val[b];
		}
			if(!x&&(y)) {
			ans+=val[a-1];
			if(b!=a+1) ans+=val[a+1];
			ans+=task1::solve(1,a-2);
			if(b-a-1>=3) ans+=task1::solve(a+2,b-1);
			ans+=task1::solve(b+1,n);
			ans+=val[b];
		    }
		if(x&&(!y)) {
			ans+=val[a];
			ans+=task1::solve(1,a-1);
			if(b-1-a>=3) ans+=task1::solve(a+1,b-2);
			ans+=task1::solve(b+2,n);
			ans+=val[b+1];
			if(a!=b-1) ans+=val[b-1];
		    }
		if((!x)&&(!y)){
			ans+=val[a-1]+val[a+1]+val[b-1]+val[b+1];
			if(b-a==2) ans-=val[a+1];
			ans+=task1::solve(1,a-2);
			if(b-a>=5) ans+=task1::solve(a+2,b-2);
			ans+=task1::solve(b+2,n);
		}
		printf("%lld\n",ans);
	    }
	}
	else {
		while(m--)
		{
			int x=read(),a=read();int y=read(),b=read();
			cout<<val[x]+val[y]<<endl;
		}
	}
	return 0;
}
/*
8 8 A3
1 2 3 4 5 6 7 8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
3 0 7 0
3 0 7 1
3 1 7 0
3 1 7 1
4 0 5 0
4 0 5 1
4 1 5 0
4 1 5 1
*/
