#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
typedef  long long ll;
const int maxn=100001;
int n;
int d[maxn];
ll sum;
int dmax;

ll getnum()
{
    int ind=1;
    int num=1;
    for(int i=1; i<=n; i++)
    {
        if(d[i]>0)
        {
            ind=1;
        }
        else
        {
            if(ind)
            {
                ind=0;
                num++;
            }
        }
    }
    if(d[n]>0&&d[1]<=0) return num-1;
    if(d[n]<=0&&d[1]<=0) return num-2;
    return num;
}


void dig()
{
    for(int i=1; i<=n; i++)
    {
        d[i]--;
    }
}
void print()
{
    for(int i=1; i<=n; i++)
    {
        cout<<d[i]<<' ';
    }
    cout<<"sum: "<<sum<<endl;
}

int main(void)
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>d[i];
        if(i==1) dmax=d[i];
        else dmax=max(dmax,d[i]);
    }
    while(dmax--)
    {
	    sum+=getnum();
        dig();
    }

    cout << sum;
    return 0;
}
