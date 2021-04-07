#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,a[10000],b[10000],out=0,w1=1000000,w2=1000000,c[10000]={0,1,0};
	int r=0,s[10000]={0,1,0};
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int j=1;j<=n;j++)
	{for(int i=1;i<=m;i++)
	 { out=0;
	 	if(a[i]==c[j]){w1=b[i];out=1;}
	 	if(b[i]==c[j]){w2=a[i];out=1;}
	 	
	 	if((out==1&&w1!=1000000&&w1<c[j+1]&&s[w1]==0)||(out==1&&w2==1000000)){c[j+1]=w1;r=i;}
	 	if((out==1&&w2!=1000000&&w2<c[j+1]&&s[w2]==0)||(out==1&&w1==1000000)){c[j+1]=w2;r=i;}
	 }
	 w1=1000000;w2=1000000;
	 
	 s[c[j+1]]=1;
	 a[r]=0;b[r]=0;
    }
	 for(int i=1;i<=n;i++)printf("%d ",c[i]);
	 
	 fclose;
	 return 0;
}
