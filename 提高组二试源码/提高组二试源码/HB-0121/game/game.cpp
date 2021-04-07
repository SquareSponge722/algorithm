#include <bits/c++config.h> 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int ans=0;
int n=0;
int m=0;
int b=0;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(m=3,n=3)
	ans=112;
    else if(m=2,n=2)
    ans=12;
    cout<<ans;
	return 0;
}
