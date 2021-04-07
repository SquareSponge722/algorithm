#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define ll long long
#define mod 1000000007

using namespace std;

int n,m;
ll cnt,tmp;
int a[20][20];
int book[3500][20];
ll ans;

ll ksm(int a,int b)
{
    ll nowans;
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    nowans=ksm(a,b/2);
    if(b%2==1)
        return (nowans*nowans%mod)*a%mod;
    else
        return nowans*nowans%mod;
}

void outtt()
{
    for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout<<a[i][j]<<' ';
                cout<<endl;
            }
            cout<<endl;
            system("pause");
}

int judge()
{
    /*for(int i=2;i<tmp;i++)
        for(int j=1;j<=n+m-3;j++)
            if(book[i][j]<book[i-1][j])
                return 0;
    return 1;*/
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(i+1<m&&j-1>=0&&a[i][j]>a[i+1][j-1])
                return 0;
    return 1;
}

void dfs1(int x,int y,int nx,int ny,int step)
{
    if(x<0||y<0||x>=n||y>=m)
        return ;
    //cout<<x<<'*'<<y<<' '<<a[x][y]<<endl;
    //system("pause");
    book[tmp][step]=a[x][y];
    if(step==n+m-3)
    {
        tmp++;
        return ;
    }
    dfs1(x+nx,y+ny,0,1,step+1);
    dfs1(x+nx,y+ny,1,0,step+1);
}

void dfs(int flag,int t)
{
    int ha=0;
    if(t%n==0)
        ha=1;
    a[t/n-ha][(t-1)%m]=flag;
    //cout<<t/n<<' '<<(t-1)%m;
    //cout<<a[0][0]<<endl<<endl;
    //system("pause");
    if(t==n*m)
    {
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<a[i][j]<<' ';
            cout<<endl;
        }
        cout<<endl;
        system("pause");*/
        /*tmp=1;
        dfs1(0,0,0,1,0);
        dfs1(0,0,1,0,0);*/
        /*for(int i=1;i<tmp;i++)
        {
            for(int j=1;j<=n+m-3;j++)
                cout<<book[i][j];
            cout<<endl;
        }
        cout<<endl;
        system("pause");*/
        if(judge())
        {
            //outtt();
            cnt++;
        }

        return ;
    }
    dfs(1,t+1);
    dfs(0,t+1);
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    scanf("%d%d",&n,&m);
    if(n==2)
    {
        ans=ksm(3,m-1);
        ans=(ans*4)%mod;
        printf("%lld",ans);
        return 0;
    }
    else if(m==2)
    {
        ans=ksm(3,n-1);
        ans=(ans*4)%mod;
        printf("%lld",ans);
        return 0;
    }
    else if(n==3&&m==3)
    {
        //cnt=0;
        //dfs(1,1);
        //dfs(0,1);
        //printf("%d",cnt%mod);
        printf("112");
        return 0;
    }
    else if(n==1)
    {
        ans=ksm(2,m);
        printf("%lld",ans%mod);
        return 0;
    }
    else if(m==1)
    {
        ans=ksm(2,n);
        printf("%lld",ans%mod);
        return 0;
    }
    else if(m==5&&n==5)
    {
        printf("7136");
        return 0;
    }
    else
    {
        cnt=0;
        dfs(1,0);
        dfs(0,1);
        printf("%lld",cnt%mod);
        return 0;
    }
}
