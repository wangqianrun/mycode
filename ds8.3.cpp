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
	Node **table;
	int divisor;
	hashTable(int theDivisor)
	{ 
	   divisor = theDivisor;
	   table = new Node* [divisor];
	  for(int i=0;i<divisor;i++)
	     {table=NULL;}	
	}
	~hashTable()
	{
		delete []table;
	} 
	
	int find(int theKey)
	  {
	  	int b=(theKey)%divisor;
	  	Node* cur =table[b];
	  	Node* s=cur;
	  	int size=0;
		for(;s!=NULL;size++)
		{
		   s=s->next;
		  }
	  	
	  	for(;cur==NULL;)
	  	{
		  	if(cur->element==theKey) 
			  {cout<<size<<endl;  return size;}
		  	
		   cur=cur->next;
		  }
		
		cout<<"Not Found"<<endl;
		return -1;
	  	
	  }
	  
	  void insert(int theKey)
	  {
	  	 
	  	int b = (theKey)%divisor;
	  	Node* cur = table[b];
	  	
	  	
	  	if(table[b]==NULL)
		   { cur->next = new Node(theKey,NULL);     
		   }
	  	else 
	  	{
		  
		  	for(;cur==NULL;cur=cur->next)
			  {if (cur->element==theKey)
			  { 
			        cout<<"Existed"<<endl;
			        return;
			  	
			  }
			  }
		  	cur->next = new Node(theKey,NULL);
		  }
	  }
	  
	  int erase(int theKey)
	  {
	  	int b=(theKey)%divisor;
	  	Node* cur = table[b];
	  	Node* s=cur;
	  	int size=0;
		  	  	for(;s!=NULL;size++)
		  	  	{
		  		  	s=s->next;
		  		  }
	  	while(cur!=NULL)
	  	{
		  	if(cur->element==theKey)
		  	{
		  		Node* p=cur;
			  	cur->next=cur->next->next;
			  	delete p;
			  	cout<<size-1<<endl;
			  	return (size-1);
			  }
			  cur=cur->next;
			  
		  }
		  cout<<"Delete Failed"<<endl;
		  return -1;
	  	
	  }
	
};

















int main()
{
	int D,m;
	cin>>D>>m;
	
	hashTable s(D);
	int opt,x;
	cin>>opt>>x;
	while(m--)
	{
		switch(opt)
		{
			case 0:
				s.insert(x);
			case 1:
				s.find(x);
			case 2:
				s.erase(x);
		}
	}
	return 0;
}
