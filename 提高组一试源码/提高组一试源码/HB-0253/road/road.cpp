#include<cstdio>
#include<algorithm>

using namespace std;
int d[100001];

inline int read(){
	int f=1,x=0;
	char c=getchar();
	while((c<'0')||(c>'9')){if(c=='-') f=-1;c=getchar();}
	while((c>='0')&&(c<='9')){
		x=x*10+(int)(c-'0');
		c=getchar();
	}
	return x*f;
}

int work(int l,int r){
	if(l>r) return 0;
	int k=0,minll=9999999;
	for(int i=l;i<=r;++i){
		if(minll>d[i]){
			k=i;
			minll=d[k];
		}
	}
	for(int i=l;i<=r;++i){
		d[i]-=minll;
	}
	return minll+work(l,k-1)+work(k+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,ans=0;
	n=read();
	for(int i=1;i<=n;++i) d[i]=read();
	printf("%d",work(1,n));
	fclose(stdin);fclose(stdout);
	return 0;
}
