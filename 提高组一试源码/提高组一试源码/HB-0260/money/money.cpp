#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[60],b[60];
int cnt;
int cal(int a,int b)
{
    return a*b-a-b;
}
bool vis[100000];
bool can;
void work(int a[])
{
    int ctt=0;
    for(int i=1; i<cnt; i++)
    {
        for(int j=i+1; j<=cnt; j++)
        {
            if(a[j]>a[i]&&a[j]%a[i]==0&&a[j]!=-1&&a[i]!=-1)
            {
                a[j]=-1;
            }
        }
    }
    for(int i=1; i<=cnt; i++)
    {
        if(a[i]>0)
        {
            b[++ctt]=a[i];
        }
    }
    for(int i=1; i<=ctt; i++)
    {
        a[i]=b[i];
    }
    cnt=ctt;
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int xx;
    cin>>xx;
    while(xx--)
    {
        cin>>n;
        can=0;
        cnt=0;
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            if(x==1)can=1;
            if(!vis[x])
            {
                vis[x]=1;
                a[++cnt]=x;
            }
        }
        sort(a+1,a+1+cnt);
        work(a);
        if(n==2)
        {
            if(can==1||cnt==1)cout<<1<<endl;
            else cout<<2<<endl;
        }
        if(n==3)
        {
            if(can==1)cout<<1<<endl;
            else
            {
                if(cnt==1)
                {
                    cout<<1<<endl;
                }
                if(cnt==2)
                {
                    cout<<2<<endl;
                }
                if(cnt==3)
                {
                    int tmp1=cal(a[1],a[2]);
                    int tmp2=cal(a[1],a[3]);
                    int tmp3=cal(a[2],a[3]);
                    if(tmp1<a[3]||tmp2<a[3]||tmp3<a[3])
                    {
                        cout<<2<<endl;
                    }
                    else  cout<<3<<endl;
                }
            }
        }
        if(n==4)
        {
            if(can==1)cout<<1<<endl;
            else
            {
                if(cnt==1)
                {
                    cout<<1<<endl;
                }
                if(cnt==2)
                {
                    cout<<2<<endl;
                }
                if(cnt==3)
                {
                    int tmp1=cal(a[1],a[2]);
                    int tmp2=cal(a[1],a[3]);
                    int tmp3=cal(a[2],a[3]);
                    if(tmp1<a[3]||tmp2<a[3]||tmp3<a[3])
                    {
                        cout<<2<<endl;
                    }
                    else  cout<<3<<endl;
                }
                if(cnt==4)
                {
                    cout<<4<<endl;

                }
            }
        }
        else
        {
            if(can==1)cout<<1<<endl;
            else
            {
                if(cnt==1)
                {
                    cout<<1<<endl;
                }
                if(cnt==2)
                {
                    cout<<2<<endl;
                }
                if(cnt==3)
                {
                    int tmp1=cal(a[1],a[2]);
                    int tmp2=cal(a[1],a[3]);
                    int tmp3=cal(a[2],a[3]);
                    if(tmp1<a[3]||tmp2<a[3]||tmp3<a[3])
                    {
                        cout<<2<<endl;
                    }
                    else  cout<<3<<endl;
                }
                if(cnt==4)
                {
                    cout<<4<<endl;
                }
                else cout<<cnt<<endl;
            }
        }

    }

    return 0;
}
