#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100001];
bool k[100001];
int n,l,r,ans=0;
void solve(){
	for(int i=1;i<=n;i++){
		if(k[i]&&i==1) l=i;
		else if(k[i]&&!k[i-1]) l=i;
		if(k[i]) r=i;
		if((!k[i]&&k[i-1])||i==n) {
			for(int j=l;j<=r;j++) {
				a[j]--;
				if(a[j]==0) k[j]=false;
			}
			ans++;
		}
	}
	return ;
}
bool judge(int ll,int rr){
	for(int x=ll;x<=rr;x++){
		if(k[x]==true) return false;
		if(x==rr) return true;	
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(k,false,sizeof(k));
	for(int i=1;i<=n;i++)
		if(a[i]!=0) k[i]=true;
	while(!judge(1,n)){
		solve();
	}
	cout<<ans<<endl;
	return 0;
}
