#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n;
    int d[100001]={0};
    int a,b;
    int day=0;
    cin>>n;
    for(a=1;a<=n;a++)
        cin>>d[a];
    for(a=1;a<=n;a++)
    {
       while(d[a]!=0)
        {
            day++;
            for(b=a;b<=n;b++)
            {
                if(d[b]!=0)
                    d[b]--;
				else
					break;
            }
        }
    }
    cout<<day;
    return 0;
}
