#include <cstdio>
#include <cstring>

using namespace std;
int A[50005];
int B[50005];
int C[50005];

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m;
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&A[i],&B[i],&C[i]);
	}
	for(int j=1;j<=n-1;j++)
	{
		ans=ans+C[j];
	}
	printf("%d",ans);
	return 0;
}


