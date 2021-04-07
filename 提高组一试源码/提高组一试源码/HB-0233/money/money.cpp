#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define fo(i,n) for(int i=1;i<=n;i++)
using namespace std;
int T,n,a[105],ans;bool q[25005],p[25005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	fo(ti,T){
		memset(q,0,sizeof(q));
		memset(p,0,sizeof(p));
		memset(a,0,sizeof(a));
		scanf("%d",&n);ans=n;
		fo(i,n){scanf("%d",&a[i]);p[a[i]]=q[a[i]]=1;}
		sort(a+1,a+n+1);
		int l=a[1],r=a[n];
		fo(t,n){
			if(!p[a[t]])continue;
			for(int i=l;i<=r-a[t];i++)
				if(q[i]){
					if(p[i+a[t]]){p[i+a[t]]=0;ans--;if(i+a[t]==a[n]){n--;r=a[n];}}
					q[i+a[t]]=1;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
