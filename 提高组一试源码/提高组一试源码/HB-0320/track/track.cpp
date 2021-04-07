#include<bits/stdc++.h>
using namespace std;
int m,s,x,y=0,n;
int c[10001];
bool a[50001]={0},b[50001]={0};
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
    s+=x;
	cout<<x<<endl;
	return 0;
}
int print(int n)
{
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
    }
    s+=x;
}
int search(int n)
{
	for(int i=1;i<=n-1;i++)
	if(!a[i]&&!b[i])
	{
	    search(1);
		x=c[i];
		a[i]=1;
		b[i]=1;
		if(i==n-1) cout<<s<<endl;
		else search(n);
		a[i]=0;
		b[i]=0;
	}
}
