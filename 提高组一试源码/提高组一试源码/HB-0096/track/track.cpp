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
	x=fx*x; //������ 
}

//30������������֮���...��������tm���������ʷ��𣿣���������TM���ᰡ... 

//......������Ĭģʽ......

//�����⡿�����ֳ�m������ʹ��̵������ 

//���ݣ�m=1������������������ֱ��dfsһ��ͺ��˰�...��dis��1��Զ�� 15�� 

//bi=ai+1���������������ֱ�Ӷ��־ͺ��� 20�� 

//ai=1�������нڵ㶼����1���棬����+lowerboundӦ�ÿ��ԣ�20�� 

//��֧������3�����������棬�о�����������DP��... 25�� ����ֲ�Ҫ��... 

//�о� 55�� ��... 

//����Ӧ����Ҫ���ֵ�...��...midΪ��̳��ȣ�ö��ÿ����

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
 
bool check1(ll mid){ //��
	ll cnt=0,sum=0;
	for(ll i=1;i<n;i++){ //ÿ���� 
		sum+=E[i].c;
		if(sum>=mid) sum=0,cnt++;
		if(cnt==m) return true;
	} return false;
}

ll cntt=0,flag=0,lens[N],lson[N],rightt[N],rih[N],heads[N],used[N];

void dfs2(ll u,ll fa_){ //��֧������3 
	for(ll i=head[u];i;i=e[i].nextt){
		if(e[i].ver==fa_) continue;
		//cout<<head[u]<<" "<<e[i].nextt<<endl;
		dfs2(e[i].ver,u); 
		if(!lson[u]) lson[u]=e[i].ver;
		else rightt[e[i].ver]=lson[u],lson[u]=e[i].ver,
			 rih[e[i].ver]=heads[u],heads[u]=e[i].w;
	}
}

//�о���������������Ȼ��+һ����������ֵܵ�ת��... 

void dfs3(ll u,ll fa_,ll mid){
	if(flag==1) return; //cout<<mid<<endl;
	for(ll i=head[u];i;i=e[i].nextt){
		if(e[i].ver==fa_) continue;
		
			dfs3(e[i].ver,u,mid); //�ȵݹ���ȥ 
			//cout<<22222<<endl;
			if(lens[e[i].ver]+e[i].w>=mid){ //��ߵõ��ĵ��� 
				cntt++; lens[e[i].ver]=0;
				if(cntt==m) flag=1; return;
			} if(rightt[e[i].ver]&&rih[e[i].ver]+lens[rightt[e[i].ver]]>=mid)
				lens[rightt[e[i].ver]]=0,cntt++; //���ֵܵ������+��
			if(rightt[e[i].ver]&&lens[e[i].ver]+rih[e[i].ver]+lens[rightt[e[i].ver]]>=mid)
				lens[e[i].ver]=0,lens[rightt[e[i].ver]]=0,cntt++; //�����+���ֵܵ������+��
			lens[u]=max(lens[u],lens[e[i].ver]+e[i].w); //�ܼ̳е���� 
			//cout<<u<<"***"<<lens[u]<<endl;
			if(cntt==m) flag=1;  //�ֳ�m����
		}
	}


bool check2(ll mid){ //cout<<mid<<" *** "<<endl;
	memset(lens,0,sizeof(lens));
	memset(used,0,sizeof(used));
	flag=0; cntt=0; dfs3(1,0,mid); 
	if(flag==1) return true;
	return false;
}

//flag=1�� bi=ai+1��flag=2��ai=1������� 

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
	} if(flag1==1){ //����һ����
		sort(E+1,E+n,cmp); //��a���� 
		ll l=0,r=(ll)1e10,mid;
		while(l<=r){ mid=(l+r)>>1;
			if(check1(mid)) ans=mid,l=mid+1;
			else r=mid-1;
		} cout<<ans<<endl; return 0;
	} if(flag2==1){ //����n-1����(һ��ֻ��ȡ������...)
		//max-min��ԣ�ȡminֵ��
		sort(E+1,E+n,cmp1); ans=(ll)1e10; //��c����
		if(m<=(n-1)/2){ //ȫ��������� 
			for(ll i=n-1-2*m+1;i<n-i;i++) 
				ans=min(ans,(ll)E[i].c+E[n-i].c);
		} else{ for(ll i=1;i<2*n-2*m-1-i;i++)
				ans=min(ans,(ll)E[i].c+E[2*n-2*m-1-i].c);
			for(ll i=2*n-2*m-1;i<n;i++) ans=min(ans,(ll)E[i].c);
		} cout<<ans<<endl; return 0;
		//ÿ�κϲ���С������������-1��ʣ��m�����ģ�������n-1-m��
	} if(m==1){
		for(ll i=1;i<=n;i++) //�о�30000������... 
			memset(dist,0,sizeof(dist)),dfs(i,0);
		printf("%lld\n",ans); return 0;	
	} dfs2(1,0); ll l=0,r=(ll)1e10,mid;
	while(l<=r){ mid=(l+r)>>1;
		if(check2(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	} cout<<ans<<endl; return 0;
}

/*����
4 2
1 2 5
2 3 9
3 4 11 

n-1������
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
