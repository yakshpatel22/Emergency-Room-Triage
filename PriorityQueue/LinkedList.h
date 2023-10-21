/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
*Purpose of File     :Writing the header class for LinkedLists 
*File Name           :PriorityQueue.h
*Version             :1.0.0
*/
#pragma once

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		Node* previous;
		Node* next;

		T data;
	};

protected:
	Node* begin_;
	Node* end_;

public:
	LinkedList() : begin_(nullptr), end_(nullptr) {}

	Node* begin() const { return begin_; }
	Node* end() { return end_; }

	void push_front(const T& item)
	{
		Node* node = new Node();
		node->data = item;

		//checking if there is a node to link in-front of or not
		if (begin_ != nullptr)
		{
			begin_->previous = node;
			node->next = begin_;
		}
		else
		{
			end_ = node;
		}

		begin_ = node;
	}

	void push_back(const T& item)
	{
		Node* node = new Node();
		node->data = item;

		if (begin_ == nullptr && end_ == nullptr)
		{
			begin_ = node;
			end_ = node;
			return;
		}

		node->previous = end_;
		end_->next = node;

		end_ = node;
	}

	T pop_front()
	{
		if (begin_ == nullptr)
		{
			//todo: throw
			throw "";
		}

		Node* node = begin_;
		const T value = node->data;
		begin_ = node->next;

		return value;
	}

	T pop_back()
	{
		if (end_ == nullptr)
		{
			//todo: throw
			throw "";
		}

		Node* node = end_;
		const T value = node->data;
		begin_ = node->previous;

		return value;
	}

	void insert(Node* insertionPoint, const T& item)
	{
		//If insertion point is null thenpush back the new item
		if (insertionPoint == nullptr)
		{
			push_back(item);
			return;
		}

		//Inserting the new item before the insertPoint
		Node* node = new Node();
		node->data = item;

		//Setting the links of the node
		node->next = insertionPoint;
		node->previous = insertionPoint->previous;

		//Linking the node to its previous node
		if (node->previous != nullptr)
			node->previous->next = node;
		else
			begin_ = node;

		//Linking the node to its next node
		node->next->previous = node;

		// Update size

	}

	bool empty() const
	{
		return begin_ == nullptr;
	}

	size_t size() const
	{
		size_t counter = 0;

		Node* node = begin_;
		while (node != nullptr)
		{
			++counter;
			node = node->next;
		}

		return counter;
	}
};
