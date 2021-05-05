#pragma once
#include <stdexcept>
#include <iostream>

template<class T>
class List
{
private:
	size_t list_size;
	class Node
	{
	private:
		Node* next;
		Node* prev;
		T value;
	public:
		Node* getPrev() const
		{
			return this->prev;
		}
		Node* getNext() const
		{
			return this->next;
		}
		T getValue() const
		{
			return this->value;
		}

		void setPrev(Node* node)
		{
			this->prev = node;
		}
		void setNext(Node* node)
		{
			this->next = node;
		}
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
			return (this->current)->getValue();
		}
		Iterator operator++()
		{
			if (this->current != nullptr)
			{
				if (!this->reverse)
				{
					this->current = current->getNext();
				}
				else
				{
					this->current = current->getPrev();
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
					this->current = current->getNext();
				}
				else
				{
					this->current = current->getPrev();
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
					this->current = current->getPrev();
				}
				else
				{
					this->current = current->getNext();
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
					this->current = current->getPrev();
				}
				else
				{
					this->current = current->getNext();
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
			this->last_node->setNext(newNode);
			newNode->setPrev(this->last_node);
		}
		this->last_node = newNode;
		++this->list_size;
	}

	void operator+=(T value)
	{
		this->append(value);
	}

	T getElement(size_t index)
	{
		if (index + 1 > this->size())
			throw std::invalid_argument("List has not element at this index");
		auto it = this->begin();
		for (size_t i = 0; i < index; ++i)
			++it;
		return *it;
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
			Node* newNode = new Node(value, nullptr, this->first_node->getNext());
			this->first_node->setPrev(newNode);
			this->first_node = newNode;
		}
		else
		{
			Node* newNode = new Node(value, it.current->getPrev(), it.current->getNext());
			it.current->setPrev(newNode);
			it.current->getPrev()->setNext(newNode);
		}
	}

	void insert(const T& value, const size_t index)
	{
		if (index > this->size())
		{
			throw std::invalid_argument("List assignment index out of range");
		}
		else
		{
			auto it = this->begin();
			for (size_t i = 0; i < index; ++i)
			{
				++it;
			}
			this->insert(value, it);
		}
	}
	void removeFromList(const Iterator& it)
	{
		if (it.current == nullptr)
			throw std::invalid_argument("Iterator in out of list");
		if (it.current->getPrev() == nullptr && it.current->getNext() != nullptr)
		{
			Node* temp = this->first_node;
			this->first_node->getNext()->setPrev(nullptr);
			this->first_node = it.current->getNext();
			delete temp;
		}
		else if (it.current->getPrev() != nullptr && it.current->getNext() != nullptr)
		{
			Node* temp = it.current;
			temp->getPrev()->setNext(temp->getNext());
			temp->getNext()->setPrev(temp->getPrev());
			delete temp;
		}
		else
		{
			Node* temp = this->last_node;
			this->last_node->getPrev()->setNext(nullptr);
			this->last_node = it.current->getPrev();
			delete temp;
		}

		--this->list_size;
	}

	void removeFromList(size_t index)
	{
		if (index + 1 > this->size())
			throw std::invalid_argument("List has not element at this index");
		auto it = this->begin();
		for (size_t i = 0; i < index; ++i)
			++it;
		this->removeFromList(it);
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
			Node* newTemp = temp->getNext();
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

