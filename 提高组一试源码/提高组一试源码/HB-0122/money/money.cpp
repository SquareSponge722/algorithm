#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t,ans=0,flag=0;
int a[105],b[105];
inline int read()
{
	int q=0,w=0;
	char c=getchar(); 
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') q=1,c=getchar();
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}
inline int f(int x)
{
	for(int j=1;j<=ans;j++)
	{
	
	if(x-b[j]==0) {flag=1;return 1;}
	if(x<b[1]&&flag==0) return 0;
	if(flag==1) return 1;
	if(x-b[j]>0&&f(x-b[j])==0) continue;
	if(x-b[j]<0&&flag==0) return 0;
		
	}
	
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	for(int lt=1;lt<=t;lt++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		a[i]=read();
		sort(a+1,a+n+1);
		ans++;b[ans]=a[1];
		for(register int i=2;i<=n;i++)
//		for(int j=1;j<=ans;j++)
		{
			int e=f(a[i]);
			if(flag==0) 
			ans++,b[ans]=a[i];
			flag=0;
		}cout<<ans<<endl;
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));ans=0;
	}
	
	return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
