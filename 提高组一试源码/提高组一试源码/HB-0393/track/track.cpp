#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
typedef long long ll;
const int N=50005;
inline ll read()
{
	char ch=getchar(),last=' ';ll ans=0;
	while(ch<'0'||ch>'9'){
		last=ch;ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';ch=getchar();
	}
	if(last=='-') ans=-ans;
	return ans;
}
struct node{
	int to,nxt,dis;
}e[N*2];
int head[N],tot;
int n,m;
void add(int x,int y,int z)
{
	e[++tot].to=y;
	e[tot].dis=z;
	e[tot].nxt=head[x];
	head[x]=tot;
}
ll val[N],sum[N],w[N];
ll L=999999,R,ANS,mid;
void dfs1(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(y==fa) continue;
		sum[x]++;
		val[y]=e[i].dis;
		dfs1(y,x);
	}
}
int cnt;
bool err;
ll a[N],t[N];
bool vis[N];
vector<int> G[N];
void dfs(int x,int fa)
{
	int num=0;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(y==fa) continue;
		dfs(y,x);
		if(sum[x]==1) w[x]+=w[y];
		//G[x].push_back(y);
	}
	memset(a,0,sizeof a);
	memset(vis,0,sizeof vis);
	for(int i=0;i<G[x].size();i++) {
		int y=G[x][i];
		if(y!=fa)a[++num]=w[y];
	}
	if(sum[x]<=1){
		if(w[x]>=mid) w[x]=0,cnt++;
		return;
	}
	//cout<<x<<endl;
	sort(a+1,a+1+num);
//	for(int i=1;i<=num;i++) cout<<a[i]<<' ';cout<<endl;
	for(int i=1;i<num;i++)
	if(!vis[i])
    {
    	bool flag=1;
    	for(int j=i+1;j<=num&&flag;j++) if(a[i]+a[j]>=mid&&!vis[j]){
    		flag=0;vis[i]=vis[j]=1;cnt++;
		}
	}
//	for(int i=1;i<=num;i++) cout<<vis[i]<<' ';cout<<endl;
	int pos=0;
	for(int i=sum[x];i>=1;i--) if(!vis[i]) {
		pos=i;break;
	}
	if(pos)w[x]+=a[pos];
	//cout<<x<<' '<<' '<<w[x]<<endl;
	if(w[x]>=mid) w[x]=0,cnt++;
}
bool check(int mid)
{
	//for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) w[i]=val[i];
	//for(int i=1;i<=n;i++) cout<<w[i]<<' ';cout<<endl;
	cnt=0;
	dfs(1,0);
	//cout<<cnt<<endl;
	//if(err==1) return 0;
	if(cnt>=m) return 1;
	else return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	n=read(),m=read();
//	double st=clock();
	for(int i=1;i<n;i++)
	{
		 int x=read(),y=read(),z=read();
         add(x,y,z);add(y,x,z);
         G[x].push_back(y);
         G[y].push_back(x);
		 L=min(L,(ll)z);R+=(ll)z;
	}
	dfs1(1,0);
//	mid=15;
//	cout<<check(15)<<endl;
	//for(int i=1;i<=n;i++) cout<<w[i]<<endl;
	//for(int i=1;i<=n;i++) cout<<i<<' '<<sum[i]<<' '<<val[i]<<' '<<endl;
	while(L<=R)
	{
	//	cout<<mid<<endl;
	     mid=L+(R-L)/2;
	     if(check(mid)) L=mid+1,ANS=mid;
	     else R=mid-1;
	}
///	double en=clock();
//	cout<<en-st<<endl;
	cout<<ANS;
	return 0;
}
