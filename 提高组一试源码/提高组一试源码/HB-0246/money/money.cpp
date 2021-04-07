#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int n;
long long a[110];
int mark[110];
int ans;
void cmp1()
{
	for(int i=1 ; i<=n ; i++)
		if(!mark[i])
			for(int j=i+1; j<=n; j++)
				if(a[j]%a[i]==0) mark[j]=1;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin >> t;
	for(int i=1; i<=t; i++)
	{
		cin>>n;
		ans=n;
		for(int j=1; j<=n; j++) cin>>a[j];
		sort(a+1,a+n+1);
		if(n==2)
		{
			if(a[2]%a[i]==0) cout<< 1 <<endl;
			else cout<< 2 <<endl;
			continue;
		}
		memset(mark,0,sizeof(mark));
		if(n==3)
		{
			cmp1();
			if(mark[2]&&mark[3])
			{
				cout << 1 <<endl;
				continue;
			}
			if((mark[2]==1)&&(mark[3]==0))
			{
				cout << 2 <<endl;
				continue;
			}
			if((mark[2]==0)&&(mark[3]==1))
			{
				cout << 2 <<endl;
				continue;
			}
			if((mark[2]==0)&&(mark[3]==0))
			{
				int cha=a[3]-a[2];
				while (cha>=a[1])
				{
					if(cha%a[1]==0)
						break;
					cha-=a[2];
				}
				if(cha%a[1]==0 ) cout << 2 <<endl;
				else cout << 3 <<endl;
				continue;
			}
		}
		cmp1();
		for(int i=1; i<=n; i++) if(mark[i]==1) ans--;
		cout<<ans<<endl;
	}
	return 0;
}
