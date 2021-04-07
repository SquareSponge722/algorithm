#include<bits/stdc++.h>
using namespace std;

//5·ÖÖÓÏ¹Ð´²úÎï QAQ 

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		int n,a[102],ans;
		cin>>n;
		ans=n;
		for(int i=1; i<=n; i++)   cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=2; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				int k1=a[i]%a[j];
				int k2=a[i]-a[j]*(a[i]/a[j]);
				for(int h=1; h<=i; h++) {
					if(k1==0 && a[i] != 0 && a[j] != 0) {
						a[i]=0;
						ans--;
					}
					if(k2%a[h] == 0 && a[h] != 0 && a[i] != 0) {
						a[i]=0;
						ans--;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
