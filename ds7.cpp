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
		int queueFront;  //队首元素标号-1 
		int queueBack;   //队尾元素 
		int* que;
		int arrayLength;   //数组容量 
		
		
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

int queue::front()   //返回队首元素 
{
	return que[(queueFront +1) % arrayLength];
}

int queue::back()   //返回队尾元素 
{
	return que[queueBack];
}

void queue::pop()   //出队操作 
{
	queueFront = (queueFront +1)%arrayLength;
	count--;
}

void queue::push(const  int & theElement)   //入队操作 
{
	count++;
	
   
	queueBack =(queueBack +1)% arrayLength;
    que[queueBack] = theElement;
    
}



int card(int n)     //进行循环实现卡片游戏。  
{
	
	queue s(n);
       for(int i=0;i<n;i++)
       {
	       s.push(i+1);
       }
    while(s.count!=1)
    {
	    s.pop();            //删除队首 元素 
	    int a=s.front();   //把队首元素插入队尾 
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
