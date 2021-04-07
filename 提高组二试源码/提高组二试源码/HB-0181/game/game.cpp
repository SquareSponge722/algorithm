#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000050,ha=1e9+7;
long long f[maxn][10];
int n,m;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	if(m<n)
		swap(m,n);
	f[1][0]=f[1][1]=1;
	f[2][0]=2;
	f[2][1]=2;
	f[2][2]=2;
	for(int i=3;i<=n+m-1;i++){
		int x;
		bool flag=false;
		if(i<=n)
			x=i;
		else if(i>=m)
			x=m+n-i;
		else
			x=n,flag=true;
		for(int j=1;j<=x;j++){
			if(!flag)
				f[i][j]=(f[i][j]+f[i-1][j])%ha;
			else{
				f[i][j]=(f[i][j]+f[i-1][j+1])%ha;
			}
			f[i][0]=(f[i][0]+f[i-1][j])%ha;
		}
		f[i][0]=(f[i][0]+f[i-1][0])%ha;
	}
	printf("%lld\n",(f[n+m-1][0]+f[n+m-1][1]*8)%ha);
	return 0;
}
