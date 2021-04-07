#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#define re register int
#define in inline
using namespace std;
const int N=100+10;
int T,m,n,a[N],tmp[N],x,over,ans;
in void get(re &x){
	x=0;re f=1;
	register char c;
	while(!(c<='9'&&c>='0')){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
	x*=f;	
}
in int gcd(re x,re y){
	return y==0?x:gcd(y,x%y);
}
in bool dfs(re tgt,re t,re x,re mx,re sum){
	if(t==x+1){
		if(sum==tgt)return 1;
		else return 0;
	}
	for(re i=0;i<=mx/a[t];++i){
		if(dfs(tgt,t+1,x,mx,sum+i*a[t]))return 1;
	}
	return 0;
}
in bool calc(re tgt,re x){
	int mx=a[1]*a[2]-a[1]-a[2];
	if(tgt>mx)return 1;
	return dfs(tgt,1,x,mx,0);
}
in bool work(re x){
	for(re i=x+1;i<=n;++i)
		if(!calc(a[i],x))return 0;
	return 1;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	get(T);
	while(T--){
		memset(a,0,sizeof(a)),get(m),n=over=0;
		for(re i=1;i<=m;++i){
			get(tmp[i]);
			if(tmp[i]==1)over=true;
		}
		if(over||m==1){printf("1\n");continue;}
		sort(tmp+1,tmp+1+m);
		for(re i=m;i>0;--i){
			over=0;
			for(re j=i-1;j>0;--j)
				if(tmp[i]%tmp[j]==0)over=1;
			if(over==0)a[++n]=tmp[i];
		}
		if(n==1){printf("1\n");continue;}
		if(n==2){printf("2\n");continue;}
		for(re i=1;i<=n/2;++i)swap(a[i],a[n-i+1]);
		ans=n;
		for(re i=2;i<n;++i)
			if(work(i)){ans=i;break;}
		printf("%d\n",ans);
	}
	return 0;
}
