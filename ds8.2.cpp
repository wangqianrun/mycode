#include <iostream>

using namespace std;

struct chainNode
{
	int next;
	int element;
};

template <class K,class E>
class hashTable
{
	public:
	hashTable(int theDivisor);
	int search(const K& theKey ) const;
    int find(const K& theKey) const;
	int insert(const K& theKey);
	void erase(const K theKey);
	
	chainNode* table;  //散列表 
	//hash<K> hash;             //把类型K映射到一个非整数
	int dSize;                //字典中数对个数 
	int divisor;              //散列函数除数
	 
	 
	
};


//构造函数
	template<class K,class E>
	hashTable<K,E>::hashTable(int theDivisor)
	{
		divisor = theDivisor;
		dSize = 0;
		//分配和初始化散列表函数
		table = new pair<const K,E>* [divisor];
		for (int i = 0;i<divisor;i++)
		   table[i] = NULL; 
	} 
	
	template<class K,class E>
	int hashTable<K,E>::search(const K& theKey) const
	{
		//搜索一个公开地址散列表，查找关键字为theKey的数对
		//如果匹配的数对存在，返回它的位置，否则，如果列表不满
		//则返回关键字为theKey的数对可以插入的位置
		
	   int i =(int) (theKey) % divisor;    //起始桶 
	   int j = i;                            //从起始桶开始 
	   do{
	   	if (table[j] == NULL || table[j]->first == theKey) return j;
	   	j = (j+1) % divisor;             //下一个桶 
	   }while(j != i);                    //是否返回到起始桶？ 
	   
	   return j; 
	}


template <class K,class E>
int hashTable<K,E>::find(const K& theKey) const
{
	//返回匹配数对的指针
	//如果匹配数对不存在，返回NULL 
	  //搜索散列表
	  int b = search(theKey);
	  
	  //判断table[b]是否是匹配数对
	  if (table[b] == NULL || table[b]->first != theKey)
	  return -1;    //没有找到
	  
	  return b;    //找到匹配数对 
}

template<class K,class E>
int hashTable<K,E>::insert(const K& theKey)
{
	//把数对thePair插入字典，若存在关键字相同的数对，则覆盖
	//若表满，则抛出异常
	//搜索散列表，查找匹配的数对
	int b = search(theKey);
	
	//检查匹配的数对是否存在
	if (table[b] == NULL)
	{
		//没有匹配的数对，而且表不满
		table[b]= new pair<const K,E> (theKey,b);
		dSize++; 
		return b;
		
		
	} 
	else 
	{
		//检查是否有重复的关键字数对或是否表满
		if (table[b]->first == theKey)
		{
			//有重复的关键字数对，修改table[b]->second
			 // table[b]->second = thePair.second;
			 cout<<"Existed"<<endl;
			 return -1;
			 
		} 
		else
		    return -1;;                           //表满 
	        
	}
}





template<class K,class E>
void hashTable<K,E>::erase(const K theKey)
{//表中元素的删除 create erase function
	int count=0;
	int b=search(theKey);//find the delete bucket number
	int a=b,n=b;//b为判断合适与否 a为对b中符合要求的前移  n用来定位 
				//if b cut the mustard then use a to put it forward ;else use n to diecison 
	pair<const K,E>* current=table[b];
	if(table[b]==NULL||table[b]->first!=theKey)
		cout<<"Not Found"<<endl;
	else
	{	delete current;//删除这个  delete current
		b=(b+1)%divisor;//b首先加一移位  
		while(table[b]!=NULL&&b!=n)//只有走到null或者这个表走完了方才停止 
		{
			int m=(int)table[b]->first%divisor;
 
			if((a<b&&m>b)||(a>b&&m>b&&a>=m)||(a<b&&b>m&&a>=m))  //the three logical relations will be explain in the essay
			{	
				table[a]=table[b];//exchange a and b
				a=b;
				count++;//exchange time
			}
			b=(b+1)%divisor;//b要一个个往后探查  let b to point next bucket
		}
		cout<<count<<endl;
	}
	table[a]=NULL;//对最后一个没有值的赋值为null； 
}



int main()
{
	
	int D,m;
	cin>>D>>m;
	hashTable<int,int> s(D);
	while(m--)
	{
		int opt,x;
		cin>>opt>>x;
		switch(opt)
		 {  case 0 :
		   	cout<<s.insert(x)<<endl;
		   	continue;
		   	case 1 :
		   		cout<<s.find(x)<<endl;
		   		continue;
		   		case 2 :
		   			s.erase(x);
		   			continue;
		 } 
	}
	
} 
