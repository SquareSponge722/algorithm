#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ans,a,n,x;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x>a){ans+=x-a;}
		a=x;
	}
	printf("%d",ans);
	return 0;
}