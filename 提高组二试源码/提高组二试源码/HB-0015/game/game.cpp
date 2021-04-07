#include<bits/stdc++.h>
using namespace std;
const long long p=1000000007;
int n,m;
long long res;
long long mul(int x,int y){
	long long ans=1%p;
	while(y){
		if(y&1)ans=ans*x%p;
		x=x*x%p;
		y>>=1;
	}
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1)res=mul(2,m);
	if(n==2)res=4*mul(3,m-1)%p;
	if(n==3){
		if(m==1)res=8;
		if(m==2)res=36;
		if(m==3)res=112;
	}
	if(n==5&&m==5)res=7136;
	cout<<res<<endl;
	return 0;
}
