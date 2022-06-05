#include <iostream>
#include <string>
#include <windows.h>
#include "Vector.h"
using namespace std;
int read_all_int()
{
	string buff;
	int number;
	int i, flag = 0, flag_minus = 0;
	while (flag == 0)
	{
		try
		{
			getline(cin, buff);
			flag = 1;
			flag_minus = 0;
			if (buff == "") flag = 0;
			for (i = 0; i < buff.size(); i++)
			{
				if (buff[i] < '0' || buff[i]>'9')
				{
					if ((flag_minus == 0) && (buff[i] == '-') && (i == 0))
					{
						flag_minus = 1;
					}
					else
					{
						flag = 0;
						break;
					}

				}
			}
			if (flag == 1) break;
			else throw 99;


		}
		catch (int error)
		{
			cout << "Enter integer number" << endl;

		}
	}
	number = stoi(buff);

	return number;
}
int read_pos_int()
{
	string buff;
	int number;
	int i, flag = 0;
	while (flag == 0)
	{
		getline(cin, buff);
		flag = 1;
		if (buff == "") flag = 0;
		for (i = 0; i < buff.size(); i++)
		{
			if (buff[i] < '0' || buff[i]>'9')
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) break;
		cout << "Enter integer number" << endl;
	}

	number = stoi(buff);
	return number;
}
template<typename type>
ostream& operator << (ostream& out, Vector<type>& vector)
{
	for (int i = 0; i < vector.get_size(); i++)
		//for (int i = 0; i < size_of_array; i++)
	{
		out << vector.array[i] << " ";
	}
	return out;
}
template<typename type>
istream& operator >> (istream& in, Vector<type>& vector)
{
	for (int i = 0; i < vector.get_size(); i++)
	{
		vector.array[i]=read_all_int();
	}
	return in;
}
template<typename type>
void print(Vector<type> vector)
{
	cout<< vector;
}

int main()
{
	int N;
	cout << "Enter size of array" << endl;
	N = read_pos_int();
	Vector<int> v(N);
	cout << "Enter array" << endl;
	cin >> v;
	cout << "Array:" << endl;
	cout << v;
	return 0;
}
