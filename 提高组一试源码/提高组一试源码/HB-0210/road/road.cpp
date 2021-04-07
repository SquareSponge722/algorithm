#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{  
			if(a[i]!=0) {
				ans++;
			a[i]-=1;	
			}
			else {
				for(int j=0;j<i;j++) 
					for(int k=i+1;k<=n;k++)
					if(a[j]==0&&a[k]==0) break;
					else if (a[j]!=0&&a[k]!=0) {
						ans++;
						a[j]-=1;
					}
					else if(a[j]=0&&a[k]!=0){
						ans++;
						a[k]-=1;
					}
					else if(a[j]!=0&&a[k]==0){
						ans++;
						a[j]-=1;
					}
					}
					
			}
		cout<<ans<<endl;
			return 0;
		}
	
