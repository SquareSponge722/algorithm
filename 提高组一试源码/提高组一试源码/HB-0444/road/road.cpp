#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int d[100005];
int main(){
	int n;
	freopen("road.in","r",stdin);
	scanf("%d",&n);
	int minn=2100000,maxn=0;
	for(int i=1;i<=n;i++){scanf("%d",&d[i]);minn=min(minn,d[i]);maxn=max(maxn,d[i]);}
	int ans=minn;
	fclose(stdin);
	for(int h=minn+1;h<=maxn;h++){
		bool myfind=false;
		for(int i=1;i<=n;i++){
			if(d[i]>=h&&myfind==false){
				ans++;myfind=true;
			}
			else if(d[i]<h&&myfind==true)myfind=false;
		}
	}
	freopen("road.out","w",stdout);
	printf("%d",ans);
	fclose(stdout);
	return 0;
}