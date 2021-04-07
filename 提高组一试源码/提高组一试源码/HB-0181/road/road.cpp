#include<cstdio>
#include<algorithm>
#define l(x) tree[x].l
#define r(x) tree[x].r
#define lz(x) tree[x].lz
#define mi(x) tree[x].mi
#define mx(x) tree[x].mx
using namespace std;
const int maxn=100005;
int n,a[maxn];
struct node{
	int l,r;
};
struct SegmentTree{
	int l,r,mi,lz,mx;
}tree[maxn<<2];
void update(int p){
	mi(p)=min(mi(p<<1),mi(p<<1|1));
	mx(p)=max(mx(p<<1),mx(p<<1|1));
}
void spread(int p){
	if(lz(p)){
		mi(p<<1)-=lz(p);
		mi(p<<1|1)-=lz(p);
		mx(p<<1)-=lz(p);
		mx(p<<1|1)-=lz(p);
		lz(p<<1)+=lz(p);
		lz(p<<1|1)+=lz(p);
		lz(p)=0;
	}
}
void build(int p,int l,int r){
	l(p)=l;
	r(p)=r;
	if(l==r){
		mi(p)=a[l];
		mx(p)=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	update(p);
}
void change(int p,int l,int r,int x){
	if(l<=l(p)&&r(p)<=r){
		mi(p)-=x;
		mx(p)-=x;
		lz(p)+=x;
		return;
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid)
		change(p<<1,l,r,x);
	if(r>mid)
		change(p<<1|1,l,r,x);
	update(p);
}
int ask(int p,int l,int r){
	int val=0;
	if(l<=l(p)&&r(p)<=r){
		return mx(p);
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid)
		val=max(val,ask(p<<1,l,r));
	if(r>mid)
		val=max(val,ask(p<<1|1,l,r));
	return val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	build(1,1,n);
	long long ans=0,cnt=0;
	while(ask(1,1,n)>0){
		cnt++;
		int l=1,r=0,num=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			int x=ask(1,i,i);
			if(x==0){
				r=i-1;
				num=min(num,ask(1,i-1,i-1));
				if(l<=r){
					change(1,l,r,num);
					ans+=num;
				}
				num=0x3f3f3f3f;
				l=i+1;
				continue;
			}
			if(i==n){
				r=i;
				num=min(num,x);
				change(1,l,r,num);
				ans+=num;
				num=0x3f3f3f3f;
				break;
			}
			num=min(num,x);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
