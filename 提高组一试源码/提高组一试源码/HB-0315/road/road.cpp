#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010

struct pos
{
	int d;
	int l;
	int r;
} a[N];
int q[N];
int head=1,tail=0,n;
int mind=20000,posmin;
long long  ans;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x;
}
bool mycomp(const pos &a,const pos &b){
	return a.d<b.d;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i].d=read();
		if(a[i].d<mind) mind=a[i].d,posmin=i;
		a[i].l=a[i].r=i;
	} 
	for(int i=1;i<=n;i++){
		while(head<=tail && a[q[tail]].d>=a[i].d){
			a[i].l=q[tail];tail--;
		} 
		a[q[tail]].r=i;q[++tail]=i;a[q[head]].r=i;
	}
	a[posmin].l=1;
	
	for(int i=1;i<=n;i++) a[i].d-=mind;
	ans+=mind;
	for(int i=1;i<=n;i++){
		if(a[i].l!=i && a[i].r!=i){
			for(int j=a[i].l;j<=a[i].r;j++)	a[j].d-=a[i].d;
			ans+=a[i].d;
		}
		else if(a[i].l!=a[i].r){
			ans+=a[i].d;
			for(int j=a[i].l;j<=a[i].r;j++) a[j].d-=a[i].d;
		}
	}
	for(int i=1;i<=n;i++){
		ans+=a[i].d;
	}
	cout<<ans;
	return 0;
}
