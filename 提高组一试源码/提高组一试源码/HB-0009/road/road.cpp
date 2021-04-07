#include<bits/stdc++.h>
using namespace std;
#define fre(a) ifstream cin(a".in");ofstream cout(a".out")
#define FOR(i,a,b) for(i=a;i<=b;++i)
int minh=9999999,p,flag,l,r;
int q[1000001],top,head,a[100001],mina=99999999;
long long sum;
int main() {
	fre("road");
	int n,i,j,h;
	cin>>n;
	FOR(i,1,n)
		{cin>>a[i];}
	
	FOR(i,1,n)
	{
		if(a[i]<a[i+1])
		{
			while(i<=n&&a[i]<a[i+1])i++;
		}
		if(a[i]>a[i+1])
		{
			sum+=a[i];
			while(i<=n&&a[i]>a[i+1])i++;
			if(i<n)
			sum-=a[i];
		}
		
	}
	cout<<sum;
}
