#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
int gcd(int a,int b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main(){
	int t,n,m;
	int a[105],k;
	bool can[105];
	bool d[30000];
	stack<int> s;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(d,false,sizeof(d));
		m=0;k=25005;
		for(int i=1;i<=n;i++){scanf("%d",&a[i]);can[i]=true;}
		sort(a+1,a+n+1);
		if(a[1]==1){printf("1\n");continue;}
		for(int i=1;a[1]*i<=k;i++)d[a[1]*i]=true;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				//cout<<a[i]<<' '<<a[j]<<' '<<d[a[i]]<<'\n';
				if(can[j]==false)continue;
				if(a[i]>k){can[i]=false;break;}
				//if(a[i]%a[j]==0){can[i]=false;break;}
				if(d[a[i]]){can[i]=false;break;}
				int g=gcd(a[i],a[j]);
				if(g==1)k=min(k,a[i]*a[j]-a[i]-a[j]);
				for(int l=a[1];l<=k;l++){
					for(int p=1;a[i]*p+l<=k;p++){if(d[l]==true)s.push(a[i]*p+l);};
				}
			}
			while(!s.empty()){d[s.top()]=true;s.pop();}
		}
		for(int i=1;i<=n;i++)if(can[i])m++;
		printf("%d\n",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}