#include <iostream>
using namespace std;

template<class T>
void irank(T a[],int n, int r[])
		{//给数组a的n个元素排名次
		 //结果在数组r中返回
			for (int i = 0;i < n;i++)
				r[i] = 0;      //初始化

			//比较所有元素对
			for (int i = 1;i < n;i++)
				for (int j = 0;j < i;j++)
					if (a[j] <= a[i]) r[i]++;
					else r[j]++;
		}
		template<class T>
		bool bubble(T a[], int n)  //一次冒泡排序
		{
			bool swapped = false;
			int t;
			for (int i = 0;i < n;i++)
				{
				if (a[i] > a[i + 1])
				{
					
					t = a[i + 1];
					a[i + 1] = a[i];
						a[i] = t;
					swapped = true;
				}
			}
			return swapped;
		}

// 名次排序 及时终止的选择排序  及时终止的冒泡排序 插入排序
// 需使用动态数组
template <class T>
class Sort
{
public:
	void ranksort(T a[], int n);//名次排序
	

	void selectionsort(T a[], int n); //及时终止的选择排序
	

	
	void bubblesort(T a[], int n);//及时终止的冒泡排序


	void insertionsort(T a[], int n);//插入排序
	

};
template <class T>
void Sort<T>::ranksort(T a[], int n)
{
	int *r; 
		r = new int[n];
	
		irank(a, n, r);
		//使用一个附加数组u，将元素排序
		T* u = new T[n];   //创建附加数组
		//把a中元素移到u中正确位置
		for (int i = 0;i < n;i++)
			u[r[i]] = a[i];
		//把u中的元素移回 a
		for (int i = 0;i < n;i++)
			a[i] = u[i];
		delete[] u;
		delete[] r;

	

}
template <class T>
void Sort<T>::selectionsort(T a[], int n)
{
	bool sortted = false;
	for (int size = n;!sortted && (size > 1);size--)
	{
		int indexOFMax = 0;
		sortted = true;
		//查找最大元素
		for (int i = 1;i < size;i++)
			if (a[indexOFMax] <= a[i])indexOFMax = i;
			else sortted = false;//无序
		int t;
		t = a[size - 1];
		a[size - 1] = a[indexOFMax];
		a[indexOFMax] = t;
	}
}

	template <class T>
	void Sort<T>::bubblesort(T a[], int n)
	{
		int t;
		//for (int i = n;i > 1 && bubble(a, i);i--);
		for (int i=n;i>0;i--)
		   {
		   	for(int j=0;j<i-1;j++)
		   	  {
		   	  	if(a[j]>a[j+1])
		   	  	{ t=a[j+1];
		   	  	a[j+1]=a[j];
		   	  	a[j]=t;
					 }
				 }
			} 
	}
	template <class T>
	void Sort<T>::insertionsort(T a[], int n)
	{
		for (int i = 1;i < n;i++)
		{
			T t = a[i];
			int j;
			for (j = i - 1;j >= 0 && t < a[j];j--)
				a[j + 1] = a[j];
			a[j + 1] = t;
		}

	}









int main()
{
	int n;
	int* p;
	Sort<int> S;
	cin >> n;
	p = new int[n];
	for (int i = 0; i < n;i++)
		{
		cin >> p[i];
	}
		
		
	S.ranksort(p,n);
	S.selectionsort(p,n);
	S.bubblesort(p,n);
	S.insertionsort(p, n);
	for (int i = 0;i < n;i++)
		cout << p[i]<<" ";
	return 0;
}

