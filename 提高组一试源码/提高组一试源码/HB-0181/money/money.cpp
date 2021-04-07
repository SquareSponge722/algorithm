#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,a[105],n,b[105],cnt,ans;
bool used[105],vis[105],flag;
void judge(int x){
	if(x==0){
		flag=true;
		return;
	}
	for(int i=1;i<=cnt;i++){
		if(vis[i]){
			if(x>=b[i])
			judge(x-b[i]);
		}
	}
}
void dfs(int now,int sum){
	if(now==cnt+1){
		for(int i=cnt;i>=1;i--){
			if(!vis[i]){
				flag=false;
				judge(b[i]);
				if(!flag)
					return;
			}
		}
		ans=min(ans,sum);
		return;
	}
	vis[now]=true;
	dfs(now+1,sum+1);
	vis[now]=false;
	dfs(now+1,sum);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(used,0,sizeof(used));
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(a[j]%a[i]==0)
					used[j]=true;
			}
		for(int i=1;i<=n;i++){
			if(!used[i])
				b[++cnt]=a[i];
		}
		ans=cnt;
		if(b[1]==1){
			puts("1");
			continue;
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
