#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

int n,t;
int a[105];
int maxx;
bool ha[1000000];

int gcd(int x,int y)
{
    return x%y==0?y:gcd(y,x%y);
}

void book()
{
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(gcd(a[j],a[i]))
            {
                int zh=a[i]*a[j]-a[i]-a[j];
                for(int k=1;k<=zh;k++)
                {
                    if(k<a[i])
                        continue;
                    else if(k==a[i])
                        ha[k]=1;
                    else if(k>a[i]&&k<a[j]&&k%a[i]==0)
                        ha[k]=1;
                    else if(ha[k-a[i]]||ha[k-a[j]])
                        ha[k]=1;
                }
            }
            else
            {
                for(int k=1;k<=maxx;k++)
                {
                    if(k<a[i])
                        continue;
                    else if(k==a[i])
                        ha[k]=1;
                    else if(k>a[i]&&k<a[j]&&k%a[i]==0)
                        ha[k]=1;
                    else if(ha[k-a[i]]||ha[k-a[j]])
                        ha[k]=1;
                }
            }
        }
    return ;
}

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
        memset(ha,0,sizeof(ha));
        scanf("%d",&n);
        if(n==1)
        {
            int x;
            scanf("%d",&x);
            printf("1\n");
            continue;
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1)
                flag=1;
        }
        if(flag)
        {
            printf("1\n");
            continue;
        }
        else
        {
            sort(a+1,a+n+1);
            int flagg=0;
            int cnt=0;
            for(int i=n;i>=1;i--)
            {
                for(int j=i-1;j>=1;j--)
                {
                    if(gcd(a[i],a[j])!=1)
                    {
                        //cout<<endl<<gcd(a[i],a[j])<<endl;
                        maxx=a[i]*a[j]-a[i]-a[j];
                        flagg=1;
                        cnt++;
                        //break;
                    }
                }
                //if(flagg)
                //    break;
            }
            //book();
            /*for(int i=1;i<=maxx;i++)
                cout<<ha[i]<<' ';*/
            printf("%d\n",n-cnt);
        }
    }
    return 0;
}
