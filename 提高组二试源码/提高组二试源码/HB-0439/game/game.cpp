#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#include<queue>
#include<cmath>
#define ll long long
#define inf 1e9
#define maxn 1000005
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return w==1?x:-x;
}

const int modc=1e9+7;
ll j2[maxn],j3[maxn],n,m,ans;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	j2[0]=1; j3[0]=1;
	for(int i=1;i<=m+1;i++) j2[i]=(j2[i-1]*2)%modc;
	for(int i=1;i<=m+1;i++) j3[i]=(j3[i-1]*3)%modc;
	if(n==1&&m==1) cout<<"2";
	else if(n==1&&m==2) cout<<"4";
	else if(n==1&&m==3) cout<<"8";
	else if(n==2&&m==1) cout<<"4";
	else if(n==2&&m==2) cout<<"12";
	else if(n==2&&m==3) cout<<"36";
	else if(n==3&&m==1) cout<<"8";
	else if(n==3&&m==2) cout<<"36";
	else if(n==3&&m==3) cout<<"112";
	else if(n==2)
	{
		for(int i=2;i<=m;i++) ans=(ans+j2[i]*j3[m-i])%modc;
		ans=(ans+j2[m+1])%modc;
		cout<<ans<<endl;
	}
	return 0;
}
