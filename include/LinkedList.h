#pragma once
#include <iostream>
#include <time.h>
namespace List
{
	template<typename T>
	class LinkedList
	{
		
	private:
		struct Node
		{
			T data;
			Node* next;
			Node(const T& value) : data(value), next(nullptr) {}
		};

		Node* _head;
		Node* _tail;
		size_t _size;
	public:
		LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {};

		LinkedList(const LinkedList& other) : _head(nullptr), _tail(nullptr), _size(0)
		{
			Node* tmp = other._head;
			while (tmp)
			{
				push_tail(tmp->data);
				tmp = tmp->next;
			}
		}

		LinkedList(const size_t amount);
		
		~LinkedList()
		{
			clear();
		}
		LinkedList<T>& operator=(const LinkedList<T>& other)
		{
			clear();
			Node* tmp = other._head;
			while (tmp)
			{
				push_tail(tmp->data);
				tmp = tmp->next;
			}
			return *this;
		}
		LinkedList<T>& push_tail(T item)
		{
			Node* newnode = new Node(item);
			if (!_head)
			{
				_head = newnode;
				_tail = newnode;
			}
			else
			{				
				_tail->next = newnode;
				_tail = newnode;
			}
			_size++;
			return *this;
		}
		LinkedList<T>& push_tail(const LinkedList<T>& other)
		{
			Node* tmp = other._head;
			while (tmp)
			{
				push_tail(tmp->data);
				tmp = tmp->next;
			}return *this;
		}
		LinkedList<T>& push_head(T item)
		{
			Node* newnode = new Node(item);
			newnode->next = _head;
			_head = newnode;
			_size++;
			return *this;
		}
		LinkedList<T>& push_head(const LinkedList<T>& other)
		{
			LinkedList<T> copy(other);
			Node* tmp = this->_head;
			while (tmp)
			{
				copy.push_tail(tmp->data);
				tmp = tmp->next;
			}
			*this = copy;
			return *this;
		}
		LinkedList<T>& pop_head()
		{
			Node* tmp = _head;
			_head = _head->next;
			delete tmp;
			_size--;
			return *this;
		}
		LinkedList<T>& pop_tail()
		{
			delete _tail->next;
			_tail = nullptr;
			_size--;
			_tail = _head;
			for (int i = 0; i < _size-1; ++i)
			{
				_tail = _tail->next;
			}
			return *this;
		}
		LinkedList<T>& delete_node(T item)
		{
			while (_head->data == item )
			{
				pop_head();
				if (!_head)
				{
					break;
				}
			}
			Node* cur = _head;
			Node* prev = cur;
			while (cur)
			{				
				if (cur->data == item)
				{
					prev->next = cur->next;
					delete cur;
					_size--;
					cur = prev->next;
				}
				else
				{
					prev = cur;
					cur = cur->next;
				}
			}
			_tail = prev;
			return *this;
		}
		T& operator[](const size_t index)
		{
			Node* tmp = _head;
			for (int i = 0; i != index; ++i)
			{
				tmp = tmp->next;
			}
			return tmp->data;
		}
		const T& operator[](const size_t index) const
		{
			Node* tmp = _head;
			for (int i = 0; i != index; ++i)
			{
				tmp = tmp->next;
			}
			return tmp->data;
		}
		size_t size() const
		{
			return _size;
		}
		LinkedList<T>&  clear()
		{
			Node* current = _head;
			while (current)
			{
				Node* tmp = current;
				current = current->next;
				delete tmp;
			}
			_head = nullptr;
			_tail = nullptr;
			_size = 0;
			return *this;
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
	{
		out << "[";
		if (list.size())
		{
			for (int i = 0; i < list.size() - 1; ++i)
			{
				out << list[i] << ", ";
			}
			out << list[list.size() - 1];
		}		
;		out << "]";
		return out;
	}
	template<> LinkedList<int>::LinkedList(const size_t amount):_head(nullptr), _tail(nullptr), _size(0)
	{
		srand(time(NULL));
		for (int i = 0; i < amount; ++i)
		{
			push_tail( rand() % 10);
		}
		
	}
	

}
