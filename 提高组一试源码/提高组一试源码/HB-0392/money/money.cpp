#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define re register int
using namespace std;
const int maxn=105;
int n;
bool f[25005];
int a[maxn];
int tmp[maxn];
inline int read()
{
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c&15),c=getchar();
	return x;
}
void dp(const int &x)
{
	int i=x;
	while(i<=a[n]) f[i]=1,i+=x;
	for(re i=1;i<=tmp[0];i++)
	{
		for(re j=0;j<=a[n]-tmp[i];j++)
		{
			f[j+tmp[i]]|=f[j];
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	re t=read();
	while(t--)
	{
		n=read();
		tmp[0]=0;
		memset(f,0,sizeof f);
		for(re i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		f[0]=1;
		for(re i=1;i<=n;i++)
		{
			if(f[a[i]]) continue;
			tmp[++tmp[0]]=a[i];
			dp(a[i]);
		}
		printf("%d\n",tmp[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
