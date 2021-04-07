#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int a[1001];
bool can[25001];

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

int gcd(int m,int n){
	if(n==0) return m;
	else return gcd(n,m%n);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,t;
	t=read();
	while(t--){
		int m=0;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		sort(a+1,a+n+1);
/*		for(int i=n;i>1;--i){
			bool cant=0;
			int ttt=a[i-1]*a[i-2]-a[i-1]-a[i-2];
			for(int j=ttt;j>a[i-1];j-=a[i-1]){
				if(a[i]==j){cant=1;break;} 
			}
			if(cant){++m;continue;}
			for(int j=ttt;j>a[i-2];j-=a[i-2]){
				if(a[i]==j){cant=1;break;} 
			} 
			if(cant){++m;continue;}
		}
		printf("%d\n",m);*/
		int k=2;
		while(gcd(a[1],a[k])!=1) ++k;
	    int ttt=a[1]*a[k]-a[1]-a[k];
//	can=new bool[ttt+1];
	memset(can,0,sizeof(can));
	can[a[1]]=can[a[k]]=can[ttt]=1;
/*	for(j=ttt;j>0;j-=a[1]) 
	can[j]=1;
	for(j=ttt;j>0;j-=a[k]) 
	can[j]=1;*/
	for(int j=ttt;j;--j){
		if(can[j])
		 can[j-a[1]]=can[j-a[k]]=1;
	}
	for(int i=1;(a[i]<=ttt)&&(i<=n);++i){
		if((can[a[i]])) ++m;
	}
	printf("%d\n",m);
    }
    fclose(stdin);fclose(stdout);
	return 0;
}
