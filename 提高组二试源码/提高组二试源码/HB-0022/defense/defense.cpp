#include <bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,m,r[N],a,b,x,y,ans=0;
int ch=getchar();

struct node{
	long long next,to,can;
}f[100005];

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>ch;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		for(int j=1;j<=n-1;j++){
			cin>>f[j].next>>f[j].to;
			for(int ig=1;ig<=m;ig++){
				scanf("%d%d%d%d",&f[a],&f[a].can,&f[b],&f[b].can);
				if((f[i].can>0)&&(f[i+1].can<0))
					ans+=r[i];
				else if	((f[i].can<0)&&(f[i+1].can<0))
					ans=-1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
