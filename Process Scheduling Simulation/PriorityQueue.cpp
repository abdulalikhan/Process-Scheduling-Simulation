#include "StdAfx.h"
#include "PriorityQueue.h"
#include "Node.h"
#include "Process.h"
#include <iostream>

template <class T>
PriorityQueue<T>::PriorityQueue(){
	front = rear = 0;
}

template <class T>
void PriorityQueue<T>::deleteAll(){
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
PriorityQueue<T>::~PriorityQueue(){
	if ((front != 0) && (rear != 0))
		deleteAll();
}

template <class T>
bool PriorityQueue<T>::isEmpty() const{
	if ((front == 0) || (rear == 0))
		return true;
	return false;
}

template <class T>
bool PriorityQueue<T>::isFull() const{
	Node<T>* temp = new Node<T>();
	if (temp == 0)
		return true;
	else{
		delete temp;
		return false;
	}
}

template <class T>
void PriorityQueue<T>::enqueue(T data){
	if (isFull()){
		std::cout << "Error: Priority Queue is full!";
		return;
	}
	Node<T>* newNode = new Node<T>(data);
	if (isEmpty())
		front = rear = newNode;
	else{
		Node<T>* temp = front;
		Node<T>* prev = 0;
		while (temp != 0){
			if (temp == front && temp->getData() > data){
				newNode->setNext(front);
				front = newNode;
				return;
			}else if (temp->getData() > data){
				prev->setNext(newNode);
				newNode->setNext(temp);
				return;
			}
			if (temp->getNext() == 0)
				break;
			prev = temp;
			temp = temp->getNext();
		}
		if (temp->getNext() == 0){
			rear->setNext(newNode);
			rear = newNode;
		}
	}
}

template <class T>
T PriorityQueue<T>::dequeue(){
	if (isEmpty()){
		std::cout << "Error: Priority Queue is empty!";
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
T PriorityQueue<T>::peek() const{
	if (isEmpty())
		std::cout << "Error: Priority Queue is empty!";
	else
		return front->getData();
}

// The following statement prevents the compiler from throwing an "undefined reference" error
// Each template instantiation must be referenced at the end of this file
template class PriorityQueue<int>;
template class PriorityQueue<Process>;