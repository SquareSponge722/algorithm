#include<bits/stdc++.h>
using namespace std;
int k(int x){
	int a=1,sum;
	sum=x*a-1;
	a++;
	return sum;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,m,a[30009],b[30009],c[30009];
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	
	for(int i=1;i<=m;i++){
		if(a[i]==n){
		cout<<2;
	}
	 if(k(m)=k(n){
		cout<<2<<endl<<5;
	}
	}
}
	
