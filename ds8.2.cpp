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
	
	chainNode* table;  //ɢ�б� 
	//hash<K> hash;             //������Kӳ�䵽һ��������
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
		
	   int i =(int) (theKey) % divisor;    //��ʼͰ 
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
int hashTable<K,E>::insert(const K& theKey)
{
	//������thePair�����ֵ䣬�����ڹؼ�����ͬ�����ԣ��򸲸�
	//�����������׳��쳣
	//����ɢ�б�����ƥ�������
	int b = search(theKey);
	
	//���ƥ��������Ƿ����
	if (table[b] == NULL)
	{
		//û��ƥ������ԣ����ұ���
		table[b]= new pair<const K,E> (theKey,b);
		dSize++; 
		return b;
		
		
	} 
	else 
	{
		//����Ƿ����ظ��Ĺؼ������Ի��Ƿ����
		if (table[b]->first == theKey)
		{
			//���ظ��Ĺؼ������ԣ��޸�table[b]->second
			 // table[b]->second = thePair.second;
			 cout<<"Existed"<<endl;
			 return -1;
			 
		} 
		else
		    return -1;;                           //���� 
	        
	}
}





template<class K,class E>
void hashTable<K,E>::erase(const K theKey)
{//����Ԫ�ص�ɾ�� create erase function
	int count=0;
	int b=search(theKey);//find the delete bucket number
	int a=b,n=b;//bΪ�жϺ������ aΪ��b�з���Ҫ���ǰ��  n������λ 
				//if b cut the mustard then use a to put it forward ;else use n to diecison 
	pair<const K,E>* current=table[b];
	if(table[b]==NULL||table[b]->first!=theKey)
		cout<<"Not Found"<<endl;
	else
	{	delete current;//ɾ�����  delete current
		b=(b+1)%divisor;//b���ȼ�һ��λ  
		while(table[b]!=NULL&&b!=n)//ֻ���ߵ�null��������������˷���ֹͣ 
		{
			int m=(int)table[b]->first%divisor;
 
			if((a<b&&m>b)||(a>b&&m>b&&a>=m)||(a<b&&b>m&&a>=m))  //the three logical relations will be explain in the essay
			{	
				table[a]=table[b];//exchange a and b
				a=b;
				count++;//exchange time
			}
			b=(b+1)%divisor;//bҪһ��������̽��  let b to point next bucket
		}
		cout<<count<<endl;
	}
	table[a]=NULL;//�����һ��û��ֵ�ĸ�ֵΪnull�� 
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
