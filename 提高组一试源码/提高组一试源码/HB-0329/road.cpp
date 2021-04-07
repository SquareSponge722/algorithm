#include<cstdio>
#define N 100005
#define For(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
int d[N];
int ans;

int read(){
	int p=1,q=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0'&&c<='9'){q=q*10+c-'0';c=getchar();}
	return p*q;
}

int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	n=read();
	For(i,1,n){
		d[i]=read();
		if(d[i]>d[i-1])ans+=d[i]-d[i-1];
	}
	printf("%d",ans);
	return 0;
}
