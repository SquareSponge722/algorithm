#include<cstdio>
#include<iostream>
//#include<ctime>
using namespace std;
#define ymd(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
inline int read(){
	register int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int maxn1=100005,inf=0x7fffffff;
int a[maxn1],n;
int paint(int l,int r,int h){
	if(l>r)return 0;
	int minh=l;
	FOR(i,l+1,r)if(a[i]<a[minh])minh=i;
	return a[minh]-h+paint(l,minh-1,a[minh])+paint(minh+1,r,a[minh]);	
}
void Zack(){
	n=read();
	FOR(i,1,n)a[i]=read();
	printf("%d\n",paint(1,n,0));
	return ;
}
int main(){
//	int st=clock();
	ymd("road");
	Zack();
//	cout<<clock()-st<<endl;
	return 0;
}
