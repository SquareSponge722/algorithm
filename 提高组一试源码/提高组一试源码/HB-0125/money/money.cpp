#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long inf=100000007;
int t;
int n;
int b[10010];
int flag[1000010];
int p[1000010],pp[1000010];
long long a[110];
long long mint=2147483647;
int ans=0;

int gcd(int x,int y)
{
	if( y > x ) swap(x,y);
	if( y == 0 ) return x;
	else return gcd(y,x%y);
}

void xxs()
{
	for(int i=a[1];i<=mint;i++)
	{
		if( p[i] == 1 )
		{
			for(int j=1;j<=n;j++)
			{
				int xx=i+a[j];
				if( xx > mint ) break;
				if( flag[xx] == 1 && pp[xx] == 0 )
				{
					pp[xx]=1;
					ans++;
				}
				p[xx]=1;
			}
		}
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
		    cin>>a[i];
		    b[i]=0;
		}
		memset(flag,0,sizeof(flag));
		memset(p,0,sizeof(p));
		memset(pp,0,sizeof(pp));
		sort(a+1,a+n+1);
		
		int cnt=0;
		mint=2147483647;
		
		for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
		{
			if( a[i]%a[j] == 0 && b[i] == 0 )
			{
				a[i]=inf;
				b[i]=1;
				cnt++;
			}
			
			if( gcd(a[i],a[j]) == 1 && b[i] == 0 && b[j] == 0 && a[i] != 2 && a[j] != 2 )
			{
				mint=min(mint,(a[i]-1)*(a[j]-1)-1);
			}
			
			if( a[i] > mint && b[i] == 0 )
			{
			    a[i]=inf;
			    b[i]=1;
			    cnt++;
			}
		}
		
		sort(a+1,a+n+1);
		if( mint == 2147483647 ) mint=a[1];
		n-=cnt;
		for(int i=1;i<=n;i++)
		{
			flag[a[i]]=1;
			p[a[i]]=1;
		}
		ans=0;
		xxs();
		n-=ans;
		cout<<n<<endl;
	}
	return 0;
}
