#include<bits/stdc++.h>
using namespace std;
int need[15],a[15];
int n,T,tt;
int dfs(int need1){
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(!need[i]&&!need[j]){
				if(a[j]%a[i]==0){
					need1--;
					need[j]=1;
					continue;
				}
				for(int k=n/2-1;k<=n;k++){
					if(!need[k]&&i!=k&&j!=k){
						for(int e=0;e<=a[k]/a[i]+1;e++){
							for(int r=0;r<=a[k]/a[j]+1;r++){
								if(a[i]*e+a[j]*r==a[k]){
									need1--;
									need[k]=1;
									T=1;
									break;
								}
							}
							if(T) break;
						}
						if(T) break;	
					}
				}
			}
			T=0;
		}
	}
	return need1;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>tt;
	for(int w=1;w<=tt;w++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		cout<<dfs(n)<<endl;
		memset(need,0,sizeof(need));
	}
	return 0;
}
