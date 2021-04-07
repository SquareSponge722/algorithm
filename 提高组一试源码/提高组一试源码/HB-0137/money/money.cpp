#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ymd(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int maxn=105,inf=0x7fffffff;
int n,m,a[maxn];
bool nbn(int a,int b,int c) {
	FOR(i,1,c)FOR(j,1,c) {
		if(pow(a,i)>c)break;
		if(pow(a,i)+pow(b,j)>c)continue ;
		if(pow(a,i)+pow(b,j)==c)return 1;
	}
	return 0;
}
void solve() {
	//Ð¡¿­µÄÒÉ»ó2333
	bool b[maxn]= {};
	int cnt=0,xk[10000]= {},kk[10000]= {};
	FOR(i,1,n)FOR(j,1,n)if(!b[i]&&!b[j]&&i!=j) {
		if(a[i]%a[j]==0)b[i]=1;
		else if(a[j]%a[i]==0)b[j]=1;
		else {
			int ys=__gcd(a[i],a[j]);
			xk[++cnt]=ys*((a[i]/ys)*(a[j]/ys)-(a[i]/ys)-(a[j]/ys));
			kk[cnt]=ys;
//			printf("%d %d\n",a[i],a[j]);
		}
	}
//	FOR(i,1,cnt)printf("%d %d\n",xk[i],kk[i]);
//		FOR(i,1,n)FOR(j,1,n)if(i!=j&&!b[i]&&!b[j])
	FOR(i,1,n)if(!b[i]) {
		FOR(j,1,cnt)if(a[i]>=xk[j]&&a[i]%kk[j]==0)b[i]=1;
	}
//		xk=min(xk,a[i]*a[j]-a[i]-a[j]);
//		printf("xk %d\n",xk);
//	FOR(i,1,n)if(!b[i]&&a[i]>xk)//cout<<i<<endl,
//		m--;
	sort(a+1,a+n+1);
	FOR(i,1,n)FOR(j,i+1,n)FOR(k,j+1,n)if(!b[i]&&!b[j]&&!b[k]) {
		if(nbn(a[i],a[j],a[k]))b[k]=1;
	}
	FOR(i,1,n)if(b[i])m--;
	printf("%d\n",m);
	return ;
}
void solve3() {
	bool b[5]= {};
	sort(a+1,a+4);
	if(a[2]%a[1]==0)b[2]=1;
	if(a[3]%a[1]==0)b[3]=1;
	if(!b[2]&&!b[3]&&a[3]%a[2]==0)b[2]=0;
	int cat=0;
	FOR(i,1,3)if(b[i])cat++;
	if(cat) {
		printf("%d\n",3-cat);
		return ;
	}
	if(nbn(a[1],a[2],a[3])) {
		b[3]=1;
		printf("2\n");
		return ;
	}
	printf("3\n");
	return ;
}
void Zack() {
	int t=read();
	while(t--) {
		bool flag1=0;
		n=read();
		m=n;
		FOR(i,1,n) {
			a[i]=read();
			if(a[i]==1)flag1=1;
		}
		if(flag1) {
			printf("1\n");
			continue;
		}
		if(n==2) {
			if(a[1]%a[2]==0||a[2]%a[1]==0)printf("1\n");
			else printf("2\n");
		} else if(n==3) {
			solve3();
		} else {
			solve();
		}
	}
	return ;
}
int main() {
	ymd("money");
	Zack();
	return 0;
}
