///money
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mn=110;
int T;
int n;
int a[mn];
bool exist[mn];
int m;
int fir,sec;
int cal(int a,int b)///X
{
    int c;
    c=a*b-a-b;
    return c;
}
bool cal2(int pos,int x)
{
    if(x==fir||x==sec)
        return 0;
    for(int i=0; i*fir<=x; i++)
        for(int j=0; j*sec<=x; j++)
            if(i*fir+j*sec==x)
                return 1;
    return 0;
}
void init()
{
    memset(a,0,sizeof(a));
    memset(exist,1,sizeof(exist));///!!=1
    cin>>n;
    m=n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    /*
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    */
}
void work()
{
    if(a[1]==1)
    {
        m=1;
    }
    else
    {
        fir=a[1];
        sec=25100;
        for(int i=2; i<=n; i++)
            if(a[i]%a[1]==0)
            {
                exist[i]=0;
                m--;
            }
            else sec=min(a[i],sec);
        //cout<<"___________________"<<endl;
        //cout<<"m="<<m<<endl;
        //cout<<"first="<<fir<<endl;
        //cout<<"second="<<sec<<endl;
        int maxa=cal(fir,sec);
        //cout<<"maxa="<<maxa<<endl;
        //cout<<"exist[4]="<<exist[4]<<endl;
        for(int i=1; i<=n; i++)
            if(a[i]>maxa&&exist[i])
            {
                exist[i]=0;
                m--;
            }
            else if(a[i]<=maxa&&exist[i])

                if(cal2(i,a[i]))
                {
                    exist[i]=0;
                    m--;
                }
    }
    cout<<m<<endl;
    //cout<<"exist[5]"<<exist[5]<<endl;
}
void a1()
{
    cout<<"1"<<endl;
}
void a2()
{
    if(a[2]%a[1]==0)
        m=1;
    cout<<m<<endl;
}
void a3()
{
    for(int i=2; i<=3; i++)
        for(int j=1; j<=i-1; j++)
            if(a[i]%a[j]==0)
                exist[i]=0;
    bool flag=1;
    for(int i=0; i*a[1]<=a[3]; i++)
        for(int j=0; j*a[2]<=a[3]; j++)
            if(a[3]==a[1]*i+a[2]*j)
            {
                flag=0;
                break;
            }
    if(flag==0)
        exist[3]=0;
    m=n;
    for(int i=1; i<=3; i++)
        if(exist[i]==0)
            m--;
    cout<<m<<endl;
}
void a4()
{
    for(int i=2; i<=4; i++)
        for(int j=1; j<=i-1; j++)
            if(a[i]%a[j]==0)
                exist[i]=0;


    bool flag=1;
    for(int i=0; i*a[1]<=a[3]; i++)
        for(int j=0; j*a[2]<=a[3]; j++)
            if(a[3]==a[1]*i+a[2]*j)
            {
                flag=0;
                break;
            }
    if(flag==0)
        exist[3]=0;


    flag=1;
    for(int i=0; i*a[1]<=a[4]; i++)
        for(int j=0; j*a[2]<=a[4]; j++)
            for(int k=0; k*a[3]<=a[4]; k++)
                if(a[4]==a[1]*i+a[2]*j+k*a[3])
                {
                    flag=0;
                    break;
                }
    if(flag==0)
        exist[4]=0;

    m=n;
    for(int i=1; i<=4; i++)
        if(exist[i]==0)
            m--;
    cout<<m<<endl;
}
void a5()
{
    for(int i=2; i<=5; i++)
        for(int j=1; j<=i-1; j++)
            if(a[i]%a[j]==0)
                exist[i]=0;


    bool flag=1;
    for(int i=0; i*a[1]<=a[3]; i++)
        for(int j=0; j*a[2]<=a[3]; j++)
            if(a[3]==a[1]*i+a[2]*j)
            {
                flag=0;
                break;
            }
    if(flag==0)
        exist[3]=0;


    flag=1;
    for(int i=0; i*a[1]<=a[4]; i++)
        for(int j=0; j*a[2]<=a[4]; j++)
            for(int k=0; k*a[3]<=a[4]; k++)
                if(a[4]==a[1]*i+a[2]*j+k*a[3])
                {
                    flag=0;
                    break;
                }
    if(flag==0)
        exist[4]=0;


    flag=1;
    for(int i=0; i*a[1]<=a[4]; i++)
        for(int j=0; j*a[2]<=a[4]; j++)
            for(int k=0; k*a[3]<=a[4]; k++)
                for(int l=0; l*a[4]<=a[5]; l++)
                    if(a[5]==a[1]*i+a[2]*j+k*a[3]+l*a[4])
                    {
                        flag=0;
                        break;
                    }
    if(flag==0)
        exist[5]=0;

    m=n;
    for(int i=1; i<=4; i++)
        if(exist[i]==0)
            m--;
    cout<<m<<endl;
}
void work2()
{
    if(n==1)
        a1();
    if(n==2)
        a2();
    if(n==3)
        a3();
    if(n==4)
        a4();
    if(n==5)
        a5();
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>T;
    while(T--)
    {
        init();
        if(n>=6)
            work();
        else
            work2();
    }
    return 0;
}

