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
	
	pair<const K, E>** table;  //ɢ�б� 
	hash<K> hash;             //������Kӳ�䵽һ��������
	int dSize;                //�ֵ������Ը��� 
	int divisor;              //ɢ�к�������
	 
	 
	
};


//���캯��
	template<class K,class E>
	hashTable<K,E>::hashTable(int theDivisor)
	{
		divisor = theDivisor;
		dSize = 0;
		//����ͳ�ʼ��ɢ�б���
		table = new pair<const K,E>* [divisor];
		for (int i = 0;i<divisor;i++)
		   table[i] = NULL; 
	} 
	
	template<class K,class E>
	int hashTable<K,E>::search(const K& theKey) const
	{
		//����һ��������ַɢ�б����ҹؼ���ΪtheKey������
		//���ƥ������Դ��ڣ���������λ�ã���������б���
		//�򷵻عؼ���ΪtheKey�����Կ��Բ����λ��
		
	   int i =(int) hash(theKey) % divisor;    //��ʼͰ 
	   int j = i;                            //����ʼͰ��ʼ 
	   do{
	   	if (table[j] == NULL || table[j]->first == theKey) return j;
	   	j = (j+1) % divisor;             //��һ��Ͱ 
	   }while(j != i);                    //�Ƿ񷵻ص���ʼͰ�� 
	   
	   return j; 
	}


template <class K,class E>
pair<const K,E>* hashTable<K,E>::find(const K& theKey) const
{
	//����ƥ�����Ե�ָ��
	//���ƥ�����Բ����ڣ�����NULL 
	  //����ɢ�б�
	  int b = search(theKey);
	  
	  //�ж�table[b]�Ƿ���ƥ������
	  if (table[b] == NULL || table[b]->first != theKey)
	  return NULL;    //û���ҵ�
	  
	  return table[b];    //�ҵ�ƥ������ 
}

template<class K,class E>
int hashTable<K,E>::insert(const pair<const K,E>& thePair)
{
	//������thePair�����ֵ䣬�����ڹؼ�����ͬ�����ԣ��򸲸�
	//�����������׳��쳣
	//����ɢ�б�����ƥ�������
	int b = search(thePair.first);
	
	//���ƥ��������Ƿ����
	if (table[b] == NULL)
	{
		//û��ƥ������ԣ����ұ���
		table[b]= new pair<const K,E> (thePair);
		dSize++; 
		cout<<b<<endl;
		return b;
	} 
	else 
	{
		//����Ƿ����ظ��Ĺؼ������Ի��Ƿ����
		if (table[b]->first == thePair.first)
		{
			//���ظ��Ĺؼ������ԣ��޸�table[b]->second
			  table[b]->second = thePair.second;
			 
			 
		} 
		else                           //���� 
		   throw hashTableFull();
	}
}





int main()
{
	
} 
