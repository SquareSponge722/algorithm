#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[101];
int kz[101];
//质数判断 
bool isprime(int a){
	for(int p=2;p<=sqrt(a);p++)
		if(a%p==0) return false;
	return true;
}
//公因数判断
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	int n,m;
	for(int u=1;u<=T;u++){
		memset(a,0,sizeof(a));
		memset(kz,0,sizeof(kz));
		cin>>n;
		bool k=false;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if(!isprime(a[i])) break;
			if(i==n) {
				k=true;
				cout<<n<<endl;
			}
		}
		bool e=false;
		if(!k){
			sort(a+1,a+n+1);
			bool ae=true;
			for(int i=n;i>=1;i--){	
				if(a[n]!=a[i]+n-i) ae=false;
			}
			if(ae) cout<<n<<endl;
			e=true;
		}
		if(!e&&!k){
			cout<<n+1<<endl;
		}
	}
	return 0;
}
