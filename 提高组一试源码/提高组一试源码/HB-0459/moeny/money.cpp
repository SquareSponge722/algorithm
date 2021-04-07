#include<bits/stdc++.h>
using namespace std;
//ifstream fin("moeny.in");
//ofstream fout("moeny.out");
int T,n,a[110],num[110],cnt;
bool flag;
int xs[110];
bool vis[110];

void dfs(int k,int now,int nnum)
{
	if(flag==1)
	return;
	
	if(now==k)
	{
	
		if(nnum==num[k])
		flag=1;
		return;
	}
	if(vis[now])
	dfs(k,now+1,nnum);
	for(int i=0;nnum+num[now]*i<=num[k];i++)
	{
		xs[now]=i;
		dfs(k,now+1,nnum+i*num[now]);
		xs[now]=0;
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		//=======//
		if(a[1]==1)
		{
			cout<<"1"<<endl;
			memset(a,0,sizeof(a)); 
			continue;
		}
		for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
	    {
		if(a[i]==0||a[j]==0)
		continue;
		if(a[j]%a[i]==0)
		{
		a[j]=0;
	    }
	    }
	    for(int i=1,j=1;i<=n;i++)
	    {
	    	if(a[i])
	    	num[++cnt]=a[i];
		}
	
		//=======//
		if(cnt==2)
		{
		cout<<"2"<<endl;
		}
		if(cnt==1)
		{
		cout<<"1"<<endl;
		}
		//=======//
		if(cnt>2)
		{
			int ans=cnt;
//			for(int i=1;i<=cnt-2;i++)
//			{
//				if(!vis[i])
//			for(int j=i+1;j<=cnt-1;j++)
//			{
//				if(!vis[j])
//			for(int k=j+1;k<=cnt;k++)
//			{
//				if(!vis[k])
//				for(int ii=0;ii*num[i]<=num[k];ii++)
//				for(int jj=0;jj*num[j]+ii*num[i]<=num[k];jj++)
//				{
//					if(jj*num[j]+ii*num[i]==num[k])
//					{
//						ans--;
//						vis[k]=1;
//					}
//				}
//			}
//		}
//		}
		for(int i=3;i<=cnt;i++)
		{
			memset(xs,0,sizeof(xs));
			dfs(i,1,0);
			if(flag)
			{
			vis[i]=1;
			ans--;
			flag=0;
		    }
		}
		cout<<ans<<endl;
		}
		cnt=0;
		memset(num,0,sizeof(num));
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
