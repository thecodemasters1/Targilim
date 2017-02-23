#pragma once

template <class T>
class Array
{
public:
	Array(int size);
	~Array();
	T& operator[] (int index);
	int getLength();
	void print();

private:
	T * arr;
	int length;
};

template<class T>
Array<T>::Array(int size)
{
	arr = new T[size];
	length = size;

	for (int i = 0; i < length; i++)
	{
		arr[i] = 0;
	}
}


template <class T>
Array<T>::~Array()
{
	delete[] arr;
}


#define OUT_OF_BOUNDS -1
template <class T>
T& Array<T>::operator[] (int index)
{
	if (index < 0 || index >= length)
	{
		throw OUT_OF_BOUNDS;
	}
	return arr[index];
}

template <class T>
int Array<T>::getLength()
{
	return length;
}

template <class T>
void Array<T>::print()
{
	for (int i = 0; i < length; ++i)
	{
		printf("[%d]: %d\n", i, arr[i]);
	}
}
