#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,x,lim) for(i=(x);i<(lim);i++)
using namespace std;
const int N=110,M=1000;
int k,cur[N],amax=0,dp[N],cnt,T,n,c[N],a[N*100],vis[N],f[M+10],ans=0,isp[N],hav1=0;
int fcnt(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(!vis[i])res++;}
	return res;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int o=1;o<=T;o++){
		ans=0;
		scanf("%d",&n);cnt=n;memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);if(!hav1&&a[i]==1)hav1=1;
			amax=max(amax,a[i]);
		}
		if(hav1){printf("1\n");continue;}
		sort(a+1,a+1+n);
		if(n==2){
			if(a[2]%a[1]==0)printf("1\n");
			else printf("2\n");
			continue;
		}
		
		for(int i=1;i<=n;i++)if(!vis[i]){
			for(int j=i+1;j<=n;j++)if(!vis[j]){
				if(a[j]%a[i]==0)vis[j]=1;
			}
		}
		for(int i=1;i<=n;i++)if(!vis[i]){
			for(int j=1;j<=n;j++)if(!vis[j]){
				memset(f,0,sizeof(f));
				f[a[i]]=f[a[j]]=1;
				for(k=a[i]+1;k<=amax;k++){
					if((k-a[i]>0&&f[k-a[i]])||(k-a[j]>0&&f[k-a[j]])){
						f[k]=1;
					}
				}
				for(int k=i+1;k<=n;k++)if(k!=j&&f[a[k]])vis[k]=1;
			}
		}
		ans=fcnt();
		if(ans>3){
		for(c[1]=1;c[1]<=n;c[1]++)if(!vis[c[1]]) 
			for(c[2]=c[1]+1;c[2]<=n;c[2]++)if(!vis[c[2]])
				for(c[3]=c[2]+1;c[3]<=n;c[3]++)if(!vis[c[3]]){
			memset(f,0,sizeof(f));
			f[a[c[1]]]=f[a[c[2]]]=f[a[c[3]]]=1;
			rep(k,a[c[1]]+1,amax){
				if((k-a[c[1]]>0&&f[k-a[c[1]]])||(k-a[c[2]]>0&&f[k-a[c[2]]])||(k-a[c[3]]>0&&f[k-a[c[3]]]))f[k]=1;
			}
			for(int k=c[1]+1;k<=n;k++)if(k!=c[2]&&k!=c[3]&&f[a[k]])vis[k]=1;
		}
		}
		ans=fcnt();
		
		if(ans>4){
			for(c[1]=1;c[1]<=n;c[1]++)if(!vis[c[1]]) 
			for(c[2]=c[1]+1;c[2]<=n;c[2]++)if(!vis[c[2]])
			for(c[3]=c[2]+1;c[3]<=n;c[3]++)if(!vis[c[3]])
			for(c[4]=c[3]+1;c[4]<=n;c[4]++)if(!vis[c[4]]){
			memset(f,0,sizeof(f));
			f[a[c[1]]]=f[a[c[2]]]=f[a[c[3]]]=f[a[c[4]]]=1;
			rep(k,a[c[1]]+1,amax){
				if((k-a[c[1]]>0&&f[k-a[c[1]]])||(k-a[c[2]]>0&&f[k-a[c[2]]])||(k-a[c[3]]>0&&f[k-a[c[3]]])||(k-a[c[4]]>0&&f[k-a[c[4]]]))f[k]=1;
			}
			for(int k=c[1]+1;k<=n;k++)if(k!=c[2]&&k!=c[3]&&k!=c[4]&&f[a[k]])vis[k]=1;
		}
		}
		/*
		ans=fcnt();
		if(ans>5){
			for(c[1]=1;c[1]<=n;c[1]++)if(!vis[c[1]]) 
			for(c[2]=c[1]+1;c[2]<=n;c[2]++)if(!vis[c[2]])
			for(c[3]=c[2]+1;c[3]<=n;c[3]++)if(!vis[c[3]])
			for(c[4]=c[3]+1;c[4]<=n;c[4]++)if(!vis[c[4]])
			for(c[5]=c[4]+1;c[5]<=n;c[5]++)if(!vis[c[5]]){
			memset(f,0,sizeof(f));
			f[a[c[1]]]=f[a[c[2]]]=f[a[c[3]]]=f[a[c[4]]]=f[a[c[5]]]=1;
			rep(k,a[c[1]]+1,amax){
				if((k-a[c[1]]>0&&f[k-a[c[1]]])||(k-a[c[2]]>0&&f[k-a[c[2]]])||(k-a[c[3]]>0&&f[k-a[c[3]]])||(k-a[c[4]]>0&&f[k-a[c[4]]])||(k-a[c[5]]>0&&f[k-c[5]]))f[k]=1;
			}
			for(int k=c[1]+1;k<=n;k++)if(k!=c[2]&&k!=c[3]&&k!=c[4]&&k!=c[5]&&f[a[k]])vis[k]=1;
		}
		}
		ans=fcnt();
		if(ans>6){
			for(c[1]=1;c[1]<=n;c[1]++)if(!vis[c[1]]) 
			for(c[2]=c[1]+1;c[2]<=n;c[2]++)if(!vis[c[2]])
			for(c[3]=c[2]+1;c[3]<=n;c[3]++)if(!vis[c[3]])
			for(c[4]=c[3]+1;c[4]<=n;c[4]++)if(!vis[c[4]])
			for(c[5]=c[4]+1;c[5]<=n;c[5]++)if(!vis[c[5]])
			for(c[6]=c[5]+1;c[6]<=n;c[6]++)if(!vis[c[6]]){
			memset(f,0,sizeof(f));
			f[a[c[1]]]=f[a[c[2]]]=f[a[c[3]]]=f[a[c[4]]]=f[a[c[5]]]=f[a[c[6]]]=1;
			rep(k,a[c[1]]+1,amax){
				if((k-a[c[1]]>0&&f[k-a[c[1]]])||(k-a[c[2]]>0&&f[k-a[c[2]]])||(k-a[c[3]]>0&&f[k-a[c[3]]])||(k-a[c[4]]>0&&f[k-a[c[4]]])||(k-a[c[5]]>0&&f[k-c[5]])||(k-a[c[6]]>0&&f[k-a[c[6]]]))f[k]=1;
			}
			for(int k=c[1]+1;k<=n;k++)if(k!=c[2]&&k!=c[3]&&k!=c[4]&&k!=c[5]&&f[a[k]])vis[k]=1;
		}
		}
		*/
		ans=fcnt();
		printf("%d\n",ans);
	}
	return 0;
}


/*
28
21 26 49 54 47 39 38 15 30 24 29 35 42 22 43 55 17 37 51 13 48 45 36 11 52 53 8 50

*/

/*
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)if(!dp[a[i]]){
			dp[a[i]]=1;cur[i]=1;
			for(int k=1+a[i];k<=amax;k++)if(!dp[k]){
				if(dp[k-a[i]])dp[k]=1;
			}
			//ans=fcnt();
		}
		*/
