#pragma once
#include "Node.h"

template <class T>
class queue
{
	private:
		Node<T>* front;
		Node<T>* rear;
	public:
		queue();
		void deleteAll();
		~queue();
		bool isEmpty() const;
		bool isFull() const;
		void enqueue(T data);
		T dequeue();
		T peek() const;
};

