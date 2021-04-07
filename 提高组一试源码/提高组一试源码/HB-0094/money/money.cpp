#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#define MAXN 110
#define MAXM 60000
using namespace std;
int n,cnt,t,mx,ti;
int a[MAXN],book[MAXN],b[MAXN];
int read()
{
	char ch=getchar();
	int sum=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum;
}

void check()
{
	int maxn;
	book[0]=t;
	for(int i=1;i<=n;++i)
	{
		if(book[b[i]]==t)
		--cnt;
		else 
		{
			maxn=mx-b[i];
			for(int j=0;j<=maxn;++j)
			if(book[j]==t)book[j+b[i]]=t;
		}
	}
	return;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ti=read();
	while(ti--)
	{
		++t;
		cnt=mx=0;
		n=read();
		for(int i=1;i<=n;++i)
		{
			b[i]=read();
			mx=max(mx,b[i]);
		}
		sort(b+1,b+n+1);
		cnt=n;
		check();
		cout<<cnt<<endl;
	}
	return 0;
}
