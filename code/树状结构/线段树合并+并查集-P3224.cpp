#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
const int M = 1e7 + 10;

struct tree{
	int cnt;
	int ls,rs;
}tre[M];

int n,m,q;
char ord[5];
int rak[N],mapp[N];
//map <int,int> mapp;

int fa[N];

int tot;
int root[N];

int fin(int);
void insert(int&,int,int,int);
int query(int,int,int,int);
void merge(int&,int,int,int);

inline void upp(int k){
	tre[k].cnt = tre[tre[k].ls].cnt + tre[tre[k].rs].cnt;
}

int main(){

	mapp[0] = -1;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&rak[i]);
		insert(root[i],1,n,rak[i]);
		mapp[rak[i]] = i;
		fa[i] = i;
	}
	
	int u,v;
	while(m--){
		scanf("%d %d",&u,&v);
		int fu = fin(u),fv = fin(v);
		if(fu != fv){
			fa[fu] = fv;
			merge(root[fv],root[fu],1,n);
		}
	}

	scanf("%d",&q);
	while(q--){
		scanf("%s %d %d",&ord,&u,&v);
		if(ord[0] == 'Q'){
			int ans = query(root[fin(u)],1,n,v);
			printf("%d\n",mapp[ans]);
		}else{
			int fu = fin(u),fv = fin(v);
			if(fu != fv){
				fa[fu] = fv;
				merge(root[fv],root[fu],1,n);
			}
		}
	}

	return 0;
}
int fin(int k){
	if(fa[k] != k) fa[k] = fin(fa[k]);
	return fa[k];
}
void insert(int& id,int l,int r,int pos){
	if(!id) id = ++tot;
	if(l == r){
		tre[id].cnt++;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) insert(tre[id].ls,l,mid,pos);
	else insert(tre[id].rs,mid + 1,r,pos);
	upp(id);
}
int query(int id,int l,int r,int pos){
	if(tre[id].cnt < pos) return 0;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(pos <= tre[tre[id].ls].cnt) return query(tre[id].ls,l,mid,pos);
	else return query(tre[id].rs,mid + 1,r,pos - tre[tre[id].ls].cnt);
}
void merge(int &id,int idMer,int l,int r){
	if(!id){
		id = idMer;
		return ;
	}
	if(!idMer) return ;
	if(l == r){
		tre[id].cnt += tre[idMer].cnt;
		return ;
	}
	int mid = (l + r) >> 1;
	merge(tre[id].ls,tre[idMer].ls,l,mid);
	merge(tre[id].rs,tre[idMer].rs,mid + 1,r);
	upp(id);
}

//其实本来不准备上传的
//虽然是紫题但非常的模板
//传上来主要是提示一下STL的常数还是挺大的
//这道题用map的话时间会加倍
//如果不能大幅的减小代码难度还是自己手打比较好

//以后也会在末尾加上时间
//2021-4-8