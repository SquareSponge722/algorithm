#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

signed main()
{
//    freopen ("road.in","r",stdin);
//    freopen ("road.out","w",stdout);
    int n,a[100010];
    int flag = 0,sig,ans = 0,cm = 0;
    scanf ( "%d",&n );
    for ( register int i = 0 ; i < n ;  ++ i )
        scanf ( "%d",a[i] );
    while ( cm != n )
    {
        int cm = 0;
        for ( register int i = 1 ; i < n ; ++ i )
        {   
            if (a[i]==0)
                {
                    sig = i-1;
                    break;
                }
            else
                sig = n - 1;
        }
        for ( register int i = 0 ; i <= sig ; ++ i )
        {
            if (a[i-1]!=0) 
			a[i] --;
            else
            {
                ++ans;
                sig = i-1;
                break;
            }
        }
        ++ans;
        for ( register int  i = 0; i < n ; ++ i )
            if (a [i]== 0 ) cm ++;    
        }
    printf ("%d",ans);
    return 0 ;
}


