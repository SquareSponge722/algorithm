#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[101];
int dp(int a,int b,int c)
{
	bool f[c+3];
	int ans=3;
	for(int i=0;i<=c;i++)
	f[i]=0;
	f[0]=1;
	if(a>b) swap(a,b);
	for(int i=a;i<=c;i++)
	if(f[i-a]||f[i-b]) f[i]=1;
	if(f[c]) ans--;
	if(a%b==0||b%a==0) ans--;
	return ans;
}
void check()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n==2)
	{
		if(a[1]%a[2]==0||a[2]%a[1]==0) cout<<1<<endl;
		else cout<<2;
	}
	if(n==3)
	{
		int x1=dp(a[1],a[2],a[3]);
		int x2=dp(a[1],a[3],a[2]);
		int x3=dp(a[2],a[3],a[1]);
		cout<<min(min(x1,x2),x3)<<endl;
	}
	else if(n!=2&&n!=3)cout<<n<<endl;
	return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	check();
	return 0;
}
