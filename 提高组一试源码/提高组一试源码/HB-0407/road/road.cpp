#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define rep(i,j,k) for(int i=j;i<=k;i++)
typedef unsigned long long ull;
using namespace std;
int n;int d[100001];
int dir[100001];//Compared to last
int read(){
	char ch=getchar();int f=1,x=0;
	while(ch<'0' || ch>'9'){ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
ull solve(int l,int r,int delta){
	int method=0,cnt=0;int ans1=0;ull ans2=0;int mid=-1;
	rep(i,l+1,r){
		if(dir[i]!=dir[i+1] && dir[i]!=0 && dir[i+1]!=0){
			//no regu
			method=1;
		}
	}
	if(method==0){
		rep(i,l,r){
			ans1=max(ans1,d[i]-delta);
		}
		return ans1;
	}
	else if(method==1){
		cnt=0x3f3f3f3f;
		rep(i,l,r){
			if(cnt>d[i]-delta){
				cnt=d[i]-delta;
				mid=i;
			}
		}
		ans2+=cnt;
		ans2+=solve(l,mid-1,delta+cnt);
		ans2+=solve(mid+1,r,delta+cnt);
		return ans2;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	rep(i,1,n){
		d[i]=read();
		if(d[i-1]>d[i])dir[i]=-1;
		else if(d[i-1]==d[i])dir[i]=0;
		else dir[i]=1;
	}
	printf("%llu",solve(1,n,0));
	return 0;
}
