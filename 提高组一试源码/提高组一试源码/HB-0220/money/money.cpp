#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10005],t[10005],b[10005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,T,m,sum1,sum2,min=10000;
	cin>>T;
	for (int j=1;j<=T;j++){
		cin>>n;
	    for (int i=1;i<=n;i++){
	    	cin>>a[i];
	        sum1+=a[i]*t[i];
		}
	    for (int k=1;k<=m;k++) {
	    	sum2+=b[k]*t[k];
		}
	}
	if (sum2==sum1){
		if (m<min) min=m;
		cout<<min<<" ";
	}
	return 0;
}
