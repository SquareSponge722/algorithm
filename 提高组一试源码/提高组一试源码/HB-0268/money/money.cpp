#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool dg(int x[101],int m,int p)
{
    int y;
    for(y=1;y<=m;y++)
    {
        if(p<x[y])
            return true;
        else if(p==x[y])
            return false;
        else
        {
            if(!dg(x,m,p-x[y]))
                return false;
        }
    }
	return true;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
    int t;
    int c;
	int n;
	int b,d;
	int a[101];
    cin>>t;
    for(c=1;c<=t;c++)
    {
		cin>>n;
        for(b=1;b<=n;b++)
            cin>>a[b];
        for(b=1;b<=n;b++)
        {
            for(d=1;d<n;d++)
            {
                if(a[d]==a[d+1])
                {
                    a[d+1]=a[n];
                    n--;
                }
                if(a[d]>a[d+1])
                {
                    int l;
                    l=a[d];
                    a[d]=a[d+1];
                    a[d+1]=l;
                }
            }
        }
        for(b=2;b<=n;b++)
        {
            if(!dg(a,b-1,a[b]))
            {
                for(d=b;d<n;d++)
                    a[d]=a[d+1];
                n--;
				b--;
            }
        }
        cout<<n<<endl;
    }
    return 0;
}
