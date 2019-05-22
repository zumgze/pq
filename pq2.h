#include<iostream>//优先队列线性表链表实现 
using namespace std;
template<class T>
class pq2 
{
public:
	pq2()//链表不设最大长度 
	{
		head=NULL;
		num=0;
	}
	bool empty(){return num==0;}
	int size(){return num;}
	void pop()
	{
		if(empty())
		{
			cerr<<"error0"<<endl;
			return;
		}
		num--;
		node *p=head;
		head=head->next;
		delete p;
	}
	const T& top()
	{
		if(empty())
		{
			cerr<<"error0"<<endl;
			return head->element;
		}
		return head->element;
	}
	void push(const T& element,bool(*cmp)(T,T))
	{
		if(empty()||!cmp(head->element,element))//插在最前面 
		{
			head=new node(head,element);
			num++;
			return;
		}
		num++; 
		node *p=new node(NULL,element);
		node *q=head;
		while(q)//寻找插入位置 
		{
			if(cmp(q->element,element)&&((!q->next)||(!cmp(q->next->element,element))))
			{
				p->next=q->next;
				q->next=p;
				break;
			}
			q=q->next;
		}
		p=NULL;
		q=NULL;
	}
private:
	int num;
	struct node//链表节点 
	{
		node* next;
		T element;
		node(node* a,T b)
		{
			next=a;
			element=b;
		}
	}; 
	node* head;
};
