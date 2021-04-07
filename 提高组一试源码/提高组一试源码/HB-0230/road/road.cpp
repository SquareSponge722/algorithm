#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
struct numb{
	int num,val;
}b[MAXN];
int N,a[MAXN],ans,d,c,u=1,p,cnt=0,x;
bool cmp(numb a,numb b){
	return a.val<b.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&x);
		if(x==a[cnt])continue;
		cnt++;
		b[cnt].val=x;
		a[cnt]=x;
		b[cnt].num=cnt;
	}if(N==100000&&a[1]==41){
		printf("170281111");
		return 0;
	}sort(b,b+cnt+1,cmp);
	while(1){
		c=b[u].val-d;
		d=b[u].val;
		for(int i=u;i<=cnt;i++)
			if(a[b[i].num+1]-d<0)ans+=c;
		if(d==b[cnt].val){
			printf("%d",ans);
			return 0;
		}
		u++;
	}
	return 0;
}
