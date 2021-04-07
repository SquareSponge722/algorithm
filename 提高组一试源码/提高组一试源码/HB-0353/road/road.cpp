#include <cstdio>
#include <cstdlib>
using namespace std;
const int N=100010;
int a[N];
int day;
int n;
void dfs(int left, int right){
	bool flag=false ,book=false;
	int t;
	if(left>right)	return ;
	for(int i=left;i<=right;i++){
		if(a[i]==0){
			t=i;
			flag=true;
			break;
		}
		a[i]--;
		book=true;
	}
	if(book)	day++;
	if(flag){
		dfs(t+1,right);
		dfs(left,t-1);
	
	}
	else
		dfs(left,right);
	return ;
}
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,n);
	printf("%d",day);
	return 0;
}
