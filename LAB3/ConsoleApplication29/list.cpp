#include "stdafx.h"
#include "list_function.h"
#include <string>
#include <iostream>
using namespace std;


list::list()
{

	next = nullptr;
	info = "";
}

void list::dellist()
{
	list *temp, *temp2;
	temp2 = nullptr;
	temp = this;
	while (this->next != nullptr)
	{
		while (temp->next != nullptr)
		{
			temp2 = temp;
			temp = temp->next;
		}
		delete temp;
		temp2->next = nullptr;
	}
}

void list::add(int i, string data)
{
	if (i == 0)
	{
		this->info = data;
	}
	else
	{
		if (this->next == nullptr)
		{
			this->next = new list();
			this->next->add(i - 1, data);
		}
		else
		{
			this->next->add(i - 1, data);
		}
	}
}

void list::get(int i)
{
	if (next == nullptr && info == "")  //проверка список на пустоту 
	{
		cout << "null list" << endl;
		return;
	}
	bool empty = false; //проверка создания элемента
	list *pp = this;
	for (int j = 0; j < i; j++)
	{
		if (pp->next == nullptr&& j != 0)
		{
			empty = true;
			break;
		}
		pp = pp->next;
	}
	if (!empty)
	{
		cout << pp->info.data() << endl;
	}
	else
	{
		cout << "no index" << endl;
	}

}

void list::del(int i)
{
	list *p = this;
	list *pp;
	if (next == nullptr && info == "")
	{
		cout << "null list" << endl;
		return;
	}
	if (i = 0)   // Удаление элемента со сдвигом 
	{			 
		p->info = "";
	}
	else
	{
		for (int j = 0; j < i - 1; j++)
		{

			p = p->next;
		}
		pp = p;			//сохраниение предыдущего элемента
		p = p->next;
		pp->next = p->next;  // смена указателя на предыдущем элементе на указатель (следующего элемента)
		delete p;
	}

}