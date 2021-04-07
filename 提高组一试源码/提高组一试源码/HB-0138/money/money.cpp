#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
const int MAXN=25000;
int T,n,ans,a[105],bac[MAXN+5];
inline int read()
{
    int re=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) re=(re<<3)+(re<<1)+ch-'0',ch=getchar();
    return re;
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    T=read();
    while(T--)
    {
        n=ans=read();
        for(register int i=1;i<=n;i++)
		{
			a[i]=read();
			for(register int j=1;j<i;j++)
				if(a[j]==a[i])
				{
					i--,n--,ans--;
					break;
				}
		}
		memset(bac,0,sizeof bac);
        bac[0]=1;
        for(register int i=1;i<=n;i++)
            for(register int j=0;j<=MAXN-a[i];j++)
                bac[j+a[i]]+=bac[j];
        for(register int i=1;i<=n;i++) if(bac[a[i]]>1) ans--;
        printf("%d\n",ans);
    }
    return 0;
}
