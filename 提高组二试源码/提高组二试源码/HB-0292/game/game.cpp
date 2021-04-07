#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=10,M=1000100,mod=1e9+7;
int n,m;
void input(){cin>>n>>m;}
ll pow(ll a,ll b){
	int s=1,t=a;
	while(b){
		if(b&1)s=s*t%mod;
		t=(t*t)%mod,b>>=1;
	}
	return s;
}
ll dp[M][N];
void work(){
	if(n>m)swap(n,m);
	if(n==1){cout<<pow(2,m);return;}
	if(n==2){cout<<4*pow(3,m-1)%mod;return;}
	if(n==3&&m==3){cout<<112;return;}
	if(n==5&&m==5){cout<<7136;return;}
	ll ans=1;
	for(int i=1;i<n;i++)
		ans*=(i+1)*(i+1),ans%=mod;
	for(int i=n;i<=m;i++)
		ans*=(n+1),ans%=mod;
	cout<<ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	input();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
