#include <iostream>
#include <unordered_map>
using namespace std;



class queue
{
	public:
		queue(int arrayLength = 10)
		{
			que= new int[arrayLength];
			this->arrayLength = arrayLength;
			queueBack=-1;
			queueFront=-1;	
			count=0;
		}
		~queue()
		{ delete []que;}
		bool empyt();
		int size();
		int front();
		int back();
		void pop();
		void push(const int & theElement);
		int count;
	private:
		int queueFront;  //����Ԫ�ر��-1 
		int queueBack;   //��βԪ�� 
		int* que;
		int arrayLength;   //�������� 
		
		
};

bool queue::empyt()   
{
	if (queueFront == queueBack) return true;
        else return false;	
}

int queue::size()
{
	if (queueFront==queueBack) return -1;
	return (queueBack-queueFront);
}

int queue::front()   //���ض���Ԫ�� 
{
	return que[(queueFront +1) % arrayLength];
}

int queue::back()   //���ض�βԪ�� 
{
	return que[queueBack];
}

void queue::pop()   //���Ӳ��� 
{
	queueFront = (queueFront +1)%arrayLength;
	count--;
}

void queue::push(const  int & theElement)   //��Ӳ��� 
{
	count++;
	
   
	queueBack =(queueBack +1)% arrayLength;
    que[queueBack] = theElement;
    
}



int card(int n)     //����ѭ��ʵ�ֿ�Ƭ��Ϸ��  
{
	
	queue s(n);
       for(int i=0;i<n;i++)
       {
	       s.push(i+1);
       }
    while(s.count!=1)
    {
	    s.pop();            //ɾ������ Ԫ�� 
	    int a=s.front();   //�Ѷ���Ԫ�ز����β 
	    s.push(a);
	    s.pop();
    }
    
    return s.back();


}




int main()
{
	int n;
	cin>>n;
	int t;
	t=card(n);
	cout<<t<<endl;

}
