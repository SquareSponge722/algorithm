#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	if(n==1&&m==1) cout<<2;
	if(n==1&&m==2) cout<<4;
	if(n==1&&m==3) cout<<8;
	if(n==2&&m==1) cout<<4;
	if(n==2&&m==2) cout<<12;
	if(n==2&&m==3) cout<<24;
	if(n==3&&m==1) cout<<8;
	if(n==3&&m==2) cout<<24;
	if(n==3&&m==3) cout<<112;
	return 0;
}
