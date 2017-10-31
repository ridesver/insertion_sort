#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void insert(int *a, int b)
{
	int i, j;
	for (i = 1; i <= b - 1; i++)
	{
		for (int j = i-1; j >=0 && a[j] > a[j + 1]; j--)
			swap(a[j], a[j + 1]);
	}
}

bool numbers(int *a, int b)
{
	cout << "Enter elements: \n";
	string k;
	getline(cin, k);
	istringstream stream(k);
	bool c = true;
	for (int i = 0; i < b; i++)
	{
		if (!(stream >> a[i]))
		{
			c = false;
			break;
		}
	}
	return c;
}

int main()
{
	int *a, b;
	cout << "Enter the number of elements: \n";
	cin >> b;
	cin.get();
	a = new int[b];
	if (numbers(a, b))
	{
		insert(a, b);
		cout << "Result: \n";
		for (int i = 0; i < b; i++)
		{
			cout << a[i] << " ";
		}
		cout << '\n';
	}
	else cout << "An error has occured while reading input data. \n";
	return 0;
}
