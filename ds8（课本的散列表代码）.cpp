#include <iostream>

using namespace std;

template <class K,class E>
class hashTable
{
	public:
	hashTable(int theDivisor);
	int search(const K& theKey ) const;
	pair<const K,E>* find(const K& theKey) const;
	int insert(const pair<const K,E>& thePair);
	int pop (const K& theKey);
	
	pair<const K, E>** table;  //散列表 
	hash<K> hash;             //把类型K映射到一个非整数
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
		
	   int i =(int) hash(theKey) % divisor;    //起始桶 
	   int j = i;                            //从起始桶开始 
	   do{
	   	if (table[j] == NULL || table[j]->first == theKey) return j;
	   	j = (j+1) % divisor;             //下一个桶 
	   }while(j != i);                    //是否返回到起始桶？ 
	   
	   return j; 
	}


template <class K,class E>
pair<const K,E>* hashTable<K,E>::find(const K& theKey) const
{
	//返回匹配数对的指针
	//如果匹配数对不存在，返回NULL 
	  //搜索散列表
	  int b = search(theKey);
	  
	  //判断table[b]是否是匹配数对
	  if (table[b] == NULL || table[b]->first != theKey)
	  return NULL;    //没有找到
	  
	  return table[b];    //找到匹配数对 
}

template<class K,class E>
int hashTable<K,E>::insert(const pair<const K,E>& thePair)
{
	//把数对thePair插入字典，若存在关键字相同的数对，则覆盖
	//若表满，则抛出异常
	//搜索散列表，查找匹配的数对
	int b = search(thePair.first);
	
	//检查匹配的数对是否存在
	if (table[b] == NULL)
	{
		//没有匹配的数对，而且表不满
		table[b]= new pair<const K,E> (thePair);
		dSize++; 
		cout<<b<<endl;
		return b;
	} 
	else 
	{
		//检查是否有重复的关键字数对或是否表满
		if (table[b]->first == thePair.first)
		{
			//有重复的关键字数对，修改table[b]->second
			  table[b]->second = thePair.second;
			 
			 
		} 
		else                           //表满 
		   throw hashTableFull();
	}
}





int main()
{
	
} 
