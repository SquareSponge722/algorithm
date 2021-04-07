#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int N=1000001;
int d[N];
int n;
long long ans;
int sz;
void dfs(int l)
{
	queue <int > q;
	bool flag=true;
	for(int i=0;i<sz;++i)
		if(d[i])
			flag=false;
	if(flag){
		printf("%lld\n",ans);
		exit(0);
	}			
	for(int i=0; i<sz; ++i)
		q.push(d[i]);
	if(q.front()==0) {
		int cnt=0;
		while(q.front()==0) {
			q.pop();
			++cnt;
		}
		sz-=cnt;
		cnt=0;
		while(!q.empty()) {
			d[cnt++]=q.front();
			q.pop();
		}
	}
	int zero_lc=sz;
	for(int i=l; i<sz; ++i)
		if(d[i]==0) {
			zero_lc=i;
			break;
		}
	int min=99999;
	for(int i=l; i<zero_lc; ++i)
		if(d[i]<min)
			min=d[i];
	ans+=min;
	for(int i=l; i<zero_lc; ++i)
		d[i]-=min;
	dfs(l);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	sz=n;
	for(int i=0; i<n; ++i)
		scanf("%d",&d[i]);
	dfs(0);
	return 0;
}
