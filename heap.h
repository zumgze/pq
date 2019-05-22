#include<iostream>//���ȶ��ж�ʵ�� 
using namespace std;
template<class T>
class heap
{
public:
	heap(int n)
	{
		a=new T[n];
		max=n;
		num=0;
	}
	bool empty(){return num==0;}
	int size(){return num;}
	void pop(bool(*cmp)(T,T))
	{
		if(empty())
		{
			cerr<<"error0"<<endl;
			return;
		}
		num--;
		a[0]=a[num];
		int location=0;
		while(true)//ɾ�����ڵ㣬�����һ���ڵ�����ڸ��ڵ㣬���½��� 
		{
			if(location*2+2<num)
			{
				if(cmp(a[location*2+1],a[location])&&cmp(a[location*2+1],a[location*2+2]))//�����ӽ��� 
				{
					T help;
					help=a[location];
					a[location]=a[location*2+1];
					a[location*2+1]=help;
					location=location*2+1;
					continue;
				}
				else if(cmp(a[location*2+2],a[location]))//���Һ��ӽ��� 
				{
					T help;
					help=a[location];
					a[location]=a[location*2+2];
					a[location*2+2]=help;
					location=location*2+2;
					continue;
				}
				break;
			}
			else if((location*2+1<num)&&(cmp(a[location*2+1],a[location])))//���ֻ������ 
			{
				T help;
				help=a[location];
				a[location]=a[location*2+1];
				a[location*2+1]=help;
				location=location*2+1;
				continue;
			}
			break;
		}
	}
	const T& top()
	{
		if(empty())
		{
			cerr<<"error0"<<endl;
			return a[0];
		}
		return a[0];
	}
	void push(const T& element,bool(*cmp)(T,T))
	{
		if(num==max)
		{
			cerr<<"error1"<<endl;
			return;
		}
		a[num]=element;
		int location=num;
		num++;
		while(location>0)//����������Ͻ��� 
		{
			if(cmp(a[location],a[(location-1)/2]))
			{
				T help;
				help=a[location];
				a[location]=a[(location-1)/2];
				a[(location-1)/2]=help;
				location=(location-1)/2;
				continue;
			}
			break;
		}
	}
private:
	T* a;
	int num;
	int max;
};
