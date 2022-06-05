#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
template<typename type>
class Vector
{
private:
	int size_of_array;
public:
	type* array;
	Vector() {};
	Vector (int size)
	{
		array = new type[size];
		size_of_array = size;
	}
	int get_size()
	{
		return size_of_array;
	}
	void set_size(int size_tmp)
	{
		size_of_array = size_tmp;
	};
	Vector& operator = (Vector vector_tmp)
	{
		for (int i = 0; i < size_of_array; i++)
			array[i] = vector_tmp.array[i];
		return *this;
	}
};