#include<bits/stdc++.h>
using namespace std;
#define fre(a) ifstream cin(a".in");ofstream cout(a".out")
#define FOR(i,a,b) for(i=a;i<=b;++i)
int sum,flag;
int a[100001];
void f(int pl,int p,int q,int tot)
{
	if(q==tot&&pl<=p)
	{
		flag=1;return;
	}
	else if(pl<p)
	for(int i=0;!flag&&tot+a[pl]*i<=q;++i)
	{
		f(pl+1,p,q,tot+a[pl]*i);
	}
}
int main()
{
	fre("money");
	int T,n,i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		sum=n;
		FOR(i,1,n)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		FOR(i,2,n)
		{
			flag=0;
			f(1,i,a[i],0);
			if(flag)
			sum--;
		}
		cout<<sum<<'\n';
		FOR(i,1,n)
		a[i]=0;
	}
	return 0;
}
