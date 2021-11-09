#include <iostream>
using namespace std;

// 名次排序 及时终止的选择排序  及时终止的冒泡排序 插入排序
// 需使用动态数组
template <class T>
class Sort
{
public:
	void ranksort(T a[],int n)//名次排序
{       
	r = new int [n]
	void rank(T a[],int n,int r[])
	{//给数组a的n个元素排名次
	 //结果在数组r中返回
	for (int i=0;i<n;i++)
		r[i] = 0;      //初始化

	//比较所有元素对
	for (int i = 1;i<n,i++)
		for(int j = 0;j<i;j++)
			if(a[j]<=a[i]) r[i]++;
	                else r[j]++;
	}
	rank(a,n,r);
   //使用一个附加数组u，讲元素排序
   T *u = new T [n];   //创建附加数组
   //把a中元素移到u中正确位置
   for(int i=0;i<n;i++)
	   u[r[i]]=a[i];
   //把u中的元素移回 a
   for(i =0;i<n;i++)
	   a[i] = u[i];
   delete [] u;
   delete [] r;

}	

void selectionsort(T a[],int n) //及时终止的选择排序
{
	bool sortted = false;
	for (int size =n;!sorted && (size>1);size--)
	{
		int indexOFMax=0;
		sorted = true;
		//查找最大元素
		for (int i = 1;i<size,i++)
			if (a[indexOFMax]<= a[i] indexOFMax = i);
		       else sorted = false;//无序
		int t;
		t=a[size - 1];
		a[size -1] = a[indexOFMax];
		a[indexOFMax] = t;
	}
}

bool bubble(T a[], int n)
{
	bool swapped = false;
	for (int i = 0;i<n;i++)
		if(a[i]>a[i+1])
		{
			int t;
			t=a[i+1];
			a[i+1]=a[i]
			a[i]=t;
		swapped = true;
		}
	return swapped;
}
void bubblesort(T a[],int n)
{
	for (int i =n;i>1 && bubble(a,i);i--);
}


};

void insertionsort(T a[],int n) //插入排序
{
	for (int i=1;i<n;i++)
	{
		T t = a[i];
		int j;
		for(j=i-1;j>=0 && t< a[j];j--)
			a[j+1] = a[j];
		a[j+1] = t;
	}

}





int main()
{
	int size;
	int *p;
	p=new int [n];
	cin>>size;
	for (int i=0,i<n;i++)
		cin>>p[i];
	cout<<Sort.insertionsort(p,n)<<endl;
	system("pause");
	return 0;
}
