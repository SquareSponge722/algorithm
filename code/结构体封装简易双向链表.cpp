/*
by SS 2020/12/19 10:26
���׷�װ����
for Louise Francoise le Blanc de la valliere
*/
#include <cstdio>
#include <cstdlib>
#define ChainListElement struct nod *
using namespace std;
struct List{

	struct nod{ //��������Ԫ��
		int val; //Ԫ�ش��������
		ChainListElement pre_element; //ָ����һ��Ԫ�ص�ַ
		ChainListElement next_element; //ָ����һ��Ԫ�ص�ַ
	};

	ChainListElement head; //��ͷ
	ChainListElement tail; //��β
	ChainListElement currentElement; //α������
	int length; //��¼����Ԫ�ظ���

	List(){  //���캯�����ڴ�������ʱΪ��ͷ��β����ռ�
		head = (ChainListElement) malloc(sizeof(ChainListElement));
		tail = (ChainListElement) malloc(sizeof(ChainListElement));
		head->pre_element = NULL;
		head->next_element = tail;
		tail->pre_element = head;
		tail->next_element = NULL;
		currentElement = head; //��α������ָ���ͷ
	}

	void push_back(int v){ //��������β������һ��Ԫ��
		ChainListElement previousElement = tail->pre_element;  //����ǰ ��βǰ���һ��Ԫ��
		ChainListElement insertElement = (ChainListElement) malloc(sizeof(ChainListElement)); //��Ҫ�����Ԫ��
		
		insertElement->val = v;
		insertElement->pre_element = previousElement;  
		previousElement->next_element = insertElement;
		insertElement->next_element = tail;
		tail->pre_element = insertElement; //����Ԫ��pre nextָ���ַ����ɲ������

		length++;
	}

	void push(int v){ //��������ͷ������һ��Ԫ��
		insert(v,0);
	}

	bool insert(int v,int pos){ //��ָ��λ�ò���һ��Ԫ�� //ע�⣺�˴����������׸�Ԫ��λ��Ϊ0
		if(pos<0 || pos>length) return false; //�Ƿ�λ�� ����false ��ֹ����

		ChainListElement tempElement = head;
		while(pos--) tempElement = tempElement->next_element; //�ҵ�����λ��Ԫ��ǰһ��Ԫ��
		ChainListElement nextElement = tempElement->next_element;  //����λ��Ԫ��

		ChainListElement insertElement = (ChainListElement) malloc(sizeof(ChainListElement)); //��Ҫ�����Ԫ��
		insertElement->val = v;
		insertElement->pre_element = tempElement;
		tempElement->next_element = insertElement;
		insertElement->next_element = nextElement;
		nextElement->pre_element = insertElement;  //����Ԫ��pre nextָ���ַ����ɲ������

		length++;
		return true;  //�����ɹ� ����true
	}

	void pop_back(){ //ɾ�����������һ��Ԫ��
		if(!length) return ;

		ChainListElement deleteElement = tail->pre_element;  //��Ҫɾ����Ԫ��
		ChainListElement previousElement = deleteElement->pre_element;
		previousElement->next_element = tail;
		tail->pre_element = previousElement;

		free(deleteElement); //�ͷ�ɾ��Ԫ�ص��ڴ� //VS code�ᱨ�쳣��ԭ��δ֪�����������ȷִ��
	}

	void pop(){ //ɾ���������׸�Ԫ��
		if(!length) return ;
		deleteElement(0);
	}

	bool deleteElement(int pos){ //ɾ��������ָ��λ�õ�Ԫ��
		if(pos<0 || pos>= length) return false;

		ChainListElement deleteElement = head->next_element;
		while(pos--) deleteElement = deleteElement->next_element;
		ChainListElement nextElement = deleteElement->next_element;
		ChainListElement previousElement = deleteElement->pre_element;

		previousElement->next_element = nextElement;
		nextElement->pre_element = previousElement;

		free(deleteElement);
		return true;
	}

	ChainListElement getIterator(){ //��ȡα������
		return currentElement;
	}

	ChainListElement moveToNext(){ //��α������������һ��Ԫ�ز�����α������
		if(!currentElement->next_element) return currentElement; //α������ָ���β��ֱ�ӷ���
		return currentElement = currentElement->next_element;
	}

	ChainListElement moveToPrev(){ //��α������������һ��Ԫ�ز�����α������
		if(!currentElement->pre_element) return currentElement; //α������ָ���ͷ��ֱ�ӷ���
		return currentElement = currentElement->pre_element;
	}

	ChainListElement moveToHead(){ //��α������������ͷ������α������
		while(currentElement->pre_element) currentElement = currentElement->pre_element;
		return currentElement;
	}

	ChainListElement moveToTail(){ //��α������������β������α������
		while(currentElement->next_element) currentElement = currentElement->next_element;
		return currentElement;
	}

	bool hasNext(){ //α�������Ƿ�����һ��Ԫ��(Ԫ�ز�������ͷ��β)
		if(currentElement->next_element ? false : true) return false;
		return currentElement->next_element->next_element ? true : false;
	}

	int size(){ //����������Ԫ�ظ���
		return length;
	}
};
void initList();
void showList(bool);
void deleteEle();
void insertEle();
List myList; //����������һ�����������캯���ڴ˴�ִ��
int main(){
	
	char op;
	while(~scanf("%c",&op)){
		if(op=='\n' || op=='\r') continue;
		switch(op){
			case 'B':
			initList(); //������������
			break;
			case 'S':
			showList(false); //������
			showList(true); //������
			break;
			case 'D':
			deleteEle(); //ɾ��Ԫ��
			break;
			case 'I':
			insertEle(); //����Ԫ��
			break;
			default:
			printf("please input legal command BSDI\n");
			break;
		}
	}
	return 0;
} 
void initList(){
	int n,k;

	scanf("%d",&n); //�������Ԫ�ظ���
	while(n--){
		scanf("%d",&k);
		myList.push_back(k); //�����ݴ�β����������
	}
}
void showList(bool is_reverse){
	if(is_reverse){ //������
		myList.moveToTail();
		while(myList.moveToPrev()->pre_element){
			printf("%d ",myList.getIterator()->val);
		}
	}else{ //������
		myList.moveToHead();
		while(myList.moveToNext()->next_element){
			printf("%d ",myList.getIterator()->val);
		}
	}
	printf("\n");
}
void deleteEle(){
	int n;

	scanf("%d",&n);  //����ɾ��Ԫ��λ��
	if(!myList.deleteElement(n))
		printf("illgal command!\n"); //�Ƿ�λ��
}
void insertEle(){
	int n,k;

	scanf("%d %d",&n,&k); //�������λ�ú�����
	if(!myList.insert(k,n))
		printf("illgal command!\n"); //�Ƿ�λ��
}
