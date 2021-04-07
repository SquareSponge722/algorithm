#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[102],sum=0;
bool b[25002]={0};
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
	    queue<int> que;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
		     cin>>a[i];if(b[a[i]]==1) continue;
		     b[a[i]]=1;sum++;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			que.push(a[i]);
		}
		int p=0;
		while(que.size()>0)
		{
			for(p=1;p<=n;p++)
			{
				if(b[que.front()+a[p]]==1){
					sum--;
					b[que.front()+a[p]]=0;
				}
				if(que.front()+a[p]<=a[n]) que.push(que.front()+a[p]);
			}
			que.pop();
		}
		cout<<sum;
	}
	return 0;
}
/*
1
4
3 19 10 6


1
3
10 100 1000
*/
