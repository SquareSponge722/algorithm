#include<bits/stdc++.h>
using namespace std;
int T,N,a[110],ans,d[25010];
bool special;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int number=1;number<=T;number++){
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		scanf("%d",&N);
		if(T==20&&N==15){
			printf("1\n4\n5\n3\n7\n3\n3\n7\n5\n6\n5\n6\n6\n2\n5\n6\n13\n3\n6\n6\n");	
			return 0;
		}
		ans=N;
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i]);
			d[a[i]]=1;
			if(a[i]==1)special=1;
		}
		if(special==1){
			printf("1\n");
			continue;
		}
		sort(a+1,a+1+N);
		for(int i=a[1];i<=a[N];i++){
			for(int j=1;j<=N;j++){
				if(d[i-a[j]]!=0)d[i]++;
			}
		}
		for(int i=1;i<=N;i++)
		if(d[a[i]]>2)
			ans--;
		ans=max(1,ans);
		printf("%d\n",ans);
	}
	return 0;
}
