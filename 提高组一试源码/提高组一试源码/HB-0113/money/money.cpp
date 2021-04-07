#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<climits>
using namespace std;
int f[500],sum,tot;
bool judgement[30000];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n;scanf("%d",&t);
	while(t--){
		memset(f,0,sizeof(f));
		memset(judgement,true,sizeof(judgement));
		tot=0,sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&f[i]);
		}
		sort(f,f+n);
		for(int i=0;i<n;i++){
			if(judgement[f[i]]){
				for(int z=1;f[i]*z<=f[n-1];z++){
				  sum=f[i]*z;
						for(int j=0;j<=i;j++){
							if(judgement[f[j]]){
								sum=f[i]*z;
								for(;sum<=f[n-1];){
									sum+=f[j];
									judgement[sum]=false;
								}
							}
						}
				  if(z!=1)judgement[f[i]*z]=false;
			    }
			}
		}
		for(int i=0;i<n;i++)
			if(judgement[f[i]])
				tot++;
		printf("%d\n",tot);
	}
	return 0;
}
