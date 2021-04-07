#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
short T;
bool b[33000];
int a[110];
bool over(short n)
{
	for(int y=1;y<=n;y++)
	if(b[a[y]]==0) 
	return true;
	return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for(int sss=1;sss<=T;sss++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		short n;
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+1+n);
		int che=1;
		for(int i=a[1];i*che<=a[n];che++)
		b[i*che]=1;
		int ans=1;
		int age=2;
		while(b[a[age]]==1) age++;
		while(over(n))
		{
			b[a[age]]=1;
			ans++;
			for(int x=a[1];x<a[n];x++)
			if(b[x]==1)
			{
				int che=1;
				for(int i=a[age];x+i*che<=a[n];che++)
				b[x+i*che]=1;
			}
			else;
			age++;
			while(b[a[age]]==1) age++;
			if(age>n) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
