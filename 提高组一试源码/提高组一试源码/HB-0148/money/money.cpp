//chf sj ycy -||- 
#include<bits/stdc++.h>

using namespace std;

#define rep(i,x,y) for(register int i=x;i<=y;i++)
#define rrep(i,x,y) for(register int i=x;i>=y;i--)

typedef long long ll;
typedef double db;

const int maxn=1e5;

int T,n,Ans;
int a[maxn+10];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void work()
{
	T=read();
	while(T--)
	{
		n=read();
		rep(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
		if(n==2) {Ans=2; if(a[2]%a[1]==0) Ans--;}
		else if(n==3)
		{
			Ans=3;
			if(a[3]%a[1]==0) Ans--;
			else if(a[3]%a[2]==0) Ans--;
			else for(int i=0;i*a[1]<=a[3];i++)
				 	 for(int j=0;j*a[2]<=a[3];j++)
						 if(i*a[1]+j*a[2]==a[3]){Ans--;goto HBHB;}
			HBHB:;
			if(a[2]%a[1]==0) Ans--;
		}
		else if(n==4)
		{
			Ans=4;
			if(a[2]%a[1]==0) Ans--;
			for(int i=0;i*a[1]<=a[3];i++)
				for(int j=0;j*a[2]<=a[3];j++)
					if(i*a[1]+j*a[2]==a[3]){Ans--;goto HAHA;}
			HAHA:;
			for(int i=0;i*a[1]<=a[4];i++)
				for(int j=0;j*a[2]<=a[4];j++)
					for(int k=0;k*a[3]<=a[4];k++)
						if(i*a[1]+j*a[2]+k*a[3]==a[4]){Ans--;goto HEHE;}
			HEHE:;
		}
		else if(n==5)
		{
			Ans=5;
			if(a[2]%a[1]==0) Ans--;
			for(int i=0;i*a[1]<=a[3];i++)
				for(int j=0;j*a[2]<=a[3];j++)
					if(i*a[1]+j*a[2]==a[3]){Ans--;goto ZJZJ;}
			ZJZJ:;
			for(int i=0;i*a[1]<=a[4];i++)
				for(int j=0;j*a[2]<=a[4];j++)
					for(int k=0;k*a[3]<=a[4];k++)
						if(i*a[1]+j*a[2]+k*a[3]==a[4]){Ans--;goto JSJS;}
			JSJS:;
			for(int i=0;i*a[1]<=a[5];i++)
				for(int j=0;j*a[2]<=a[5];j++)
					for(int k=0;k*a[3]<=a[5];k++)
						for(int l=0;l*a[4]<=a[5];l++)
							if(i*a[1]+j*a[2]+k*a[3]+l*a[4]==a[5]){Ans--;goto HNHN;}
			HNHN:;
		}
		else Ans=n;
		printf("%d\n",Ans);
	}
} 

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	work();
	return 0;
}
