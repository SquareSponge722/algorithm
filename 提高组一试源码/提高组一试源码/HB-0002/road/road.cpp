#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int hole[100005];
bool ok[100005];
int n, m;
int cnt=0;
long long big;
int fill(int strt, int end, int ttl)   //end should be the one BEFORE 0
{
	int minm=10000;
	int s, k, tmp;
	if (strt==end)
	{
		ttl+=hole[strt];
		hole[strt]=0;
		ok[strt]=true;
		return ttl;
	}
	//end note
	for (int i=strt; i<=end; i++)
	{
		tmp=hole[i];
		if (minm>tmp && ok[i]==false)
		{
			minm=tmp;   //find the shallowest hole to save time
		}
	}
	ttl+=minm;
	for (int j=strt; j<=end; j++)
	{
		hole[j]=hole[j]-minm;
		if (hole[j]==0)
		{
			ok[j]=true;  //filled holes
		}
	}
	// start looking for next round of holes
	s=strt;
	k=strt;
	while (s<=end && k<=end+1)
	{
		if (ok[k]==true)  //ending ok-s must be specified!!!!
		{
			if (s==k)
			{
				k++;
				s++;
				continue;
			}
			ttl=fill(s, k-1, ttl);
			s=k+1;	
		}
		if (ok[k]==false && k==end+1)	
		{
			ttl=fill(s, k-1, ttl);
		}
		k++;	
	}
	return ttl;
}
int main()
 {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>m;
		hole[i]=m;
		ok[i]=false;
	} //entering data
	cnt=fill(1, n, cnt);
	big=cnt;
	cout<<big;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

