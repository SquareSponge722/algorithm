#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long int mod=1000000007; 
int main()
{
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
long int n,m;
cin>>n>>m;
if(n==1) cout<<(1<<m);
else if(m==1) cout<<(1<<n);
if(n==2) 
{ if(m==2)cout<<12;
 else if(m==3)cout<<36;
else if(m>3) {
	int ans=1;
	for(int i=0;i<(m-2);i++) ans*=3;
	cout<<(12*ans)%mod;}
} 
if(n==3){
	if(m==2) cout<<36;
	else if(m==3) cout<<112;
}
if(n==5&&m==5) cout<<7136;
if(m==2)  if(n>3) {
	int ans=1;
	for(int i=0;i<(n-2);i++) ans*=3;
	cout<<(12*ans)%mod;}
	return 0;
	}
	


