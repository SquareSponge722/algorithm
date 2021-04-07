/*
by SS 2020/12/19 10:26
简易封装链表
for Louise Francoise le Blanc de la valliere
*/
#include <cstdio>
#include <cstdlib>
#define ChainListElement struct nod *
using namespace std;
struct List{

	struct nod{ //链表基本元素
		int val; //元素储存的数据
		ChainListElement pre_element; //指向上一个元素地址
		ChainListElement next_element; //指向下一个元素地址
	};

	ChainListElement head; //表头
	ChainListElement tail; //表尾
	ChainListElement currentElement; //伪迭代器
	int length; //记录表中元素个数

	List(){  //构造函数，在创建链表时为表头表尾分配空间
		head = (ChainListElement) malloc(sizeof(ChainListElement));
		tail = (ChainListElement) malloc(sizeof(ChainListElement));
		head->pre_element = NULL;
		head->next_element = tail;
		tail->pre_element = head;
		tail->next_element = NULL;
		currentElement = head; //将伪迭代器指向表头
	}

	void push_back(int v){ //从链表的尾部插入一个元素
		ChainListElement previousElement = tail->pre_element;  //插入前 表尾前面的一个元素
		ChainListElement insertElement = (ChainListElement) malloc(sizeof(ChainListElement)); //将要插入的元素
		
		insertElement->val = v;
		insertElement->pre_element = previousElement;  
		previousElement->next_element = insertElement;
		insertElement->next_element = tail;
		tail->pre_element = insertElement; //更改元素pre next指向地址，完成插入操作

		length++;
	}

	void push(int v){ //从链表的头部插入一个元素
		insert(v,0);
	}

	bool insert(int v,int pos){ //从指定位置插入一个元素 //注意：此处定义链表首个元素位置为0
		if(pos<0 || pos>length) return false; //非法位置 返回false 终止操作

		ChainListElement tempElement = head;
		while(pos--) tempElement = tempElement->next_element; //找到插入位置元素前一个元素
		ChainListElement nextElement = tempElement->next_element;  //插入位置元素

		ChainListElement insertElement = (ChainListElement) malloc(sizeof(ChainListElement)); //将要插入的元素
		insertElement->val = v;
		insertElement->pre_element = tempElement;
		tempElement->next_element = insertElement;
		insertElement->next_element = nextElement;
		nextElement->pre_element = insertElement;  //更改元素pre next指向地址，完成插入操作

		length++;
		return true;  //操作成功 返回true
	}

	void pop_back(){ //删除链表中最后一个元素
		if(!length) return ;

		ChainListElement deleteElement = tail->pre_element;  //将要删除的元素
		ChainListElement previousElement = deleteElement->pre_element;
		previousElement->next_element = tail;
		tail->pre_element = previousElement;

		free(deleteElement); //释放删除元素的内存 //VS code会报异常，原因未知，但程序可正确执行
	}

	void pop(){ //删除链表中首个元素
		if(!length) return ;
		deleteElement(0);
	}

	bool deleteElement(int pos){ //删除链表中指定位置的元素
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

	ChainListElement getIterator(){ //获取伪迭代器
		return currentElement;
	}

	ChainListElement moveToNext(){ //将伪迭代器移向下一个元素并返回伪迭代器
		if(!currentElement->next_element) return currentElement; //伪迭代器指向表尾，直接返回
		return currentElement = currentElement->next_element;
	}

	ChainListElement moveToPrev(){ //将伪迭代器移向上一个元素并返回伪迭代器
		if(!currentElement->pre_element) return currentElement; //伪迭代器指向表头，直接返回
		return currentElement = currentElement->pre_element;
	}

	ChainListElement moveToHead(){ //将伪迭代器移至表头并返回伪迭代器
		while(currentElement->pre_element) currentElement = currentElement->pre_element;
		return currentElement;
	}

	ChainListElement moveToTail(){ //将伪迭代器移至表尾并返回伪迭代器
		while(currentElement->next_element) currentElement = currentElement->next_element;
		return currentElement;
	}

	bool hasNext(){ //伪迭代器是否还有下一个元素(元素不包括表头表尾)
		if(currentElement->next_element ? false : true) return false;
		return currentElement->next_element->next_element ? true : false;
	}

	int size(){ //返回链表中元素个数
		return length;
	}
};
void initList();
void showList(bool);
void deleteEle();
void insertEle();
List myList; //声明并创建一个链表，构造函数在此处执行
int main(){
	
	char op;
	while(~scanf("%c",&op)){
		if(op=='\n' || op=='\r') continue;
		switch(op){
			case 'B':
			initList(); //向表中填充数据
			break;
			case 'S':
			showList(false); //正向打表
			showList(true); //逆向打表
			break;
			case 'D':
			deleteEle(); //删除元素
			break;
			case 'I':
			insertEle(); //插入元素
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

	scanf("%d",&n); //输入填充元素个数
	while(n--){
		scanf("%d",&k);
		myList.push_back(k); //将数据从尾部插入链表
	}
}
void showList(bool is_reverse){
	if(is_reverse){ //反向打表
		myList.moveToTail();
		while(myList.moveToPrev()->pre_element){
			printf("%d ",myList.getIterator()->val);
		}
	}else{ //正向打表
		myList.moveToHead();
		while(myList.moveToNext()->next_element){
			printf("%d ",myList.getIterator()->val);
		}
	}
	printf("\n");
}
void deleteEle(){
	int n;

	scanf("%d",&n);  //输入删除元素位置
	if(!myList.deleteElement(n))
		printf("illgal command!\n"); //非法位置
}
void insertEle(){
	int n,k;

	scanf("%d %d",&n,&k); //输入插入位置和数据
	if(!myList.insert(k,n))
		printf("illgal command!\n"); //非法位置
}
