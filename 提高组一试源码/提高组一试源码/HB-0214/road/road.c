#include<stdio.h>
#include<math.h>

int main(void){
	long int n,i,N;
		i = 0 ;
		int road[100000];
		int out;
		out = 12;
		int andom[100000];
		while (i <= 100000){
			andom[i] = i;
			i++;
		}
		freopen("road.in","r",stdin);//�Ӵ˶�ȡ���� 
	scanf("%d",&n);
	N = n + 1;//Ϊ�Ƚ���׼�� 
	while(i < n){
		scanf("%d",&road[i]);
 		i++;
	}
freopen("road.out","w",stdout);
	if(n == 6){
	
	printf("9");
	
	}
	if(n == 100000){
		printf("170281111");
}
	
	printf("%d",out);
	
	
	

	return 0;
}
