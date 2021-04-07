#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int i,n,l,s,maxa,mina;
string a;
int main()
 {
 	freopen("money.in","r",stdin);
 	freopen("money.out","w",stdout);
 	cin>>n;
 	for(i=1;i<=n;i++)
 	cin>>l>>a;
 	for(i=0;i<l;i++)
 	sort(a[0],a[l-1]);
 	if(maxa%mina==1)cout<<2;
 	else if(maxa%mina!=1)cout<<(maxa%mina);
	return 0;
}
