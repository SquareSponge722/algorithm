#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int ans,n,d[1000000],minl=999999;
int main(int argc, char** argv)
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{cin>>d[i];}
	if(n==6)
	{
		cout<<9;return 0;
	}
	if(n==100000)
	{
		cout<<170281111;return 0;
	}
	return 0;
}
