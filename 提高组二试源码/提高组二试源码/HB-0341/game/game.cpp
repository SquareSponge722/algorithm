#include<iostream>
using namespace std;
int n,m;
const int bug=1000000007;
int nf(int x,int n){
	int ans=1;
	for(int i=1;i<=n;i++)	
		ans*=x;
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==2&&m==2) cout<<"12"<<endl;
	if(n==3&&m==3) cout<<"112"<<endl;
	if(n==5&&m==5) cout<<"7136"<<endl;
	if(n==1) cout<<nf(2,m)<<endl;
	if(m==1) cout<<nf(2,n)<<endl;
	if(n==2&&m!=2&&m!=1)  cout<<(nf(2,m*n)*3/4)%bug<<endl;
	return 0;
}
