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

void reads(int &x){
	int fx=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fx=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	x=fx*x; //Õý¸ººÅ 
}

int a[519],f[50019],n;

//¸´ÔÓ¶È£º100*25000*20 

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T; reads(T); while(T--){ 
		reads(n); int ans=0; 
	    memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) reads(a[i]);
		sort(a+1,a+n+1); int maxx=a[n]; f[0]=1;
		for(int i=1;i<=n;i++){
			if(f[a[i]]==1) continue;
			f[a[i]]=1; ans++;
			for(int j=a[i];j<=maxx;j++)
				f[j]|=f[j-a[i]];
		} printf("%d\n",ans);
	}
}
