#include<iostream>
#include<cstdio>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100100,M=200200;
int T,n,mx,ans,a[N],b[M]={1};
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout); 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		mx=0;ans=0;
		FOR(i,1,n) scanf("%d",&a[i]),mx=max(mx,a[i]);
		sort(a+1,a+n+1);
		FOR(i,1,n){
			if(!b[a[i]]){
				FOR(j,0,mx)if(b[j] && j+a[i]<=mx) b[j+a[i]]=1;
				ans++;
			}
			//FOR(i,0,mx) cout<<b[i]<<' ';cout<<endl; 
		}
		printf("%d\n",ans);
		FOR(i,1,2*mx) b[i]=0;
	}
}/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
