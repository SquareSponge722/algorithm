#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,a[100001]={0};
	int b,c=0;
	int x=0,sum;
	cin>>n;
	
	for(int i=0;i<=n;i++) {
		cin>>a[i];	
	for(int j=0;j<=n;j++){
	if(a[i]>=a[j]&&a[i]<=n&&a[j]<=n)
	b=a[i];
	c=a[j];
	
	}	
}
	cout<<n+b-c<<endl;
	return 0;
}
