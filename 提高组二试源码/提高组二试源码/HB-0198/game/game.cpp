#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<string>
#include<vector>
#define MO 1000000007
using namespace std;
typedef pair<int,int> pii;

const int mx[2]={0,1},my[2]={1,0};

int m,n;
int ans;
int lu[1000][1000];
int poi;
vector<long long>ste;


void build1()
{
	poi=0;
	string s;
	for(int i=0;i<n;i++) s+="0";
	for(int i=0;i<m;i++) s+="1";
	for(int i=0;i<s.size();i++)
	{
		lu[0][i]=s[i]-'0';
	}
	poi++;
	while(next_permutation(s.begin(),s.end()))
	{
		for(int i=0;i<s.size();i++)
		{
			lu[poi][i]=s[i]-'0';
		}
		poi++;
	}
	poi--;
	return;
}

void build2()
{
	long long a=0;
	while(a <= (1<<n)-1)
	{
		ste.push_back(a);
		a++;
	}
}

int main()
{
	cin>>n>>m;
	build1();
	build2();
	for(int i=0;i<ste.size();i++)
	{
		cout<<ste[i]<<endl;
	}
//	dfs();
}
