#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
int t;
int n;
int a[200];
bool vis[200];
bool book[200];
int ans;
int b[200];
int m;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		m=0;
		memset(book,0,sizeof(book));
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int x=1;x<=n;x++){
			scanf("%d",&a[x]);
		}
		sort(a+1,a+1+n);
		if(a[1]==1){
			printf("1\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				for(int x=i+1;x<=n;x++){
					if(a[x]%a[i]==0){
						vis[x]=1;
					}
				}
				m++;
				b[m]=a[i];
			}
		}
		for(int y=m;y>=3;y--){
			if(b[y]>b[1]*b[2]-b[1]-b[2]){
				book[y]=1;
			}
		}
		for(int x=1;x<=m;x++){
			if(!book[x]){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
