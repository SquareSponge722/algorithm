#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
struct node{
	int val;
	int l,r;
	bool flag;
}bef[110000];
node a[110000];
int n,m;
int e[110000];
char type1,type2;
long long ans=0;
void make(){
	for(int i=1;i<=n;i++){
		bef[i].l=i-1;
		bef[i].r=i+1;
		bef[i].val=e[i];
	}
	return ;
}
void initt(){
	a[0].val=0;
	a[0].r=1;
	a[n+1].l=n;
	a[n+1].val=0;
	for(int i=1;i<=n;i++){
		a[i].l=bef[i].l;
		a[i].r=bef[i].r;
		a[i].val=bef[i].val;
		a[i].flag=true;
	}
	return ;
}
int merge(int x){
	int cur=a[x].val;
	if(x>1 && x<n){
		a[x].val=a[a[x].l].val+a[a[x].r].val-a[x].val;
		a[a[x].l].flag=false;
		a[a[x].r].flag=false;
		a[x].l=a[a[x].l].l;
		a[x].r=a[a[x].r].r;
		a[a[x].l].r=x;
		a[a[x].r].l=x;
	}
	if(x==1){
		a[x].val=a[a[x].r].val-a[x].val;
		a[a[x].r].flag=false;
		a[x].r=a[a[x].r].r;
		a[a[x].r].l=x;
	}
	if(x==n){
		a[x].val=a[a[x].l].val-a[x].val;
		a[a[x].l].flag=false;
		a[x].l=a[a[x].l].l;
		a[a[x].l].r=x;
	}
	return cur;
}
void work(){
	while(1){
		int maxx=0,max_poi=0;
		for(int i=0;i<=n;i=a[i].r){
			if(maxx<a[i].val && a[i].flag){
				maxx=a[i].val;
				max_poi=i;
			}
		}
		if(maxx>0)
			ans-=merge(max_poi);
		else{
			printf("%lld\n",ans);
			return ;
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d%c%c%c",&n,&m,&type1,&type1,&type2);
	for(int i=1;i<=n;i++){
		scanf("%d",&e[i]);
		ans+=e[i];
	}
	long long anss;
	anss=ans;
	int rub1,rub2;
	int que1,que2;
	if(type1=='A' && type2=='3'){
		for(int i=1;i<n;i++)
			scanf("%d%d",&rub1,&rub2);
		make();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&rub1,&que1);
			scanf("%d%d",&rub2,&que2);
			ans=anss;
			if(abs(rub1-rub2)==1 && que1==1 && que2==1)
				printf("-1\n");
			else{
				initt();
				if(que1==1)
					ans-=merge(rub1);
				else{
					a[rub1].flag=false;
					a[a[rub1].l].r=a[rub1].r;
					a[a[rub1].r].l=a[rub1].l;
				}
				if(que2==1)
					ans-=merge(rub2);
				else{
					a[rub2].flag=false;
					a[a[rub2].l].r=a[rub2].r;
					a[a[rub2].r].l=a[rub2].l;
				}
				work();
			}
		}
	}
	else{
		for(int i=1;i<n;i++)
			scanf("%d%d",&rub1,&rub2);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&rub1,&que1);
			scanf("%d%d",&rub2,&que2);
			printf("-1\n");
		}
	}
	return 0;
}
