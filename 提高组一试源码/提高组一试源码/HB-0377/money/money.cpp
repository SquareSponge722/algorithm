#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXX 25001
using namespace std;
int can[26000]={false};
int num[110],t,n,ans=0;;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		ans=n;
		for(int j=1;j<=n;j++)
			scanf("%d",&num[j]);
		memset(can,0,sizeof(can));
		sort(num+1,num+n+1);
		for(int j=1;j<=n;j++){
			if(can[num[j]]){
				ans--;
				continue;
			}
			else{
				can[num[j]]=true;
				for(int k=1;k<=MAXX;k++){
					if(can[k])
						can[k+num[j]]=true;
					if(k+num[j]>MAXX)
						break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
