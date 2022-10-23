#pragma once

template<class T>
class CustomArray
{
public:
	CustomArray();
	~CustomArray();
	void reserve(int newCapacity);
	void push(T value);
	void insert(int index, T value);
	void remove(int index);
	T pop();
	void clear();
	int findIndex(T value);
private:
	T* data = nullptr;
	int m_Size;
	int m_Capacity = 4;
};


template<class T>
CustomArray<T>::CustomArray()
{
	data = new T[m_Capacity];
	m_Size = 0;
}

template<class T>
CustomArray<T>::~CustomArray()
{
	delete[] data;
}

template<class T>
void CustomArray<T>::reserve(int newCapacity)
{
	if (newCapacity < m_Capacity) return;
	T* temp = data;
	data = new T[newCapacity];
	for (int i = 0; i < m_Size; ++i)
	{
		data[i] = temp[i];
	}
	m_Capacity = newCapacity;
	delete[]temp;

}

template<class T>
void CustomArray<T>::push(T value)
{
	if (m_Size + 1 > m_Capacity)
	{
		reserve(2*m_Capacity + 1);
	}
	data[m_Size] = value;
	m_Size++;
}

template<class T>
void CustomArray<T>::insert(int index, T value)
{
	if (!value || index < 0 || index > m_Size)
	{
		return;
	}

	if (m_Size + 1 > m_Capacity)
	{
		reserve(2 * m_Capacity + 1);
	}

	for (int i = m_Size; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[index] = value;

	m_Size++;
}

template<class T>
void CustomArray<T>::remove(int index)
{
	if (index<0 || index > m_Size - 1)
	{
		return;
	}

	data[m_Size] = -1;
	for (int i = index; i < m_Size; i++)
	{
		data[i] = data[i + 1];
	}
	m_Size--;
}

template<class T>
T CustomArray<T>::pop()
{
	if (m_Size == 0)return;
	T temp = data[m_Size - 1];
	m_Size--;
	return temp;
}

template<class T>
void CustomArray<T>::clear()
{
	delete[] data;
	m_Size = 0;
}

template<class T>
int CustomArray<T>::findIndex(T value)
{
	if (m_Size == 0)return -1;
	for (int i = 0; i < m_Size; ++i)
	{
		if (data[i] == value)
			return i;
	}
	return -1;
}