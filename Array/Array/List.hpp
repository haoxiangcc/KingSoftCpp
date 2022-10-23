#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T _data;
	struct Node* next;
	struct Node* pre;
	Node() :_data(0), next(nullptr), pre(nullptr) {}
	Node(T data) :_data(data), next(nullptr), pre(nullptr) {}
};

template<typename T>
class CustomList
{
public:
	CustomList() {};
	Node<T> push(T data);
	Node<T> insert(int index,T data);
	T find(int index);
	void remove(int index);
	void popall();
private:
	int _size = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
};

template<typename T>
Node<T> CustomList<T>::push(T data)
{
	Node<T>* node = new Node<T>(data);
	if (this->head != nullptr)
	{
		this->tail->next = node;
		node->pre = this->tail;
		this->tail = node;
	}
	else
	{
		this->head = node;
		this->tail = head;
	}
	this->_size++;
	return node;
}

template<typename T>
Node<T> CustomList<T>::insert(int index, T data)
{
	if (index <= 0 || index > this->_size)return nullptr;
	if (index == this->_size)return push(data);
	Node<T>* node = new Node<T>(data);
	if (index == 0)
	{
			node->next = this->head;
			this->head->pre = node;
			head = node;
	}
	else
	{
		Node<T>* temp = this->head;
		int i = 0;
		while (i < index && temp->next)
		{
			temp = temp->next;
			++i;
		}
		node->next = temp;
		node->pre = temp->pre;
		temp->pre = node;
		node->pre->next = node;
	}
	this->_size++;
	return;
}

template<typename T>
T CustomList<T>::find(int index)
{
	if (index < 0 || index > this->_size)
	{
		return -1;
	}
	int i = 0;
	Node<T>* temp = this->head;
	while (i < index && temp->next)
	{
		temp = temp->next;
		++i;
	}
	return temp->data;
}

template<typename T>
void CustomList<T>::remove(int index)
{
	if (index < 0 || index > this->_size)
	{
		return;
	}
	if (index == 0)
	{
		Node<T>* temp = this->head->next;
		temp->pre = nullptr;
		delete this->head;
		this->head = temp;
	}
	else if (index == this->_size)
	{
		Node<T>* temp = this->tail;
		this->tail = this->tail->pre;
	}
	else
	{
		int i = 0;
		Node<T>* temp = this->head;
		while (i < index && temp->next)
		{
			temp = temp->next;
			++i;
		}
		temp->pre->next = temp->next;
		temp->next->pre = temp->pre;
		delete temp;
	}

	this->_size--;
	return;
}

template<typename T>
void CustomList<T>::popall()
{
	int i = 0;
	Node<T>* temp1 = this->head;
	Node<T>* temp2 = nullptr;
	while (i < this->_size && temp1->next)
	{
		temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
		++i;
	}
	if (temp1)delete temp1;
	this->head = nullptr;
	this->tail = nullptr;
	this->_size = 0;
	return;
}