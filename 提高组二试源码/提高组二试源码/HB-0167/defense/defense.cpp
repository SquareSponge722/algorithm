# include <cstdio>
# include <iostream>
using namespace std;
char type[5];
int fei[100050],dao1[100050],dao2[100050],a[100050],x[100050],b[100050],y[100050];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,i,j,z;
	cin>>n>>m>>type;
	for(i=1;i<=n;i++)
		cin>>fei[i];
	for(i=0;i<n-1;i++)
		cin>>dao1[i]>>dao2[i];
	for(i=0;i<m;i++)
		cin>>a[i]>>x[i]>>b[i]>>y[i];
	for(i=0;i<m;i++)
	{
		int zong1=0,zong2=0;
		for(j=0;j<n-1;j++)
			if(((dao1[j]==a[i]&&dao2[j]==b[i])||(dao1[j]==b[i]&&dao2[j]==a[i]))&&x[i]==0&&y[i]==0)
			{
				z=1;
				break;
			}
		if(z==1) cout<<"-1"<<endl;
		else if(type[1]=='2'&&x[i]==0&&y[i]==0) cout<<"-1"<<endl;
		else if(type[0]=='A'&&(a[i]==b[i]+1||b[i]==a[i]+1)&&x[i]==0&&y[i]==0) cout<<"-1"<<endl;
		else
		{
			for(j=1;j<=n;j+=2)
				zong1+=fei[j];
			if(a[i]%2==0&&x[i]==1)
				zong1+=fei[a[i]];
			else if(a[i]%2==1&&x[i]==0)
				zong1+=(fei[a[i]+1]+fei[a[i]-1]-fei[a[i]]);
			if(b[i]%2==0&&y[i]==1)
				zong1+=fei[b[i]];
			else if(b[i]%2==1&&y[i]==0)
				zong1+=(fei[b[i]+1]+fei[b[i]-1]-fei[b[i]]);
			for(j=2;j<=n;j+=2)
				zong2+=fei[j];
			if(a[i]%2==1&&x[i]==1)
				zong2+=fei[a[i]];
			else if(a[i]%2==0&&x[i]==0)
				zong2+=(fei[a[i]+1]+fei[a[i]-1]-fei[a[i]]);
			if(b[i]%2==1&&y[i]==1)
				zong2+=fei[b[i]];
			else if(b[i]%2==0&&y[i]==0)
				zong2+=(fei[b[i]+1]+fei[b[i]-1]-fei[b[i]]);
			if(zong1>zong2)
				cout<<zong2<<endl;
			else
				cout<<zong1<<endl;
		}
	}
	return 0;
}

