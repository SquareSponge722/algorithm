#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define rep(k,i,j) for(int k = i;k <= j; ++k)
#define FOR(k,i,j) for(int k = i;k >= j; --k)
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
const int size = 1e5+5;
int d[size],dw[size],tp[size];
int n,minx;
ll ans = 0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	minx = inf;
	rep(i,1,n){
		d[i] = read();
		minx = min(minx,d[i]);
	}
	memset(dw,0,sizeof(dw));
	ans = minx;
	rep(i,1,n) d[i] -= minx;
	int tot1(0),tot2(0);
	rep(i,1,n){
		if(i!=1&&i!=n&&d[i]>d[i-1]&&d[i]>d[i+1]){
			tp[++tot1] = d[i];
		}else if(i==1&&d[i]>d[i+1]){
			tp[++tot1] = d[i];
		}else if(i==n&&d[i]>d[i-1])
			tp[++tot1] = d[i];
		if(d[i]<d[i-1] && d[i]<d[i+1]) dw[++tot2] = d[i];
		if(d[i]<dw[tot2]) dw[tot2] = d[i];
	}
//	rep(i,1,tot2) ans += dw[i]; 
	rep(i,1,tot1){
		int x;
		if(i!=1) x = max(dw[i-1],dw[i+1]); 
		int maxx = max(dw[i-1],dw[i]);
		ans += tp[i]-maxx;
		ans  += x;
 }/*
	rep(i,1,tot1) printf("%d ",tp[i]);
	puts("");
	rep(i,1,tot2) printf("%d ",dw[i]);
	printf("\n%d %d",tot1,tot2);*/
	printf("%lld\n",ans);
	return 0;
} 
