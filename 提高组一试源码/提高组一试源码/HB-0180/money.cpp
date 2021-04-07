#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<algorithm>
using namespace std;
int n,a[110],vis[1200],can[1200],cansum,ans,T;
void Shai(int t){
	int sum=cansum; 
	for(int i=t;i<=1010;i+=t){
		for(int j=1;j<=sum;j++){
			if(!vis[i+can[j]]&&i+can[j]<1010){
				vis[i+can[j]]=1;
				can[++cansum]=can[j]+i;
			}
		}
		if(!vis[i]){vis[i]=1;can[++cansum]=i;}
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(can,0,sizeof(can)); cansum=0; ans=0;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1); 
		for(int i=1;i<=n;i++){
		//	cout<<"for£» "<<a[i]<<endl;
		//	cout<<a[i]<<endl;
		//	cout<<vis[a[i]]<<endl;
			if(!vis[a[i]]){ans++;Shai(a[i]);}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
