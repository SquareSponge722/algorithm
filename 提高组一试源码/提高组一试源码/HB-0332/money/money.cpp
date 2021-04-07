#include <iostream>
#include <cmath>
using namespace std;


bool seach(int a,int b[])//分解质数 
{
	for(int i;i<a;i++)
	{
	for(int j,j<a;j++)	
	if(b[i]%j==0)
	{
		b=b/j;
		}	
	}
}


int main(int argc, char** argv) {
	
	int a;
	int b[];
	
	
	
	for(int i=0;i<a;i++)
	{
		cin<<b[i];
	}
	
	
	
	return 0;
}
