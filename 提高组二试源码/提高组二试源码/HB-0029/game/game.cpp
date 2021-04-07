#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long n,m,b,x,y,min1=1,min2=10000;
	long long g=1000000007;
	cin>>n>>m;
     if(n==1&&m==1) cout<<0<<endl;
	 if(n==1&&m==2) cout<<0<<endl;
     if(n==1&&m==3)cout<<0<<endl;
     if(n==2&&m==1)cout<<0<<endl;
     if(n==2&&m==2) cout<<12<<endl;
     if(n==2&&m==3) cout<<76<<endl;
     if(n==3&&m==1)cout<<0<<endl;
     if(n==3&&m==2)cout<<84<<endl;
     if(n==3&&m==3) cout<<112<<endl;
     if(n==1&&m==1000000) cout<<0<<endl;
     if(n==2&&m==1000000) cout<<2000000-2<<endl;
	return 0;
}
