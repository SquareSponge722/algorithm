#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int i,j,n,q,s[50001],a[50000],b[50000],c[50000],s1=0,m,e,s2=0;
int main()
 {
 	freopen("track.in","r",stdin);
 	freopen("track.out","w",stdout);
 	cin>>n>>q;
 	for(i=1;i<n;i++)
 	{cin>>a[50000]>>b[50000]>>c[50000];
 	for(j=1;j<=n;j++)
 	{if(a[j]==i||b[j]==i)s[i]+=1;}
 	if(s1<s[i]){s1=s[i];m=i;}}
 	for(i=0;i<s1-1;i++)
	 {if(a[i]==m||b[i]==m)e+=c[i];
	  s2+=e-min(c[0],c[m]);
	  } 
	  cout<<s2;
	return 0;
}
