#pragma once
template <class T>
class Node
{
	private:
		T data;
		Node<T>* next;
	public:
		Node();
		Node(T data);
		Node(T data, Node<T>* next);
		T getData() const;
		Node<T>* getNext() const;
		void setData(T data);
		void setNext(Node<T>* next);
};

