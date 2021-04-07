#include<bits/stdc++.h>
using namespace std;
int n,m,w,val[100010],gg,ll,a,x,b,y,ans=0,add,now;
char C;
bool q[100010],judge[100010];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%c%d",&n,&m,&C,&w);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<=n-1;i++)
	scanf("%d%d",&gg,&ll);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		q[a]=1,q[b]=1;
		if(x)judge[a-1]=1,judge[a]=1,judge[a+1]=1;
		if(y)judge[b-1]=1,judge[b]=1,judge[b+1]=1;
		ans=-1;
		for(int i=1;i<=n;i++){
			add=1000000;
			if(!judge[i]){
				if(q[i]){
					printf("-1\n");
					break;
				}
				else{
					if(!q[i-1]){
						if(add>val[i-1]||add>val[i]){
							if(val[i-1]<val[i]){
								add=val[i-1];
								now=i-1;
							}	
							else {
								add=val[i];
								now=i;
							}
						}
					}
					if(!q[i+1]){
						if(add>val[i+1]||add>val[i]){
							if(val[i+1]<val[i]){
								add=val[i+1];
								now=i+1;
							}	
							else {
								add=val[i];
								now=i;
							}
						}
					}
					if(add==1000000){
						printf("-1\n");
						break;
					}
				} 
			}
			printf("%d",ans);
		}
	}
	return 0;
}
