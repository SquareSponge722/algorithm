#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,m;
int cost[1000010];
ll ans;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char ch[3];
	cin>>n>>m>>ch;
	if(ch[0]=='A'&&ch[1]=='1'){
	for(int i=1;i<=n;i++)
		cin>>cost[i];
	for(int i=1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			ans+=cost[i];
		}
	}
	for(int i=1;i<=m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		printf("%lld\n",ans);
	}
		return 0;
	}
	if(ch[0]=='A'){
	for(int i=1;i<=n;i++)
		cin>>cost[i];
	for(int i=1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
	}
	ll ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			ans2+=cost[i];
		}
		else ans1+=cost[i];
	}
	for(int i=1;i<=m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a%2==1&&b==1){
			if(c%2==1&&d==0){
				printf("-1\n");
				continue;
			} 
		    if(c%2==0&&d==1){
		    	printf("-1\n");
		    	continue;
			} 
			else {
				printf("%lld\n",ans1);
			} 
		}
		if(a%2==1&&b==0){
			if(c%2==0&&d==0){
				printf("-1\n");
				continue;
			} 
		    if(c%2==1&&d==1){
		    	printf("-1\n");
		    	continue;
			} 
			else {
				printf("%lld\n",ans2);
			} 
		}
	    if(a%2==0&&b==1){
			if(c%2==1&&d==1){
				printf("-1\n");
				continue;
			} 
		    if(c%2==0&&d==0){
		    	printf("-1\n");
		    	continue;
			}
			else{
				printf("%lld\n",ans2); 
			} 
		}
	    if(a%2==0&&b==0){
			if(c%2==0&&d==1){
				printf("-1\n");
				continue;
			} 
		    if(c%2==1&&d==0){
		    	printf("-1\n");
		    	continue;
			}
			else{
				printf("%lld\n",ans1); 
			} 
		}		
	}
		return 0;
	}
}
