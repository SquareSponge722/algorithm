#include<cstdio>
#include<cmath>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;

void reads(ll &x){
	int fx=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fx=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	x=fx*x; //正负号 
}

//30分钟做完两题之后就...第三题这tm不是树连剖分吗？？？但我真TM不会啊... 

//......开启沉默模式......

//【题意】把树分成m条链，使最短的链最长。 

//数据：m=1，就是树中最大的链，直接dfs一遍就好了吧...找dis离1最远的 15分 

//bi=ai+1，就是链的情况，直接二分就好了 20分 

//ai=1，即所有节点都接在1下面，二分+lowerbound应该可以？20分 

//分支不超过3，就是最多二叉，感觉可以用树形DP做... 25分 这个分不要了... 

//感觉 55分 吧... 

//我想应该是要二分的...但...mid为最短长度，枚举每个点

const int N=50019;

struct Edge{ ll w,ver,nextt; }e[N*2]; ll head[N],tot=0;

struct Edge1{ ll a,b,c; }E[N]; 

bool cmp(Edge1 aa,Edge1 bb){ return aa.a<bb.a; } 

bool cmp1(Edge1 aa,Edge1 bb){ return aa.c<bb.c; } 

void add(ll x,ll y,ll z){ e[++tot].ver=y,e[tot].w=z,e[tot].nextt=head[x],head[x]=tot; }

ll n,m; ll ans=0,dist[N];

void dfs(ll u,ll fa_){
	for(ll i=head[u];i;i=e[i].nextt){
		if(e[i].ver==fa_) continue;
		dist[e[i].ver]=dist[u]+e[i].w; 
		ans=max(ans,dist[e[i].ver]);
		dfs(e[i].ver,u);
	}
}
 
bool check1(ll mid){ //链
	ll cnt=0,sum=0;
	for(ll i=1;i<n;i++){ //每条边 
		sum+=E[i].c;
		if(sum>=mid) sum=0,cnt++;
		if(cnt==m) return true;
	} return false;
}

ll cntt=0,flag=0,lens[N],lson[N],rightt[N],rih[N],heads[N],used[N];

void dfs2(ll u,ll fa_){ //分支不超过3 
	for(ll i=head[u];i;i=e[i].nextt){
		if(e[i].ver==fa_) continue;
		//cout<<head[u]<<" "<<e[i].nextt<<endl;
		dfs2(e[i].ver,u); 
		if(!lson[u]) lson[u]=e[i].ver;
		else rightt[e[i].ver]=lson[u],lson[u]=e[i].ver,
			 rih[e[i].ver]=heads[u],heads[u]=e[i].w;
	}
}

//感觉可能是这样做，然后+一个左儿子右兄弟的转移... 

void dfs3(ll u,ll fa_,ll mid){
	if(flag==1) return; //cout<<mid<<endl;
	for(ll i=head[u];i;i=e[i].nextt){
		if(e[i].ver==fa_) continue;
		
			dfs3(e[i].ver,u,mid); //先递归下去 
			//cout<<22222<<endl;
			if(lens[e[i].ver]+e[i].w>=mid){ //左边得到的单链 
				cntt++; lens[e[i].ver]=0;
				if(cntt==m) flag=1; return;
			} if(rightt[e[i].ver]&&rih[e[i].ver]+lens[rightt[e[i].ver]]>=mid)
				lens[rightt[e[i].ver]]=0,cntt++; //右兄弟的左边链+边
			if(rightt[e[i].ver]&&lens[e[i].ver]+rih[e[i].ver]+lens[rightt[e[i].ver]]>=mid)
				lens[e[i].ver]=0,lens[rightt[e[i].ver]]=0,cntt++; //左边链+右兄弟的左边链+边
			lens[u]=max(lens[u],lens[e[i].ver]+e[i].w); //能继承的最长链 
			//cout<<u<<"***"<<lens[u]<<endl;
			if(cntt==m) flag=1;  //分成m条链
		}
	}


bool check2(ll mid){ //cout<<mid<<" *** "<<endl;
	memset(lens,0,sizeof(lens));
	memset(used,0,sizeof(used));
	flag=0; cntt=0; dfs3(1,0,mid); 
	if(flag==1) return true;
	return false;
}

//flag=1即 bi=ai+1，flag=2即ai=1的情况。 

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int flag1=1,flag2=1; reads(n),reads(m);
	for(ll i=1,a,b,c;i<n;i++){ 
		reads(a),reads(b),reads(c),
		E[i].a=a,E[i].b=b,E[i].c=c;
		add(a,b,c),add(b,a,c);
		if(b!=a+1) flag1=0;
		if(a!=1) flag2=0;
	} if(flag1==1){ //处理一条链
		sort(E+1,E+n,cmp); //按a排序 
		ll l=0,r=(ll)1e10,mid;
		while(l<=r){ mid=(l+r)>>1;
			if(check1(mid)) ans=mid,l=mid+1;
			else r=mid-1;
		} cout<<ans<<endl; return 0;
	} if(flag2==1){ //处理n-1叉树(一定只能取两个啊...)
		//max-min配对，取min值；
		sort(E+1,E+n,cmp1); ans=(ll)1e10; //按c排序
		if(m<=(n-1)/2){ //全部两两配对 
			for(ll i=n-1-2*m+1;i<n-i;i++) 
				ans=min(ans,(ll)E[i].c+E[n-i].c);
		} else{ for(ll i=1;i<2*n-2*m-1-i;i++)
				ans=min(ans,(ll)E[i].c+E[2*n-2*m-1-i].c);
			for(ll i=2*n-2*m-1;i<n;i++) ans=min(ans,(ll)E[i].c);
		} cout<<ans<<endl; return 0;
		//每次合并最小的两个，个数-1，剩下m个最大的，即操作n-1-m次
	} if(m==1){
		for(ll i=1;i<=n;i++) //感觉30000过不了... 
			memset(dist,0,sizeof(dist)),dfs(i,0);
		printf("%lld\n",ans); return 0;	
	} dfs2(1,0); ll l=0,r=(ll)1e10,mid;
	while(l<=r){ mid=(l+r)>>1;
		if(check2(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	} cout<<ans<<endl; return 0;
}

/*链：
4 2
1 2 5
2 3 9
3 4 11 

n-1叉树：
4 2
1 2 5
1 3 9
1 4 11

7 4
1 2 5
1 3 9
1 4 11
1 5 18
1 6 54
1 7 8 

7 3
1 2 6
2 3 5
2 4 6
3 5 9
3 6 10
4 7 4


*/ 
