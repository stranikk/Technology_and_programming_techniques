#include<iostream>
using namespace std;

void line(int i, int* a, size_t n) // прямой обход
{
	for (size_t j = 0; j<n; j++)
		if (a[j] == i)
		{
			cout << j;
			line(j, a, n);
		}
}


void back(int i, int* a, size_t n) // обратный обход
{
	for (size_t j = 0; j<n; j++)
		if (a[j] == i)
		{
			back(j, a, n);
		}
	if (i != -1) cout << i;
}

void simettr(int i, int* a, size_t n) // симметричный обход
{
	int x = 0;
	for (size_t j = 0; j<n; j++)
		if (a[j] == i)
		{
			simettr(j, a, n);
			if ((!x) && (i != -1)) cout << i;
			x++;
		}
	if (x == 0)
	{
		cout << i;
	}
}


int main()
{
	size_t n;
	cout << "size of tree: ";
	cin >> n;
	int* tree = new int[n];
	for (size_t i = 0; i<n; i++)
		cin >> tree[i];

	cout << "Pramoi obxod: ";
	line(-1, tree, n);
	cout << endl;
	cout << "Obratni obxod: ";
	back(-1, tree, n);
	cout << endl;
	cout << "Simmetrichni obxod: ";
	simettr(-1, tree, n);
	cout << endl;

	delete[] tree;
	return 0;
}
