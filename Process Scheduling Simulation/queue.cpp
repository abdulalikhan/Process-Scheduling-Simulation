#include "StdAfx.h"
#include "queue.h"
#include "Node.h"
#include "Process.h"
#include <iostream>

template <class T>
queue<T>::queue(){
	front = rear = 0;
}

template <class T>
void queue<T>::deleteAll(){
	Node<T>* temp = front;
	Node<T>* currentNode;
	while (temp != 0){
		currentNode = temp;
		temp = temp->getNext();
		currentNode->setNext(0);
		if (currentNode != 0)
			delete currentNode;
	}
	front = rear = 0;
}

template <class T>
queue<T>::~queue(){
	if ((front != 0) && (rear != 0))
		deleteAll();
}

template <class T>
bool queue<T>::isEmpty() const{
	if ((front == 0) || (rear == 0))
		return true;
	return false;
}

template <class T>
bool queue<T>::isFull() const{
	Node<T>* temp = new Node<T>();
	if (temp == 0)
		return true;
	else{
		delete temp;
		return false;
	}
}

template <class T>
void queue<T>::enqueue(T data){
	if (isFull()){
		std::cout << "Error: queue is full!";
		return;
	}
	Node<T>* newNode = new Node<T>(data);
	if (front == 0 && rear == 0){
		front = newNode;
		rear = newNode;
	}else{
		rear->setNext(newNode);
		rear = newNode;
	}
}

template <class T>
T queue<T>::dequeue(){
	if (isEmpty()){
		std::cout << "Error: queue is empty!";
	}else{
		T data = front->getData();
		Node<T>* temp = front;
		if (front->getNext() == 0)
			front = rear = 0;
		else
			front = front->getNext();
		return data;
	}
}

template <class T>
T queue<T>::peek() const{
	if (isEmpty())
		std::cout << "Error: queue is empty!";
	else
		return front->getData();
}

// The following statement prevents the compiler from throwing an "undefined reference" error
// Each template instantiation must be referenced at the end of this file
template class queue<int>;
template class queue<Process>;
