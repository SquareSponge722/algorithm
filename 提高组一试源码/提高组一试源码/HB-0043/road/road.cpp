#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,d[N];
//bool ok[N];
long long ans=0;
int ok[N];
int num=0;
void sol(){
	while(num==0){
		for(int i=1;i<=n;i++){
			d[i]-=1;
	}
		ans++;
		for(int i=1;i<=n;i++)
			if(d[i]==0) num++,ok[num]=i;
}
	if(num!=0 && num!=n){
	
		for(int j=1;j<=num;j++){
			for(int i=1;i<=n;i++){
					if((ok[j]<i) &&  (ok[j+1]>i) && d[i]) d[i]-=1;//ans++;//{d[i]-=1;ans++;}
				//	if(i>ok[num]&& d[i]) d[i]-=1;ans++;//{d[i]-=1;ans++;}//d[i]-=1;ans++;
				//	if(i<ok[1]&& d[i]) d[i]-=1;ans++;//{d[i]-=1;ans++;}//d[i]-=1;ans++;
			}
			ans++;	
		} 
		for(int j=1;j<=num;j++){
			for(int i=1;i<=n;i++){
				//	if(ok[j]<i && ok[j+1]>i && d[i]) d[i]-=1;ans++;//{d[i]-=1;ans++;}
					if((i>ok[num])&& d[i]) d[i]-=1;//ans++;//{d[i]-=1;ans++;}//d[i]-=1;ans++;
				//	if(i<ok[1]&& d[i]) d[i]-=1;ans++;//{d[i]-=1;ans++;}//d[i]-=1;ans++;
			}
			ans++;	
		} 
		for(int j=1;j<=num;j++){
			for(int i=1;i<=n;i++){
				//	if(ok[j]<i && ok[j+1]>i && d[i]) d[i]-=1;ans++;//{d[i]-=1;ans++;}
				//	if(i>ok[num]&& d[i]) d[i]-=1;ans++;//{d[i]-=1;ans++;}//d[i]-=1;ans++;
					if((i<ok[1])&& d[i]) d[i]-=1;//ans++;//{d[i]-=1;ans++;}//d[i]-=1;ans++;
			}
			ans++;	
		} 
		for(int i=1;i<=n;i++)
			if(d[i]==0){
				num++,ok[num]=i;//sol();
		}
  }//sol();	
  if(num==n) return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if(d[i]==0) num++,ok[num]=i;
	//	if(d[i]!=0) d[i]-=1,ans++;;
	}
	sol();
//	for(int i=1;i<=n;i++)
//		printf("%d ",d[i]);
//	printf("%d",num);
	printf("%lld",ans);	
	return 0;
}
