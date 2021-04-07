#include<cstdio>
using namespace std;
const int N=100000+5;
int d[N],t[N],s[N],n;
long long ans=0ll;

void read(int &x){
	char ch=getchar();x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
}
//inline void add(int i,int w){for(;i<=n;i+=i&(-i)) t[i]+=w;}
inline void add2(int i,int w){for(;i<=n;i+=i&(-i)) s[i]+=w;}
inline int query(int i){int res=0;for(;i>0;i-=i&(-i)) res+=s[i];return res;}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	for(register int i=1;i<=n;++i){
		read(d[i]);//,add(i,d[i]-d[i-1]);
		if(!d[i]) add2(i,1);	
	}
	for(register int i=1,j;i<=n;++i){
		j=n;
		int sum=query(i-1);
		while(j>=i){
			if(i==j&&!d[i]) break;
			if(!(query(j)-sum)){
				++ans;
				for(int k=i;k<=j;++k){
					--d[k];if(!d[k]) add2(k,1);
				}
			}
			else --j;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
