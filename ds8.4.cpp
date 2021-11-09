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
	
	int find(int theKey)
	  {
	  	int b=(theKey)%divisor;
	  	Node* cur =table[b].next;
	  	Node* s=cur;
	  	int size=0;
		for(;s!=NULL;size++)
		{
		   s=s->next;
		  }
	  	
	  	while(cur!=NULL)
	  	{
		  	if(cur->element==theKey) 
			  {cout<<size<<endl;  return size;}
		  	
		   else cur=cur->next;
		  }
		
		cout<<"Not Found"<<endl;
		return -1;
	  	
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
	  
	  int erase(int theKey)
	  {
	  	int b=(theKey)%divisor;
	  	Node* cur = table[b].next;
	  	Node* s=cur;
	  	Node* a=cur;
	  	int size=0;
		while(s!=NULL)
		  	  	{
						size++;
						s=s->next;
					}
	  	while(cur->next!=NULL)
	  	{
		  	if(cur->next->element==theKey)
		  	{
		  		Node* p=cur->next;
		  		if(cur->next->next==NULL)
		  		{ cur->next=NULL;
				  delete p;
				  cout<<(size-1)<<endl;
				  return(size-1);
				  }
			  	else 
				  {cur->next=cur->next->next;
			  	delete p;
			  	cout<<(size-1)<<endl;
			  	return (size-1);}
			  }
			  else cur=cur->next;
			  
		  }
		  if(cur->element==theKey)
		  {while(a->next->next!=NULL) a=a->next;
		    
              delete cur;
              a->next=NULL;
              cout<<(size-1)<<endl;
              return size-1;
		}
		  else {cout<<"Delete Failed"<<endl;
		  return -1;}
	  	
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
