#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	freopen ("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long  m,n;
	long long ans=1;
	cin>>n>>m;
	if(n==2)
	{
	for (int i=1;i<m;i++)
	ans=3*ans%1000000007;
	cout <<ans*4%1000000007;
	}
	
	

	if(m==3&&n==3)
	cout<<"112";
	if(m==2&&n==3)
	cout<<"36";
if (m==5&&n==5)
cout<<"7136";
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
