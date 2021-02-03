#pragma once
#include "Node.h"

template <class T>
class PriorityQueue
{
	private:
		Node<T>* front;
		Node<T>* rear;
	public:
		PriorityQueue();
		void deleteAll();
		~PriorityQueue();
		bool isEmpty() const;
		bool isFull() const;
		void enqueue(T data);
		T dequeue();
		T peek() const;
};

