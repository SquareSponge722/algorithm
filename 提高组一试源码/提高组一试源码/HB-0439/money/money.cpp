#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<cstring>
#define ll long long
#define inf 1e9
#define maxn 100005
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return w==1?x:-x;
}

int a[maxn],tot,b[maxn],cnt,ans,mx,flag;
bool vis[maxn],che[maxn];
vector <int> vec;
vector <int> vec2;

inline bool jud(int x,int y,int z)
{
	int tmp=b[x]*b[y]/__gcd(b[x],b[y]); z=b[z]; z%=tmp;
	for(int i=1;i<=1000;i++)
	{
		if(b[x]*i>z) break;
		if((z-b[x]*i)%b[y]==0) return true;
	}
	return false;
}

inline int getn(int x)
{
	int cnt=0;
	while(x)
	{
		if(x&1) cnt++;
		x>>=1;
	}
	return cnt;
}

inline bool jud3(int res,int dep)
{
	if(dep==0) return false;
	if(res%vec[dep-1]==0) {flag=0; return true;}
	for(int i=0;i<=1000;i++)
	{
		if(vec[dep-1]*i>res) return false;
		else jud3(res-vec[dep-1]*i,dep-1);
	}
	return false;
}

inline bool jud2(int sta)
{
	vec.clear(); vec2.clear(); int cnt2=0; flag=1;
	for(int i=1;i<=cnt;i++)
	{
		if(sta&(1<<(i-1))) vec.push_back(b[i]),cnt2++;
		else vec2.push_back(b[i]);
	}
	for(int i=0;i<vec2.size();i++)
	{
		jud3(vec2[i],cnt2);
		if(flag==1) return false;
	}
	return true;
}


int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read(); cnt=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		tot=unique(a+1,a+n+1)-a-1;
		for(int i=1;i<=n;i++) for(int j=1;j<i;j++) if(a[i]%a[j]==0) vis[i]=1;
		for(int i=1;i<=n;i++) if(vis[i]!=1) b[++cnt]=a[i]; ans=cnt; mx=b[cnt];
		int ed=(1<<cnt)-1;
		if(cnt==1)
		{
			cout<<"1"<<endl;
		}
		else if(cnt==2)
		{
			if(b[2]%b[1]==0) cout<<"1"<<endl;
			else cout<<"2"<<endl;
		}
		else if(cnt==3)
		{
			if(jud(1,2,3)) cout<<"2"<<endl;
			else if(jud(2,3,1)) cout<<"2"<<endl;
			else if(jud(1,3,2)) cout<<"2"<<endl;
			else cout<<"3"<<endl;
		}
		else
		{
			for(int i=1;i<=ed;i++) if(jud2(i)) ans=min(ans,getn(i));
			cout<<ans<<endl;
		}
	}
	return 0;
}
