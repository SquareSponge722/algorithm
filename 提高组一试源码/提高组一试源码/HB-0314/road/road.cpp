#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int d[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,max=0,ans;
	cin>>n;
	for (int i=0;i<n;i++) cin>>d[i];
	for (int i=0;i<n;i++){
		if (max<d[i])
		max = d[i];
		max--;
		if (d[i]=0) break;
		else d[i]--;
	for (ans=1;max;ans++){
		int count = 0;
		for(int i=1;i<=n;i++)
		   if(count) continue;
		   else break;
	    }
	}
    ans-=max;
	cout<<ans<<endl;
    return 0;
}

