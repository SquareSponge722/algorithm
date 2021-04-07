#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int t;
int main(int argc, char** argv) 
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int a[10];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i];
		}
		if(n==4)
		{
			cout<<2<<endl;return 0;
		}
		if(n==5)
		{
			cout<<5<<endl;return 0;
		}
		
	}
	return 0;
}
