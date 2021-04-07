#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
static char buf[100000],*pa=buf,*pd=buf;
#define gc pa==pd&&(pd=(pa=buf)+fread(buf,1,100000,stdin),pa==pd)?EOF:*pa++
inline int read(){
	register int x(0),f(1);register char c(gc);
	while(c>'9'||c<'0')f=c=='-'?-1:1,c=gc;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=gc;
	return f*x;
}
int T,n;
int a[55000],maps[55000];
bool cmp(int x,int y){
	if(!x)return 0;
	if(!y)return 1;
	return x<y;
}	
int t,tot,ans;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	int m=0;
	while(T--){
		ans=m=0;
		memset(a,0,sizeof(a));
		memset(maps,0,sizeof(maps));
		n=read();
		tot=n;
		for(register int i=1;i<=n;i++)
			a[i]=read();
		if(n==1){
			cout<<1<<'\n';
			continue;
		}
		sort(a+1,a+1+n);
		for(register int i=1;i<=n;i++){	
			if(!a[i])continue;
			for(register int j=i+1;j<=n;j++){
				if(!a[j])continue;
				if(a[j]%a[i]==0)
				a[j]=0,tot--;
			}
		}
		sort(a+1,a+1+n,cmp);
		t=(a[1]-1)*(a[2]-1);
		m=a[tot];
		for(register int i=1;i<=tot;i++)
			if(a[i]>=t){
				m=a[i];
				tot=i;
				break;
			}
		maps[0]=1;
		for(register int i=1;i<=tot;i++)
			if(!maps[a[i]]){
				ans++;
			for(register int j=0;j<=m;j++){
				if(j+a[i]>m)break;
				if(maps[j])maps[j+a[i]]=1;
				}	
			}
		cout<<ans<<'\n';
	}
	return 0;
}
