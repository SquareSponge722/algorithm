#include<bits/stdc++.h>
#define N 100010
#define	inf  0x3fffffff
#define ll long long
using namespace std;
ll n,a[N],cnt,min1=inf,cnt1;
ll ans;
bool flag;

void read(ll &x){
	int t = 1;x=0;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch == '-') t = -1;ch = getchar();}
	while(ch>='0'&&ch<='9'){x = (x<<3)+(x<<1)+ch^48;ch = getchar();}
	x*=t;
}

void get(ll l,ll r){
	if(l>r) return ;
	flag = 0;
	min1 = inf;
	for(ll i=l;i<=r;i++){
		if(min1>a[i]){
			cnt =  i;
			min1 = a[i];	
			if(min1==0) continue;
		}
	}
	ans+=min1;
	for(ll i=l;i<=r;i++){
		a[i] -= min1;
		if(a[i]!=0) flag = 1;
	}
	if(flag == 1){
		get(l,cnt-1),
		get(cnt+1,r);
	}
	else return ;	
}

int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);	
	for(ll i=1;i<=n;i++){
		read(a[i]);
		if(min1>a[i]){
			min1 = a[i];
			cnt1 = i;
		}
	}
	ans += min1;
	for(ll i=1;i<=n;i++){
		a[i]-=min1;
		if(a[i]!=0) flag = 1;
	}
	if(flag == 1){
		get(1,cnt1-1),
		get(cnt1+1,n);
	}
	printf("%lld",ans);
	return 0;
}
