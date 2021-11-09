#include <iostream>

using namespace std;

typedef long long LL;

int n;
LL _tel, _room, _clazz;
string _name;

struct student
{
	string name;
	LL tel, room, clazz;
};

class Linearlist
{
	public:
	~Linearlist() {delete [] a;}
    void Linearlistset(int capacity);
    void get_message(string name, LL tel, LL clazz, LL room);
    void edit(string name, int num, LL ne);
    void remove(string name);
    int find_name(string name);
    int get_xor(LL clazz);
    private:
    struct student *a;
    int listsize;
    int capacity;
};

void Linearlist::Linearlistset(int n)
{
    a = new student[n];
    capacity = n;
    listsize = 0;
}

void Linearlist::get_message(string name, LL tel, LL clazz, LL room)
{
	a[listsize].name = name;
	a[listsize].tel = tel;
	a[listsize].clazz = clazz;
	a[listsize].room = room;
	listsize ++;
}

void Linearlist::edit(string name, int num, LL ne)
{
	int i = 0;
	while(a[i].name != name && i < listsize) i ++;
	if(num == 1) a[i].tel = ne;
	else if(num == 2) a[i].clazz = ne;
	else if(num == 3) a[i].room = ne;
}


void Linearlist::remove(string name)
{
	int i = -1;
	while(a[++ i].name != name && i < listsize);
	
	copy(a + i + 1, a + listsize, a + i);
	
	listsize --;
}

int Linearlist::find_name(string name)
{
	int i = -1;
	while(a[++ i].name != name && i < listsize);
	if(i >= listsize) return 0;
	else return 1;
}

int Linearlist::get_xor(LL clazz)
{
	int res = 0;
	for(int i = 0; i < listsize; i ++)
	if(a[i].clazz == clazz)
	res ^= a[i].room;
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	student *a = new student[n]; 
	Linearlist L;
    L.Linearlistset(n);
	while(n --)
	{
		int m;
		cin >> m;
		if(m == 0)
		{
			cin >> _name >> _tel >> _clazz >> _room;
			L.get_message(_name, _tel, _clazz, _room);
		}
		else if(m == 1)
		{
			cin >> _name;
			L.remove(_name);
		}
		else if(m == 2)
		{
			int num;
			LL ne;
			cin >> _name >> num >> ne;
			L.edit(_name, num, ne);
		}
		else if(m == 3)
		{
			cin >> _name;
			cout << L.find_name(_name) << endl;
		}
		else if(m == 4)
		{
			cin >> _clazz;
			cout << L.get_xor(_clazz) << endl;
		}
	}
	return 0;
}
