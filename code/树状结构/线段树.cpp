#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

#define lson(k) (k << 1)
#define rson(k) (k << 1 | 1)
#define ll long long

using namespace std;

const int N = 5e4 + 10;

struct tree{
    ll sum,lmax,rmax,mmax;
    int l,r;
}tre[N << 2];

int n,m;
ll op,x,y;

void build(int,int,int);
void modify(int,ll,ll);
tree query(int,ll,ll);

inline void push(int k){
    tre[k].sum = tre[lson(k)].sum + tre[rson(k)].sum;
    tre[k].lmax = max(tre[lson(k)].sum + tre[rson(k)].lmax,tre[lson(k)].lmax);
    tre[k].rmax = max(tre[rson(k)].sum + tre[lson(k)].rmax,tre[rson(k)].rmax);
    tre[k].mmax = max(tre[lson(k)].rmax + tre[rson(k)].lmax,max(tre[lson(k)].mmax,tre[rson(k)].mmax));
}

int main(){
    scanf("%d",&n);
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        scanf("%lld %lld %lld",&op,&x,&y);
        if(op == 0){
            modify(1,x,y);
        }else{
            if(x > y) swap(x,y);
            printf("%lld\n",query(1,x,y).mmax);
        }
    }
    return 0;
}

void build(int cur,int l,int r){
    tre[cur].l = l;tre[cur].r = r;
    if(l == r){
        scanf("%lld",&tre[cur].sum);
        tre[cur].lmax = tre[cur].mmax = tre[cur].rmax = tre[cur].sum;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson(cur),l,mid);
    build(rson(cur),mid + 1,r);
    push(cur);
}
void modify(int cur,ll pos,ll val){
    if(tre[cur].l == tre[cur].r){
        tre[cur].lmax = tre[cur].mmax = tre[cur].rmax = tre[cur].sum = val;
        return ;
    }
    ll mid = (tre[cur].l + tre[cur].r) >> 1;
    if(pos <= mid) modify(lson(cur),pos,val);
    else modify(rson(cur),pos,val);
    push(cur);
}
tree query(int cur,ll l,ll r){
    if(l <= tre[cur].l && tre[cur].r <= r){
        return tre[cur];
    }
    ll mid = (tre[cur].l + tre[cur].r) >> 1;
    if(r <= mid) return query(lson(cur),l,r);
    else if(l > mid) return query(rson(cur),l,r);
    else{
        tree lt = query(lson(cur),l,r);
        tree rt = query(rson(cur),l,r);
        tree res;
        res.sum = lt.sum + rt.sum;
        res.lmax = max(lt.sum + rt.lmax,lt.lmax);
        res.rmax = max(rt.sum + lt.rmax,rt.rmax);
        res.mmax = max(lt.rmax + rt.lmax,max(lt.mmax,rt.mmax));
        return res;
    }
}

//线段树维护最大子段和
//Can you answer these queries III
//2021-5-24


/*
//线段树懒惰标记区间修改(乘加)
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;
const int N=100100;
struct nod
{
	long long num,lazy_plus,lazy_mult;
}tre[N<<2];
int n,m,p;

inline void upp(int id){
	tre[id].num=(tre[id<<1].num+tre[id<<1|1].num)%p;
}
inline void ddown(int id,int l,int r){
	if(tre[id].lazy_mult==1 && !tre[id].lazy_plus) return ;
	int mid=(l+r)>>1;
	
	tre[id<<1].lazy_plus=(tre[id].lazy_plus+tre[id<<1].lazy_plus*tre[id].lazy_mult)%p;
	tre[id<<1].lazy_mult=(tre[id<<1].lazy_mult*tre[id].lazy_mult)%p;
	tre[id<<1].num=(tre[id<<1].num*tre[id].lazy_mult)%p;
	tre[id<<1].num=(tre[id<<1].num+tre[id].lazy_plus*(mid-l+1))%p;
	
	tre[id<<1|1].lazy_plus=(tre[id].lazy_plus+tre[id<<1|1].lazy_plus*tre[id].lazy_mult)%p;
	tre[id<<1|1].lazy_mult=(tre[id<<1|1].lazy_mult*tre[id].lazy_mult)%p;
	tre[id<<1|1].num=(tre[id<<1|1].num*tre[id].lazy_mult)%p;
	tre[id<<1|1].num=(tre[id<<1|1].num+tre[id].lazy_plus*(r-mid))%p;
	
	tre[id].lazy_mult=1;
	tre[id].lazy_plus=0;
}
void build(int,int,int);
void tre_mult(int,int,int,int,long long,int);
void tre_plus(int,int,int,int,long long,int);
long long tre_search(int,int,int,int,int);
int main()
{
	int ord,x,y;
	long long k;
	scanf("%d %d",&n,&p);
	build(1,n,1);
    scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&ord);
		switch(ord)
		{
			case 1:
				{
					scanf("%d %d %lld",&x,&y,&k);
					tre_mult(1,n,x,y,k,1);
					break;
				}
			case 2:
				{
					scanf("%d %d %lld",&x,&y,&k);
					tre_plus(1,n,x,y,k,1);
					break;
				}
			case 3:
				{
					scanf("%d %d",&x,&y);
					printf("%lld\n",tre_search(1,n,x,y,1));
					break;
				}
		}
	}
	return 0;
}
void build(int l,int r,int id)
{
	tre[id].lazy_mult=1;
	tre[id].lazy_plus=0;
	if(l==r)
	{
		scanf("%lld",&tre[id].num);
		tre[id].num%=p;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	upp(id);
}
void tre_mult(int l,int r,int x,int y,long long k,int id)
{
	if(x<=l && r<=y)
	{
		tre[id].num=(tre[id].num*k)%p;
		tre[id].lazy_mult=(tre[id].lazy_mult*k)%p;
		tre[id].lazy_plus=(tre[id].lazy_plus*k)%p;
		return ;
	}
	ddown(id,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) tre_mult(l,mid,x,y,k,id<<1);
	if(y>mid) tre_mult(mid+1,r,x,y,k,id<<1|1);
	upp(id);
}
void tre_plus(int l,int r,int x,int y,long long k,int id)
{
	if(x<=l && r<=y)
	{
		tre[id].num=(tre[id].num+(r-l+1)*k)%p;
		tre[id].lazy_plus=(tre[id].lazy_plus+k)%p;
		return ;
	}
	ddown(id,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) tre_plus(l,mid,x,y,k,id<<1);
	if(y>mid) tre_plus(mid+1,r,x,y,k,id<<1|1);
	upp(id);
}
long long tre_search(int l,int r,int x,int y,int id)
{
	if(x<=l && r<=y) return tre[id].num;
	ddown(id,l,r);
	int mid=(l+r)>>1;
	long long ans=0;
	if(x<=mid) ans=(ans+tre_search(l,mid,x,y,id<<1))%p;
	if(y>mid) ans=(ans+tre_search(mid+1,r,x,y,id<<1|1))%p;
	return ans;
}

//AHOI 2009
//2021-5-24
*/


