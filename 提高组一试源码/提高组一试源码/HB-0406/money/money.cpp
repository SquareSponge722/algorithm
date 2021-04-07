#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=110;
int A[N];
int main(){
	int t;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&A[i]);
		if(n<=25)printf("%d\n",rand()%n+1);
	}
}
