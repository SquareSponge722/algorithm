#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int T,a[101]=0;
    cin>>T;
    for(int z=0;z<T;z++)
    {
    	int n;
    	cin>>n;
    	int ans=n;
    	for(int i=0;i<n;i++)
    		scanf("%d",&a[i]);
    	for(int i=0;i<n;i++)
    		for(int j=i+1;j<n;j++)
    			if((a[j]%a[i])==0)
    				ans--;
    	cout<<ans<<endl;
	}
    return 0;
}