/*
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define lson(k) (k << 1)
#define rson(k) (k << 1 | 1)
#define ll long long
const int N = 1e6 + 10;

struct node{
    int l,r;
    ll out,in,dura; //最早出块时间 最晚入块时间 块中cost总和
    bool isOk;
}tre[N << 2];

int t,n,q;
int u[N],v[N],cost[N];

void build(int,int,int);
void update(int,int);
node query(int,int,int);
node merge(int,int);

inline void push(int k){
    tre[k].isOk = tre[lson(k)].isOk && tre[rson(k)].isOk;
    if(tre[lson(k)].out > tre[rson(k)].in) tre[k].isOk = false;
    
    tre[k].out = max(tre[lson(k)].out + tre[rson(k)].dura,tre[rson(k)].out);
    tre[k].in = min(tre[lson(k)].in,tre[rson(k)].in - tre[lson(k)].dura);
    tre[k].dura = tre[lson(k)].dura + tre[rson(k)].dura;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) scanf("%d",&u[i]);
        for(int i = 1;i <= n;i++) scanf("%d",&v[i]);
        for(int i = 1;i < n;i++) scanf("%d",&cost[i]);

        build(1,1,n);

        int ord,x,y,z;
        scanf("%d",&q);
        while(q--){
            scanf("%d %d %d",&ord,&x,&y);
            if(ord == 0){
                node ans = query(1,x,y);
                printf("%s\n",ans.isOk ? "Yes" : "No");
            }else if(ord == 1){
                cost[x] = y;
                update(1,x);
            }else{
                scanf("%d",&z);
                u[x] = y;v[x] = z;
                update(1,x);
            }
        }
    }
    return 0;
}

void build(int cur,int l,int r){
    tre[cur].l = l;tre[cur].r = r;
    if(l == r){
        tre[cur].out = u[l] + cost[l];
        tre[cur].in = v[l];
        tre[cur].dura = cost[l];
        tre[cur].isOk = true;
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson(cur),l,mid);
    build(rson(cur),mid + 1,r);
    push(cur);
}
void update(int cur,int pos){
    if(tre[cur].l == tre[cur].r && tre[cur].l == pos){
        tre[cur].out = u[tre[cur].l] + cost[tre[cur].l];
        tre[cur].in = v[tre[cur].l];
        tre[cur].dura = cost[tre[cur].l];
        tre[cur].isOk = true;
        return ;
    }
    int mid = (tre[cur].l + tre[cur].r) >> 1;
    if(pos <= mid) update(lson(cur),pos);
    else update(rson(cur),pos);
    push(cur);
}
node merge(const node& l,const node& r){
    node ans;
    ans.isOk = l.isOk && r.isOk;
    if(l.out > r.in) ans.isOk = false;
    
    ans.out = max(l.out + r.dura,r.out);
    ans.in = min(l.in,r.in - l.dura);
    ans.dura = l.dura + r.dura;

    return ans;
}
node query(int cur,int l,int r){
    if(l <= tre[cur].l && tre[cur].r <= r) return tre[cur];
    int mid = (tre[cur].l + tre[cur].r) >> 1;
    if(r <= mid) return query(lson(cur),l,r);
    else if(l > mid) return query(rson(cur),l,r);
    else return merge(query(lson(cur),l,r),query(rson(cur),l,r));
}

//线段树和分块的思想很相近
//化整为零，块与块之间的状态更新

//https://ac.nowcoder.com/acm/contest/11166/J
//2021-7-18
*/