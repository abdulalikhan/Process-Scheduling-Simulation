#include "StdAfx.h"
#include "Node.h"
#include "process.h"

template <class T>
Node<T>::Node(){
	next = 0;
}

template <class T>
Node<T>::Node(T data){
	this->data = data;
	next = 0;
}

template <class T>
Node<T>::Node(T data, Node<T>* next){
	this->data = data;
	this->next = next;
}

template <class T>
T Node<T>::getData() const{
	return data;
}

template <class T>
Node<T>* Node<T>::getNext() const{
	return next;
}

template <class T>
void Node<T>::setData(T data){
	this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next){
	this->next = next;
}

// The following statement prevents the compiler from throwing an "undefined reference" error
// Each template instantiation must be referenced at the end of this file
template class Node<int>;
template class Node<Process>;
