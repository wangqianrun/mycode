#include <iostream>
using namespace std;

struct Node
{
	int element;
	Node* next;
};
class hashTable
{
	public:
	Node *table;
	int divisor;
	hashTable(int theDivisor)
	{ 
	   divisor = theDivisor;
	   table = new Node [divisor];
	  for(int i=0;i<divisor;i++)
	     {table[i].next=NULL;}	
	}
	~hashTable()
	{
		delete []table;
	} 
	
	void find(int theKey)
	  {
	  	int b=(theKey)%divisor;
	  	Node* cur =table[b].next;
	  	Node* s=cur;
	  	int size=0;
		while(s!=NULL)
		{
			size++;
		   s=s->next;
		  }
	  	
	  	while(cur!=NULL)
	  	{
		  	if(cur->element==theKey) 
			  {cout<<size<<endl;  return ;}
		  	
		   else cur=cur->next;
		  }
		
		cout<<"Not Found"<<endl;
		
	  	
	  }
	  
	  void insert(int theKey)
	  {
	  	 
	  	int b = (theKey)%divisor;
	  	Node* cur =table[b].next;
	  	Node* p=cur;
	  	if(table[b].next==NULL)
		   { table[b].next = new Node;
		   table[b].next->element=theKey;
		   table[b].next->next=NULL; 
		   }
	  	else 
	  	{
		  
		  	for(;cur!=NULL;cur=cur->next)
			  {if (cur->element==theKey)
			  { 
			        cout<<"Existed"<<endl;
			        return;
			  	
			  }
			  }
			  while(p->next!=NULL) p=p->next;
		  	p->next = new Node;
		  	p->next->element=theKey;
		  	p->next->next=NULL;
		  }
		  
	  }
	  
	  void erase(int theKey)
	  {
	  	int b=(theKey)%divisor;
	  	Node* cur = table[b].next;
	  	Node* s=cur;
	  	Node* pre=&table[b];
	  	int size=0;
		while(s!=NULL)
		  	  	{
						size++;
						s=s->next;
					}
					
		while(cur!=NULL)
		{
			if(cur->element==theKey)
			 {
			 	if(cur->next==NULL)
			 	{
				 	delete cur;
				 	pre->next = NULL;
				 	cout<<size-1<<endl;
				 	return;
				 }
				 else 
				 {
				 	pre->next=cur->next;
				 	delete cur;
				 	cout<<size-1<<endl;
				 	return;
				 }
			 }
			 else 
			 {
			 	pre=pre->next;
			 	cur=cur->next;
			 }
			 
		}
		cout<<"Delete Failed"<<endl;
		
	  	
	  }
	
};

















int main()
{
	int D,m;
	cin>>D>>m;

	
	hashTable s(D);
	int opt,x;
	
	while(m--)
	{
		cin>>opt>>x;
		switch(opt)
		{
			case 0:
				s.insert(x);
				continue;
			case 1:
				s.find(x);
				continue;
			case 2:
				s.erase(x);
				continue;
		}
	}
	return 0;
}
