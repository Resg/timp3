#include <iostream>
#include <Windows.h>
using namespace std;
template<class T1>
class Lst
{
public:
	struct el
	{
		T1 data;
		el * next;
	};
	int size = 0;
	el *head,*_end;
	Lst()
	{
		head = 0;
	}
	void add(T1 &data)
	{
		el* tmp = new el;
		tmp->next = head;
		head = tmp;
		head->data = data;
		size++;

	}
	void add_end(T1 &data)
	{
		el* tmp;
		tmp = new el;
		head->next = tmp;
		tmp->data = data;
		tmp->next = 0;
		size++;
	}
	void add_sort(T1 &data)
	{
		bool on = false;
		if (size == 0)
		{
			add(data);
			size--;
		}
		else if (size == 1)
		{
			if (data > head->data)
			{
				el* tmp;
				tmp = new el;
				head->next = tmp;
				tmp->data = data;
				tmp->next = 0;
			}
			else
			{
				add(data);
				size--;
			}
		}
		else 
		{
			el* p = head;
			while (p)
			{
				if (p->next == 0) break;
				if ((p == head) && (p->data > data))
				{
					on = true;
					add(data);
					break;
				}
				if ((data >= p->data) && (data <= p->next->data)) break;	
				p = p->next;
			}
			if (on == false)
			{
				el* tmp = new el;
				el* t = p->next;
				p->next = tmp;
				tmp->data = data;
				tmp->next = t;
			}
		}
		_end = head;
		while (_end) _end = _end->next;
		size++;
	}
	el* search(T1 &data)
	{
		el*p = head;
		while (p)
		{
			if (p->data == data) return p;
			p = p->next;
		}
		return p;
	}
	void del(T1 &data)
	{
		bool e = false;
		el*p = head;
		if (p->data == data)
		{
			e = true;
			head = head->next;
			delete p;
		}
		if (e == false)
		{
			while (p)
			{
				if (p->next->data == data) break;
				p = p->next;
			}
			el*t = p->next->next;
			delete p->next;
			p->next = t;
		}
	}
	void show()
	{
		el * u;
		u = head;
		while (u != 0)
		{
			
			u = u->next;
		}
	}
	void clear()
	{
		while (head != 0)
		{
			el* tmp = head->next;
			delete head;
			head = tmp;
		}
	}
	el* beg()
	{
		return head;
	}
	el* end()
	{
		return _end;
	}
	~Lst()
	{
		while (head != 0)
		{
			el* tmp = head->next;
			delete head;
			head = tmp;
		}
	}
	class iter
	{
	public:
		el*p;
		iter(){}
		iter& operator = (el* com)
		{
			this->p = com;
			return *this;
		}
		iter operator++(int)
		{
			this->p = this->p->next;
			return *this;
		}
		bool operator != (el* com)
		{
			if (this->p != com) return true;
			else return false;
		}
	};
};
