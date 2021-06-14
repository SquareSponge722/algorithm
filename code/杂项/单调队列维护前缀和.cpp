#include <cstdio>
#include <cstdlib>
#include <deque>
using namespace std;
const int N = 200100;
int t,n,k;
int a[N],sum[N];
deque <int> q;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[n+i] = a[i];
		}
		
		sum[0] = 0;
		q.clear();
		for(int i=1;i<=n+k-1;i++)
			sum[i] = sum[i-1] + a[i];
		
		int ans = -0x3f3f3f3f;
		int l,r;
		for(int i=1;i<=n+k-1;i++){
			while(!q.empty() && sum[i-1] <= sum[q.back()])
				q.pop_back();
			while(!q.empty() && q.front() <= i-k-1)
				q.pop_front();
			q.push_back(i-1);
			if(sum[i]-sum[q.front()] > ans){
				ans = sum[i]-sum[q.front()];
				l = q.front()+1;
				r = i==n ? n : i%n;
			}
		}
		printf("%d %d %d\n",ans,l,r);
	}
	return 0;
} 
