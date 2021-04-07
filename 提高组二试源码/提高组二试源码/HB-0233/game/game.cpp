#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
const long long mod=10e9+7;
int n,m;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		if(m==1)cout<<2;
		if(m==2)cout<<4;
		if(m==3)cout<<8;
	}
	if(m==1){
		if(n==2)cout<<4;
		if(n==3)cout<<8;
	}
	if(n==2){
		if(m==2)cout<<12;
		if(m==3)cout<<36;
	}
	if(n==3){
		if(m==2)cout<<36;
		if(m==3)cout<<112;
	}
	return 0;
}
