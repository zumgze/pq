#include<iostream>//优先队列高度优先左高树实现
using namespace std;
template<class T>
class hblt
{
public:
	hblt()
	{
		root=NULL;
		num=0;
	}
	bool empty(){return root==NULL;}
	int size(){return num;}
	void pop(bool(*cmp)(T,T))
	{
		if(empty())
		{
			cerr<<"error0"<<endl;
			return;
		}
		num--;
		node *left=root->left;
		node *right=root->right;
		root=left;
		meld(root,right,cmp);
	}
	const T& top()
	{
		if(empty())
		{
			cerr<<"error0"<<endl;
			return root->element;;
		}
		return root->element;
	}
	void push(const T& element,bool(*cmp)(T,T))
	{
		num++;
		node* q=new node(element);
		meld(root,q,cmp);
	}
private:
	int num;
	struct node
	{
		node* left;
		node* right;
		int height;
		T element;
		node(T a)//树节点 
		{
			element=a;
			left=NULL;
			right=NULL;
			height=1;
		}
	};
	void meld(node* &x,node* &y,bool(*cmp)(T,T))
	{
		if(!y)return;
		else if(!x)
		{
			x=y;
			return;
		}
		if(cmp(y->element,x->element))//确定根节点 
		{
			node *help;
			help=x;
			x=y;
			y=help;
		}
		meld(x->right,y,cmp);
		if(!x->left)
		{
			x->left=x->right;
			x->right=NULL;
			x->height=1;
		}
		else
		{
			if(x->left->height<x->right->height)//根的左右子树交换 
			{
				node *help;
				help=x->right;
				x->right=x->left;
				x->left=help;
			}
			x->height=x->right->height+1;
		}
	}
	node *root;
};
