#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
//bool can(int m,int mi){
//	for(int i=0;i<mi;i++)
//		for(int j=i+1;j<mi;j++)
//}
int solve(int n) {
	int sum=0;
	sort(a,a+n);
	for(int i=1; i<n; i++)
		if(a[i]%a[i-1]==0) sum++;
//		else if(have(a[i],i)) sum++;		
	return n-sum;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		fill(a,a+105,0);
		for(int i=0; i<n; i++) cin>>a[i];
		cout<<solve(n)<<endl;	
	}
	return 0;
}
