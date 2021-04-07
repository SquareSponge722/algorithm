#include<iostream>
#include<cstdio>
using namespace std;
int a[6],b[1005];
int main(){
	freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];
	for(int m=1;m<=n;m++){
		for(int k=1;k<=a[m];k++)cin>>b[k];
	}
	}cout<<n<<endl<<a[n];
	return 0;}
