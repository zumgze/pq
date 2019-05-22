#include<iostream>//优先队列线性表数组实现 
using namespace std;
template<class T>
class pq
{
public:
	pq(int n)
	{
		a=new T[n];
		max=n+1;//区别全空的情况，多申请一个 
		l=0;
		r=0;
	}
	bool empty(){return l==r;}
	int size(){return (r-l+max+1)%(max+1);}
	void pop()
	{
		if(empty())
		{
			cerr<<"error0"<<endl;
			return;
		}
		l=(l+1)%max;
	}
	const T& top()
	{
		if(empty())
		{
			cerr<<"error0"<<endl;
			return a[0];
		}
		return a[l];
	}
	void push(const T& element,bool(*cmp)(T,T))
	{
		if(size()==max-1)
		{
			cerr<<"error1"<<endl;
			return;
		}
		a[r]=element;
		r=(r+1)%max;
		for(int i=(r+max-1)%max;i!=l;i=(i+max-1)%max)//向前交换 
		{
			int ii=(i+max-1)%max;//ii是i的上一个
			if(cmp(a[ii],a[i]))break;
			else swap(a[ii],a[i]);
		}
	}
private:
	T* a;
	int l,r;
	int max;
};
