//money
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define FOR(i,n,m) for(int i=n;i<=m;++i)
#define ROF(i,n,m) for(int i=n;i>=m;--i)
using namespace std;
int T,n,m;
int a[110];
bool b[110];

inline int read()
{
	int x=0,p=1; char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') p=0,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return p?x:-x;
}

void part_1()
{
	if(a[2]%a[1]==0) {cout<<1<<endl; return ;}
	else cout<<2<<endl;
	return ;
}

void part_2()
{
	FOR(i,1,n-1) FOR(j,i+1,n) if(b[i]&&b[j]&&a[j]%a[i]==0) b[j]=0;
	if(b[1]&&b[2]&&b[3])
	{
		for(int i=1;i*a[1]<=a[3];++i)
		    for(int j=1;j*a[2]<=a[3];++j)
		        if(i*a[1]+j*a[2]==a[3]) b[3]=0;
	}
	FOR(i,1,n) if(b[i]) m++;//,cout<<a[i]<<' ';
//	cout<<endl;
	cout<<max(m,1)<<endl;
}

void part_3()
{
	FOR(i,1,n-1) FOR(j,i+1,n) if(b[i]&&b[j]&&a[j]%a[i]==0) b[j]=0;
	ROF(k,n,3)
		FOR(i,1,n-2)
		    FOR(j,i+1,n-1)
		    	if(j<k&&b[i]&&b[j]&&b[k])
		    	{
		    		for(int ii=1;ii*a[i]<=a[k];++ii)
		                for(int jj=1;jj*a[j]<=a[k];++jj)
		                    if(ii*a[i]+jj*a[j]==a[k]) b[k]=0;
				}
	FOR(i,1,n) if(b[i]) m++;//,cout<<a[i]<<' ';
//	cout<<endl;
	cout<<max(m,1)<<endl;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(a,0,sizeof(a));
		n=read(); m=0;
		FOR(i,1,n) b[i]=1;
		FOR(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
//		FOR(i,1,n) cout<<a[i]<<' '; cout<<endl;
		if(n==2) {part_1(); continue;}
		else if(n==3) {part_2(); continue;}
		else {part_3(); continue;}
	}
	return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17

2
2
3 5
3
3 9 5
*/
