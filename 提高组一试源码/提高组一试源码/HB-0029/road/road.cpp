#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	
	long long n,k=0,ans=0,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	if(a[i]>maxn) maxn=a[i];
	}

	for(long long i=1;i<=maxn;i++){
		for(long long j=1;j<=n;j++){
		if(a[j]>=i &&a[j-1]<i &&a[j+1]<i)	 ans++;
		 if(a[j]>=i&& a[j+1]>=i){
				j+=2;
				while(a[j]>=i){
					j++;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

