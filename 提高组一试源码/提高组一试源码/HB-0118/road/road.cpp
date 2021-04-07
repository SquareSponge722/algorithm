#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1001000;
int n,a[N],s[N],tp,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n){
		while(tp && a[s[tp]]>a[i]) ans+=a[s[tp]]-max(a[s[tp-1]],a[i]),tp--;
		if(a[s[tp]]!=a[i]) s[++tp]=i;
		//FOR(i,1,tp) cout<<s[i]<<' ';cout<<endl;
	}
	ans+=a[s[tp]];
	printf("%d",ans);
}/*
6
4 3 2 5 3 5
*/
