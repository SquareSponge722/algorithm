///road
#include<iostream>
#include<cstdio>
using namespace std;
const int mn=100010;
int n;
int a[mn];
int day=0;
void work(int l,int r)
{
    if(l>r)
        return;
    int mina=200000;
    int p=-1;
    for(int i=l; i<=r; i++)
        if(mina>a[i])
        {
            mina=a[i];
            p=i;
        }
    day+=mina;
    for(int i=l; i<=r; i++)
        a[i]-=mina;
    work(l,p-1);
    work(p+1,r);
    return ;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    //cout<<"n="<<n<<endl;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    work(1,n);
    cout<<day;
    return 0;
}
