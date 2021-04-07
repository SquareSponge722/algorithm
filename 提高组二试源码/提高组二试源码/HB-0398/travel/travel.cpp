#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int flag0=1,iu[2],opo=0;
int main()
{
	fstream input,output;
	input.open("travel.in",ios::in);
	int tcity,m;//城市总数和剩下输入数据组数 
	input>>tcity>>m;
	bool book[tcity];
	for(int a=1;a<=tcity;a++)
	book[a]=true;
	//cout<<tcity<<" "<<m<<endl;
	vector<int> city1,city2;
	for(int a=0;a<m;a++)//读入数据 
	{
		int temp1,temp2;
		input>>temp1>>temp2;
		city1.push_back(temp1);
		city2.push_back(temp2);
	}
	//cout<<city1[0]<<endl;
	input.close();
	vector<int> temp1,temp2;//新建两个vec来查找字典序最小的开头 
	temp1=city1;
	temp2=city2;
	sort(temp1.begin(),temp1.end());
	sort(temp2.begin(),temp2.end());
	int First_Node,wayto[m],pointto=-1;
	if(temp1[0]<=temp2[0]){
	First_Node=temp1[0];
		for(int a=0;a<m;a++)
	{
		if(city1[a]==First_Node){
		pointto++;
		wayto[pointto]=city2[a];
		}
   }
}
	else if(temp1[0]>temp2[0]){
	First_Node=temp2[0];
		for(int a=0;a<m;a++)
	{
		if(city2[a]==First_Node){
		pointto++;
		wayto[pointto]=city1[a];
		}
    }
}
output.open("travel.out",ios::out);
output<<First_Node<<" ";
int com0;
for(int a=0;a<m;a++){
int temp=0,inf=999999;
for(;temp<=pointto;temp++){
if((com0=wayto[temp])<inf)
inf=com0;}
}
book[com0]=false;
book[First_Node]=false;
flag0++;
output<<com0<<" ";
int com1,temm;
loop:
com1=9999999;
for(int a=0;a<m;a++)
{
	if(city1[a]==com0&&book[city2[a]]){//防止又跑回起点 同时寻找下一个最小的位置 
	if(city2[a]<com1)
	com1=city2[a];}
	else if(city2[a]==com0&&book[city1[a]]){
	if(city1[a]<com1)
	com1=city1[a];}
}
if(com1==9999999)
{
	com0=com0-1;
goto loop;
}
flag0++;
book[com1]=false;
temm=com1;
com0=com1;
output<<com1<<" ";
if(flag0==(tcity-2))
{
for(int a=1;a<=tcity;a++)
{
	if(book[a]==true){
	iu[opo]=a;
	opo++;}
}
if(iu[0]>iu[1])
output<<iu[1]<<" "<<iu[0];
else
output<<iu[0]<<" "<<iu[1];
output<<endl;
output.close();
return 0;
}
goto loop;
}


