#include <iostream>

using namespace std;

template <class K,class E>
class hashTable
{
	public:
	hashTable(int theDivisor);
	int search(const K& theKey ) const;
	int find(const K& theKey) const;
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
int hashTable<K,E>::find(const K& theKey) const
{
	//����ƥ�����Ե�ָ��
	//���ƥ�����Բ����ڣ�����NULL 
	  //����ɢ�б�
	  int b = search(theKey);
	  
	  //�ж�table[b]�Ƿ���ƥ������
	  if (table[b] == NULL || table[b]->first != theKey)
	  return -1;    //û���ҵ�
	  
	  return b;    //�ҵ�ƥ������ 
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
			  //table[b]->second = thePair.second;
			 cout<<"Existed"<<endl;
			 return -1;
			 
		} 
		else                           //���� 
		   return -1;
	
}
}

template <class K,class E>
int hashTable<K,E>::pop(const K& theKey)
{
	int b = search(theKey);
	if(table[b] == NULL || table[b]->first != theKey)
	   {
	   	  cout <<"Not Found"<<endl;
			 return -1; 
	   }
	   else 
	   { 
	      table[b]=NULL;
	   	int flag=0;
	   	for(int i=(b+1) % divisor;table[i]->first==theKey;i=(i+1 % divisor) )
	   	{
		   	table[(i-1) % divisor] = table[i];
		   	table[i]=NULL;
		   	flag++;
		   }
		   return flag;
	   }
}





int main()
{
	int D,m;
	int opt,x;
	cin>>D>>m;
	hashTable<int,int> s(D);
	while(m--)
	{
		cin>>opt>>x;
		if(opt==0)
		{
			s.insert(x);
		}
		if(opt==1)
		{
			s.find(x);
		}
		if(opt==2)
		{
			s.pop(x);
		}
	}
	return 0;
} 
