#include <iostream>
#include <queue>
#include <math.h>
using namespace std;



class binaryTreeNode
{
	public:
	int element;
	binaryTreeNode *leftChild,*rightChild;     //��������������
	binaryTreeNode(){ leftChild = rightChild = NULL;}
	binaryTreeNode(const int& theElement) 
	{
		element=theElement;
		leftChild = rightChild = NULL;
		
	}
	binaryTreeNode(const int& theElement,binaryTreeNode *theLeftChild,binaryTreeNode *theRightChild)
	 {
	 	element=theElement;
	 	leftChild = theLeftChild;
	 	rightChild = theRightChild;
	 }
};




void initialize (int n,binaryTreeNode* t)
{
	queue<binaryTreeNode*> s;
	binaryTreeNode* cur=t;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(a!=-1) 
		{cur->leftChild = new binaryTreeNode (a,NULL,NULL);
		s.push(cur->leftChild);}
		if(b!=-1) 
		{cur->rightChild =new binaryTreeNode (b,NULL,NULL);
		s.push(cur->rightChild);}
		if (!s.empty())
		{
			cur=s.front();
			s.pop();
		}
		
	}
	
}



void visit(binaryTreeNode* t)
{
	cout<<t->element<<" ";
	return;
}


void preOrder(binaryTreeNode* t)    //ǰ����������� 
{
	if(t!=NULL)
	{
		visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}


void inOrder(binaryTreeNode* t)    //������������� 
{
	if(t!=NULL)
	{
	
		preOrder(t->leftChild);
		visit(t);
		preOrder(t->rightChild);
	}
}


void postOrder(binaryTreeNode* t)    //������������� 
{
	if(t!=NULL)
	{
		
		preOrder(t->leftChild);
		preOrder(t->rightChild);
		visit(t);
	}
}



void levelOrder(binaryTreeNode* t)    //��α���������
{
	queue<binaryTreeNode*> q;
	while(t!=NULL)
	{
		visit(t);
		
		
		//��t�ĺ��Ӳ������
		if(t->leftChild!=NULL)
		   q.push(t->leftChild);
		if(t->rightChild!=NULL)
		   q.push(t->rightChild);
		   
		   
		  //��ȡ��һ��Ҫ���ʵĽڵ�
		  if(q.empty())  return;
		  t=q.front();
		  q.pop();
	}
} 



/*int Nodesize(binaryTreeNode* t)
{
	if(t==NULL)
	   return 0;
	if (t->leftChild==NULL&&t->rightChild==NULL)
	    return 1;
	cout<<(Nodesize(t->leftChild)+Nodesize(t->rightChild))<<" ";
	return Nodesize(t->leftChild)+Nodesize(t->rightChild);
	
	
}  */

int Treeheight(binaryTreeNode* t)
{
	
	if(t==NULL)
	{
		return 0;
	}
	
	int leftheight = Treeheight(t->leftChild);
	int rightheight = Treeheight(t->rightChild);
	return max(leftheight,rightheight)+1;
	
}

int TreeSize(binaryTreeNode* t)
{
	if(t==NULL)
	return 0;
	else
	{
	return TreeSize(t->leftChild)+TreeSize(t->rightChild)+1;}
}

void NodeSize(binaryTreeNode* t)    //��α���������
{
	queue<binaryTreeNode*> q;
	while(t!=NULL)
	{
		cout<<TreeSize(t)<<" ";
		
		
		//��t�ĺ��Ӳ������
		if(t->leftChild!=NULL)
		   q.push(t->leftChild);
		if(t->rightChild!=NULL)
		   q.push(t->rightChild);
		   
		   
		  //��ȡ��һ��Ҫ���ʵĽڵ�
		  if(q.empty())  return;
		  t=q.front();
		  q.pop();
	}
} 

void Nodeheight(binaryTreeNode* t)    //��α���������
{
	queue<binaryTreeNode*> q;
	while(t!=NULL)
	{
		cout<<Treeheight(t)<<" ";
		
		
		//��t�ĺ��Ӳ������
		if(t->leftChild!=NULL)
		   q.push(t->leftChild);
		if(t->rightChild!=NULL)
		   q.push(t->rightChild);
		   
		   
		  //��ȡ��һ��Ҫ���ʵĽڵ�
		  if(q.empty())  return;
		  t=q.front();
		  q.pop();
	}
} 

int main()
{
	int n=0;
	cin>>n;
	binaryTreeNode t(1);
	initialize(n,&t);
	levelOrder(&t);
	cout<<endl;
	NodeSize(&t);
	cout<<endl;
	Nodeheight(&t);
} 
