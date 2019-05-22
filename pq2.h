#include<iostream>//���ȶ������Ա�����ʵ�� 
using namespace std;
template<class T>
class pq2 
{
public:
	pq2()//��������󳤶� 
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
		if(empty()||!cmp(head->element,element))//������ǰ�� 
		{
			head=new node(head,element);
			num++;
			return;
		}
		num++; 
		node *p=new node(NULL,element);
		node *q=head;
		while(q)//Ѱ�Ҳ���λ�� 
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
	struct node//����ڵ� 
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
