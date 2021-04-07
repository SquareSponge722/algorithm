#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream fin;ofstream fout;
const int _=100000+7;
int n,m,p[_],a,aa,b,bb,f[_][2];
string st;
inline int sa(int A,int B){return A<B?A:B;}
void DP()
{
	f[1][1]=p[1];f[0][0]=0;
	for(register int i=2;i<=n;i++)
	{
		f[i][0]=sa(f[i-2][0]+p[i],f[i-1][1]);
		f[i][1]=sa(f[i-1][0]+p[i],f[i-1][1]);
	}
}
int main()
{
	fin.open("defense.in");
	fout.open("defense.out");
	fin>>n>>m;fin>>st;
	for(register int i=1;i<=n;i++)
		fin>>p[i];
	for(register int i=1;i<n;i++)
		fin>>a>>b;
	for(register int i=1;i<=m;i++)
	{
		memset(f,0x3f,sizeof(f));
		fin>>a>>aa>>b>>bb;
		if(aa==0&&bb==0&&(a-b==1||a-b==-1))
		{
			fout<<"-1";
			continue;
		}
		DP();
		fout<<f[n];
	}
	fin.close();
	fout.close();
	return 0;
}
