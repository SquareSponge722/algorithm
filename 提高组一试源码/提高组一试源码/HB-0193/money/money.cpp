#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,ans=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
int t;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while(t--){
		int n,a[110],ans=0;
		int vis[25010];
		int vis2[25000];
		int vis3[25000];
		int mjc[2050];
		n=read();
		ans=n;
		int x=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			a[i]=read();
			mjc[a[i]]=1;	
		}
		sort(a+1,a+n+1);
		if(n==2){
			if(a[2]%a[1]==0) printf("1\n");
			else printf("2\n");
		}
		if(n==3){
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){	
					if(a[i]%a[j]==0){
						if(vis[a[j]]) continue;
						vis[a[i]]=1;
						ans--;
					} 
				}
			}
	//		cout<<ans<<endl;
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int k=0;k<=n;k++){
						if(!mjc[a[i]+a[j]+a[k]])
						vis3[++x]=a[i]+a[j]+a[k];
					}
				}
			}
			sort(vis3+1,vis3+x+1);
			int v=unique(vis3+1,vis3+x+1)-vis3-1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=v;j++){
					if(vis3[j]==0) continue;
					if(a[i]%vis3[j]==0&&!vis[a[i]]){
					ans--;
		//				cout<<i<<" "<<j<<endl;
				}
			}
		}
			printf("%d\n",ans);
		}
		if(n==4){		
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){	
					if(a[i]%a[j]==0){
						if(vis[a[j]]) continue;
						vis[a[i]]=1;
						ans--;
					} 
				}
			}
	//		cout<<ans<<endl;
		for(int m=1;m<=n;m++)
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int k=0;k<=n;k++){
						if(!mjc[a[i]+a[j]+a[k]+a[m]])
						vis3[++x]=a[i]+a[j]+a[k]+a[m];
					}
				}
			}
			sort(vis3+1,vis3+x+1);
			int v=unique(vis3+1,vis3+x+1)-vis3-1;
	//		for(int i=1;i<=v;i++)
	//			cout<<vis3[i]<<endl;
			for(int i=1;i<=n;i++){
				for(int k=0;k<=n;k++)
				for(int q=0;q<=n;q++)
				for(int w=0;w<=n;w++)
				for(int r=0;r<=n;r++)
				for(int j=1;j<=v;j++){
					if(vis3[j]==0) continue;
					if((a[i]-a[k]-a[q]-a[w]-a[r])<0) continue;
					if((a[i]-a[k]-a[q]-a[w]-a[r])%vis3[j]==0&&!vis[a[i]]){
					ans--;
		//				cout<<i<<" "<<j<<endl;
				}
			}
		}
			printf("%d\n",ans);
		}
		if(n==5)		
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){	
					if(a[i]%a[j]==0){
						if(vis[a[j]]) continue;
						vis[a[i]]=1;
						ans--;
					} 
				}
			}
	//		cout<<ans<<endl;
	for(int p=0;p<=n;p++)
		for(int q=0;q<=n;q++)
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int k=0;k<=n;k++){
						if(!mjc[a[i]+a[j]+a[k]+a[p]+a[q]])
						vis3[++x]=a[i]+a[j]+a[k]+a[p]+a[q];
					}
				}
			}
			sort(vis3+1,vis3+x+1);
			int v=unique(vis3+1,vis3+x+1)-vis3-1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=v;j++){
					if(vis3[j]==0) continue;
					if(a[i]%vis3[j]==0&&!vis[a[i]]){
					ans--;
		//				cout<<i<<" "<<j<<endl;
				}
			}
		}
		//	printf("%d\n",ans);
		}
	}

		
