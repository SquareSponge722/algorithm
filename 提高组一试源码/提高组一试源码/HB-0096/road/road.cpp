#include<cstdio>
#include<cmath>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;

void reads(ll &x){
	int fx=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fx=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	x=fx*x; //Õý¸ººÅ 
}

ll a[100519],n;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	reads(n); if(n==0){ cout<<0<<endl; return 0; }
	reads(a[1]); ll lastt=a[1],ans=a[1];
	for(ll i=2;i<=n;i++){ reads(a[i]); 
	    if(a[i]>lastt) ans+=a[i]-lastt,lastt=a[i];
		lastt=min(lastt,a[i]); //cout<<ans<<endl;
	} printf("%lld\n",ans); return 0;
}
