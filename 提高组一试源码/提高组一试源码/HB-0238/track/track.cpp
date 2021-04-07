#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=50005;
int f[maxn],n,m;
struct node{
	int u,v,w;
}a[maxn];
bool cmp(node x,node y){
	return x.w>y.w;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+n,cmp);
	printf("%d",a[1].w);
}
