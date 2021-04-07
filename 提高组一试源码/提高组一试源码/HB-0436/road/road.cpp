#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define big 20000
using namespace std;
int n,d[100010];
int minn=big,sum;
int kk=1;
int finder(int l)
{
	if(d[l]==0){
		int ll=l;
		for(int i=l;i<=n;++i){
			if(d[i]!=0){
				l=i;
				break;
			} 
		}
		if(l==ll) return n+2;
	}
	kk=l;
	for(int i=l;i<=n;i++){
		if(d[i]==0) return i;
	}
	return n+1;
}
void dfs()
{
	kk=1;
	while(kk<=n+1){
		int g,b=finder(kk)-1;
		minn=big;
		for(int i=kk;i<=b;i++){
			minn=min(minn,d[i]);	
		}
		for(int i=kk;i<=b;i++){
			d[i]-=minn;
			g=i;
		}
		sum+=minn;
		kk=g+1;
	}	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&d[i]);
	}
	for(int i=1;i<=n;++i){
		if(finder(1)!=n+2){
			dfs();
		}
		else break;
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
