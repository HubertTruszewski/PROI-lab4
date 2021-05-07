#pragma once
#include <stdexcept>
#include <iostream>

template<class T>
class List
{
private:
	size_t list_size;
	struct Node
	{
		Node* next;
		Node* prev;
		T value;
		Node(T value, Node* prev = nullptr, Node* next = nullptr)
		{
			this->value = value;
			this->prev = prev;
			this->next = next;
		}
	};
	Node* first_node;
	Node* last_node;
public:

	class Iterator
	{
		friend List;
	private:
		Node* current;
		bool reverse;
	public:
		T operator*() const
		{
			if (current == nullptr)
				throw std::out_of_range("Iterator is out of range");
			return (this->current)->value;
		}
		Iterator operator++()
		{
			if (this->current != nullptr)
			{
				if (!this->reverse)
				{
					this->current = current->next;
				}
				else
				{
					this->current = current->prev;
				}
			}
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator temp = *this;
			if (this->current != nullptr)
			{
				if (!this->reverse)
				{
					this->current = current->next;
				}
				else
				{
					this->current = current->prev;
				}
			}
			return temp;
		}
		Iterator operator--()
		{
			if (this->current != nullptr)
			{
				if (!this->reverse)
				{
					this->current = current->prev;
				}
				else
				{
					this->current = current->next;
				}
			}
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator temp = *this;
			if (this->current != nullptr)
			{
				if (!this->reverse)
				{
					this->current = current->prev;
				}
				else
				{
					this->current = current->next;
				}
			}
			return temp;
		}
		bool operator==(const Iterator& it) const
		{
			if (this->reverse != it.reverse) 
				return false;
			if (this->current != it.current)
				return false;
			return true;
		}
		bool operator!=(const Iterator& it) const
		{
			return !(*this == it);
		}
		Iterator(const List& parent, Node* start_value, bool reverse = false)
		{
			this->reverse = reverse;
			this->current = start_value;
		}
	};

	Iterator begin() const
	{
		return Iterator(*this, this->first_node);
	}

	Iterator end() const
	{
		Iterator it(*this, this->last_node);
		++it;
		return it;
	}

	Iterator rbegin() const
	{
		return Iterator(*this, this->last_node, true);
	}

	Iterator rend() const
	{
		Iterator it(*this, this->first_node , true);
		++it;
		return it;
	}

	size_t size() const
	{
		return this->list_size;
	}

	bool isIn(const T& value) const
	{
		for (auto it = this->begin(); it != end(); ++it)
		{
			if (*it == value)
				return true;
		}
		return false;
	}

	void append(T value)
	{
		Node* newNode = new Node(value);
		if (this->first_node == nullptr)
		{
			this->first_node = newNode;
		}
		if (this->last_node != nullptr)
		{
			this->last_node->next = newNode;
			newNode->prev = this->last_node;
		}
		this->last_node = newNode;
		++this->list_size;
	}

	void operator+=(T value)
	{
		this->append(value);
	}

	void insert(const T& value, const Iterator& it)
	{
		if (it.current == nullptr && this->list_size != 0)
			throw std::invalid_argument("Iterator in out of list");
		if (it.current == this->last_node || it.current == nullptr)
		{
			this->append(value);
		}
		else if (it.current == this->first_node)
		{
			Node* newNode = new Node(value, nullptr, this->first_node->next);
			this->first_node->prev = newNode;
			this->first_node = newNode;
		}
		else
		{
			Node* newNode = new Node(value, it.current->prev, it.current->next);
			it.current->prev = newNode;
			it.current->prev->next = newNode;
		}
	}

	void removeFromList(const Iterator& it)
	{
		if (it.current == nullptr)
			throw std::invalid_argument("Iterator in out of list");
		if (it.current->prev == nullptr && it.current->next != nullptr)
		{
			Node* temp = this->first_node;
			this->first_node->next->prev = nullptr;
			this->first_node = it.current->next;
			delete temp;
		}
		else if (it.current->prev != nullptr && it.current->next != nullptr)
		{
			Node* temp = it.current;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		else
		{
			Node* temp = this->last_node;
			this->last_node->prev->next = nullptr;
			this->last_node = it.current->prev;
			delete temp;
		}

		--this->list_size;
	}

	List()
	{
		this->first_node = nullptr;
		this->last_node = nullptr;
		this->list_size = 0;
	}
	~List()
	{
		Node* temp = this->first_node;
		while (temp != 0)
		{
			Node* newTemp = temp->next;
			delete temp;
			temp = newTemp;
		}
		this->first_node = nullptr;
		this->last_node = nullptr;
	}
};


template<class T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list)
{
	for (auto i : list)
	{
		stream << i << std::endl;
	}
	return stream;
}

