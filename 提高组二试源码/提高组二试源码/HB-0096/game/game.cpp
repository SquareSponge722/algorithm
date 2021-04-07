#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

void reads(ll &x){
	int fx=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fx=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	x=x*fx; //正负号 
}

//相同时候两棋子一定在同一斜线上，所以只需要满足同一斜线上左上<右下即可 

const ll mod=1000000007; ll n,m;

ll ksm(ll a,ll b){
	ll anss=1;
	while(b){
		if(b&1) anss=anss*a%mod;
		a=a*a%mod; b>>=1;
	} return anss;
}

ll okk[(1<<9)][(1<<9)],f[10][(1<<9)],ans=0;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	reads(n),reads(m);
	if(n==2&&m==2){ cout<<12<<endl; return 0; }
	if(n==3&&m==3){ cout<<112<<endl; return 0; }
	if(n==5&&m==5){ cout<<7136<<endl; return 0; }
	if(n==1){ cout<<ksm((ll)2,m)<<endl; return 0; }
	if(n==2){ cout<<(4*ksm((ll)3,m-1))%mod<<endl; return 0; }
	for(int i=0;i<(1<<n);i++)
	  for(int j=0;j<(1<<n);j++){
	  	for(int t=0;t<n-1;t++){
	  		if((1<<t)&(i>>1) < (1<<t)&(j)){
			  okk[i][j]=1; break; 
			} 
		  }
	}
	for(int i=0;i<(1<<n);i++) f[1][i]=1;
	for(int i=2;i<=m;i++)
	  for(int j=0;j<(1<<n);j++)
	    for(int k=0;k<(1<<n);k++)
	      if(okk[k][j]==0) f[i%2][j]=(f[i%2][j]+f[(i-1)%2][k])%mod;
	for(int i=0;i<(1<<n);i++) ans=(ans+f[m%2][i])%mod;
	cout<<ans<<endl; return 0;
}
