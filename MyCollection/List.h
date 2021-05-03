#pragma once
#include <stdexcept>

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
			return (this->current)->getValue();
		}
		Iterator operator++()
		{
			if (!this->reverse)
			{
				this->current = current->getNext();
			}
			else
			{
				this->current = current->getPrev();
			}
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator temp = *this;
			if (!this->reverse)
			{
				this->current = current->getNext();
			}
			else
			{
				this->current = current->getPrev();
			}
			return temp;
		}
		Iterator operator--()
		{
			if (!this->reverse)
			{
				this->current = current->getPrev();
			}
			else
			{
				this->current = current->getNext();
			}
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator temp = *this;
			if (!this->reverse)
			{
				this->current = current->getPrev();
			}
			else
			{
				this->current = current->getNext();
			}
			return temp;
		}
		bool operator==(const Iterator& it) const
		{
			if (this->current == it.current)
				return true;
			return false;
		}
		bool operator!=(const Iterator& it) const
		{
			return !(*this == it);
		}
		Iterator(const List& parent, bool reverse = false)
		{
			this->reverse = reverse;
			if (!reverse)
			{
				this->current = parent.first_node;
			}
			else
			{
				this->current = parent.last_node;
			}
		}
	};

	Iterator begin() const
	{
		return Iterator(*this);
	}

	Iterator end() const
	{
		Iterator it(*this, true);
		--it;
		return it;
	}

	Iterator rbegin() const
	{
		return Iterator(*this, true);
	}

	Iterator rend() const
	{
		Iterator it(*this);
		--it;
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

	void removeFromList(size_t index)
	{
		if (index + 1 > this->size())
			throw std::invalid_argument("List has not element at this index");
		auto it = this->begin();
		for (size_t i = 0; i < index; ++i)
			++it;
		if (it.current->getPrev() == nullptr and it.current->getNext() != nullptr)
		{
			Node* temp = this->first_node;
			this->first_node->getNext()->setPrev(nullptr);
			this->first_node = it.current->getNext();
			delete temp;
		}
		else if (it.current->getPrev() != nullptr and it.current->getNext() != nullptr)
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


	List()
	{
		this->first_node = nullptr;
		this->last_node = nullptr;
		this->list_size = 0;
	}
	~List()
	{
		Node* temp = this->first_node;
		while (temp != nullptr)
		{
			Node* newTemp = temp->getNext();
			delete temp;
			temp = newTemp;
		}
	}
};