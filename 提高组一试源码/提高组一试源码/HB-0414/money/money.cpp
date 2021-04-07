#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T,n,a[101];
bool book[25001];
bool dfs(int res,int id)
{
	if(id==0) return 0;
	int data=res%a[id];
	if(data==0)
		return 1;
	while(data<=res) {
		if(dfs(data,id-1))
			return 1;
		else
			data+=a[id];
	}
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		int maxa=0,sum=0;
		memset(book,0,sizeof(book));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			maxa=max(maxa,a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			if(dfs(a[i],i-1))
				sum++;
		printf("%d\n",n-sum);
	}
	return 0;
}
