#include "stdafx.h"
#include "list_function.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	
	list head;
	int N;
	int j;
	cin >> N;
	string data;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		if (data == "add")
		{
			cin >> j;
			cin >> data;
			head.add(j, data);
		}
		if (data == "get")
		{
			cin >> j;
			head.get(j);
		}
		if (data == "del")
		{
			cin >> j;
			head.del(j);
		}

	}
	head.dellist();
	return 0;
}