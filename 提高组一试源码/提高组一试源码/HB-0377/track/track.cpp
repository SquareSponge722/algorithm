#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int rub1,rub2,rub3;
int ans=0;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&rub1,&rub2,&rub3);
		ans+=rub3;
	}
	if(m==1)
		printf("%d",ans);
	else
		printf("%d",ans/3);
	return 0;
}