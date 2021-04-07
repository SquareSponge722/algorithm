#include<iostream>
#include<cstdio>
using namespace std;
int n,a[110],vis[110];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				cout<<1<<endl;
				f=1;
				break;
			}
		}
		if(f) continue;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(a[i]%a[j]==0) vis[i]=1;
				if(a[j]%a[i]==0) vis[j]=1;
			}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(!vis[i]&&!vis[j]&&!vis[k]&&a[k]>=a[i]*a[j]-a[i]-a[j]&&i!=j&&k!=i&&k!=j)
						vis[k]=1;
		int tot=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
				tot++;
		cout<<tot<<endl;
	}
	return 0;
}
