#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using std::sort;
using std::min;
using std::max;
struct Node{int name,w;}node[100005];
bool cmp(Node x,Node y){return x.w>y.w;}
int a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,sum=0,minn=0x7f7f7f7f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		minn=min(minn,a[i]);
		node[i]=(Node){i,a[i]};
	}
	sort(node+1,node+1+n,cmp);
	for(int i=1;i<=n;i++){
		int x=node[i].name;
		int maxx=max(a[x-1],a[x+1]);
		if(a[x]>maxx){
			sum+=a[x]-maxx;
			a[x]=maxx;
		}
		else if(a[x]==a[x-1] || a[x]==a[x+1]) sum++;
	}
	printf("%d\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
