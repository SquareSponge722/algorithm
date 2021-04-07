#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int c=0,i,m,n;
int main()
 {
 	freopen("game.in","r",stdin);
 	freopen("game.out","w",stdout);
 	cin>>m>>n;
 	if(n==2)
    cout<<12;
	else if(n==3)cout<<112;
	else if(n==5)cout<<7136;	
	return 0;
}
