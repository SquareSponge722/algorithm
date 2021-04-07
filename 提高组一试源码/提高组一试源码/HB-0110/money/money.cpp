#include<bits/stdc++.h>
using namespace std;

bool nonhuzhi(int a,int b){
	int x=a,y=b,c;
	while(x%y!=0){
		c=x;
		x=y;
		y=c%y;
	}
	if(y==1)
		return false;
	else
		return true;
}
int main(void){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	int n;
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans=0;
		int a[110];
		cin>>n;
		for(int m=1;m<=n;m++)
			cin>>a[m];
		for(int l=1;l<n;l++)
			for(int r=l+1;r<=n;r++)
				if(nonhuzhi(a[l],a[r]))
					ans++;
		cout<<n-ans<<endl;
		
	}
	
	return 0;
}
