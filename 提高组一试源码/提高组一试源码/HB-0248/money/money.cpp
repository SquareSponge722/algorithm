#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=25001;
int n,ans=0,d[N];
bool cancut(int x,int l){
	if(l==1)
		return false;
	bool jg=false;
	if(!x)
		jg=true;
	else
		for(int i=l-1;i>=1;i--){
			if(x>=d[i]){
				jg=jg|cancut(x-d[i],l);
				if(jg)
					break;
			}
			else{
				jg=jg|cancut(x,l-1);
				if(jg)
					break;
			}
			if(jg)
				break;
		}
	return jg;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]);
		sort(d+1,d+n+1);
		for(int i=1;i<=n;i++)
			if(!cancut(d[i],i))
				ans++;
		printf("%d\n",ans);
	}
}
