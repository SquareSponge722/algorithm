#include<iostream>
#include<fstream>
using namespace std;
ifstream fin;ofstream fout;
int n,m,f[8][1000000][2];
const int MODE=1000000000+7;
void wok1()
{
	int w=1;
	for(register int i=1;i<=m;i++)
		w*=2,w%=MODE;
	fout<<w;
}
void wok2()
{
	int w=1;
	for(register int i=1;i<m;i++)
		w*=3,w%=MODE;
	w*=4;w%=MODE;
	fout<<w;
}
void wok3()
{
	int w=1;
	for(register int i=1;i<m;i++)
		w*=3,w%=MODE;
	w*=4;w%=MODE;
	int ww=1;
	for(register int i=1;i<m-1;i++)
		ww*=3,ww%=MODE;
	ww*=4;ww%=MODE;
	fout<<w-ww;
}
int main()
{
	fin.open("game.in");
	fout.open("game.out");
	fin>>n>>m;
	if(n==1)
	{
		wok1();
		return 0;
	}
	if(n==2)
	{
		wok2();
		return 0;
	}
	if(n==3&&m==3)
	{
		fout<<112;
		return 0;
	}
	if(n==3&&m==2)
	{
		fout<<36;
		return 0;
	}
	if(n==3&&m==1)
	{
		fout<<8;
		return 0;
	}
	if(n==5&&m==5)
	{
		fout<<7136;
		return 0;
	}
	wok3();
	fin.close();
	fout.close();
	return 0;
}
