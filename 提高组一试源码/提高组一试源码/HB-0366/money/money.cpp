#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;
ifstream fin;ofstream fout;
const int _=100+7;
const int __=25000+7;
int T,n,ans,ctl,a[_];
bool keyoukewu[__];
int main()
{
	fin.open("money.in");
	fout.open("money.out");
	fin>>T;
	while(T--)
	{
		fin>>n;ans=0;memset(keyoukewu,0,sizeof(keyoukewu));
		for(register int i=1;i<=n;i++)
			fin>>a[i];
		sort(a+1,a+n+1);
		if(n==2)
		{
			if(a[2]%a[1]==0)
				fout<<1<<"\n";
			else
				fout<<2<<"\n";
			continue;
		}
		ctl=a[1]*a[2]-a[1]-a[2]+1;
		for(register int i=1;i<=n;i++)
			if(a[i]>=ctl)
				keyoukewu[a[i]]=true;
		for(register int i=1;i<n;i++)
			for(register int j=i+1;j<=n;j++)
				if(a[j]%a[i]==0)
					keyoukewu[a[j]]=true;
		for(register int i=1;i<=a[n];i++)
			if(keyoukewu[i])
				n--;
		fout<<((n-1)|1);
	}
	fin.close();
	fout.close();
	return 0;
}
/*
1
3
3 6 9
*/
