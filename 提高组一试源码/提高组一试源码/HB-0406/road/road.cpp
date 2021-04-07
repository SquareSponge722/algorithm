#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
const int N=101000;
int A[N];
vector<int>B[N/10];
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,maxn=-1e8,minn=1e8;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		maxn=max(maxn,A[i]);
		minn=min(minn,A[i]);
		B[A[i]].push_back(i);
	}
	long long la=0,ans=0,zero=0;
	for(int i=minn;i<=maxn;i++){
		if(i-la<0)continue;
		if(B[i].size()){
			ans+=(i-la)*(zero+1);
			la+=i-la;
			for(int j=0;j<B[i].size();j++){
				if(A[B[i][j]+1]<i&&A[B[i][j]-1]<=i)zero--;
				if(A[B[i][j]+1]<i||A[B[i][j]-1]<=i)continue;
				zero++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
