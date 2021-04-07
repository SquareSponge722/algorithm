#include<bits/stdc++.h>
using namespace std;
int n;
int r[100000];
int wh()
{
	int cnt=0;
	for(int i=0;i<n;i++)
	    if(r[i]>0) cnt=1;
	return cnt;
}
int deep()
{
	int max=-1;
	for(int i=0;i<n;i++)
	    if(max<r[i]) max=r[i];
	return max;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int dpt;
	int cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	    cin>>r[i];
	bool ok=0;
	while(wh())
	{
		dpt=deep();
		for(int i=0;i<n;i++)
		{
			if(r[i]==dpt)
			{
				r[i]--;
				if(ok==0) cnt++;
				ok=1;
				if(r[i+1]!=dpt) ok=0;
			}
		}
	}
	cout<<cnt;
	return 0;
}

