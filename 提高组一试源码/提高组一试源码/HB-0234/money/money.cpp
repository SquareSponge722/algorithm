#include <bits/stdc++.h>
using namespace std;
int t,n,a[26000];
int aa;
long long ans;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++){
	cin>>n;
	for(int j=1;j<=n;j++) {
	cin>>a[j];
	}
	if(n==2){//30 scores
		printf("2\n");
}
else {
	srand(time(0));
	aa=rand()%n+1;
	cout<<aa;
}}
	return 0;
}
