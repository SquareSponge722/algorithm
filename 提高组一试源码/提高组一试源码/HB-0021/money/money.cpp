#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int _min(int x,int y) {return x<y?x:y;}
int mygcd(int x,int y)
{
	if(!y) return x;
	else return mygcd(y,x%y);
}
int n,m,a[150],ans;
int x,y,z;
bool flag,flag1;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&m);
	while(m--)
	{
		flag=false;
		ans=0;
		int temp=999999999;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1) flag=true;
		}
		if(flag) printf("1\n");
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			if(mygcd(a[i],a[j])==1)
			if(temp>a[i]*a[j]-a[i]-a[j])
			{
				temp=a[i]*a[j]-a[i]-a[j];
				x=a[i],y=a[j],z=x+y;
				if(x>y) swap(x,y);
				
			}
		if(temp==999999999) printf("2\n");
		//cout<<temp<<endl;
		for(int i=1;i<=n;i++)
		if(temp>a[i]) 
		{
			flag1=true;
			for(int j=0;a[i]-y*j>=0;j++)
			if((a[i]-y*j)%x==0) 
			{
				flag1=false;
				break;
			}
			if(flag1) ans++;
			//cout<<a[i]<<" ";
		}
		printf("%d\n",ans+2);
	}
	return 0;
}
