#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<cstring>
#define ll long long
#define maxn 100005
#define inf 1e9
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return w==1?x:-x;
}

int d[maxn],n;
ll ans;

inline void solve(int l,int r,int lst)
{
	if(l>r) return;
	if(l==r) {ans+=(d[l]-lst); return;}
	int tmp=inf,flag=0,pre=l;
	for(int i=l;i<=r;i++) tmp=min(tmp,d[i]);
	ans+=(ll)(tmp-lst);
	for(int i=l;i<=r;i++) if(d[i]==tmp) solve(pre,i-1,tmp),pre=i+1;
	solve(pre,r,tmp);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++) d[i]=read();
	solve(1,n,0);
	cout<<ans<<endl;
	return 0;
}
