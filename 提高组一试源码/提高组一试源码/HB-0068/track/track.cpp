#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		sum+=c;
	}
    printf("%d",sum);
}
