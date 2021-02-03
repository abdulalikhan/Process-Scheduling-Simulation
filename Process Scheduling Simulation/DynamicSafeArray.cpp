#include "StdAfx.h"
#include "DynamicSafeArray.h"
#include "UpperIndexOutOfBoundsException.h"
#include "LowerIndexOutOfBoundsException.h"
#include "process.h"

template <class T>
DynamicSafeArray<T>::DynamicSafeArray(){
	size = 0;
	data = 0;
}

template <class T>
DynamicSafeArray<T>::DynamicSafeArray(int size){
	this->size = size;
	data = new T[size];
}

template <class T>
DynamicSafeArray<T>::DynamicSafeArray(const DynamicSafeArray<T>& rhs){
	size = rhs.getSize();
	data = new T[rhs.getSize()];
	memcpy(data, rhs.data, sizeof(T)*size);
}

template <class T>
DynamicSafeArray<T>& DynamicSafeArray<T>::operator=(const DynamicSafeArray<T>& rhs){
	if (this != &rhs){
		if (data != 0){
			delete [] data;
			data = 0;
		}
		size = rhs.getSize();
		data = new T[size];
		memcpy(data, rhs.data, sizeof(T)*size);		 
	}
	return (*this);
}

template <class T>
int DynamicSafeArray<T>::getSize(void) const{
	return size;
}

template <class T>
DynamicSafeArray<T>::~DynamicSafeArray(){
	if (data != 0){
		delete [] data;
		data = 0;
	}
	size = 0;
}

// for lvalue
template <class T>
T& DynamicSafeArray<T>::operator[] (int index){
	/* If the index is out of bounds (less than zero or exceeds the size),
	throw an exception
	*/
	if (index >= size)
		throw UpperIndexOutOfBoundsException();
	else if (index < 0)
		throw LowerIndexOutOfBoundsException();
	else
		return data[index];
}


// for rvalue
template <class T>
const T& DynamicSafeArray<T>::operator[] (int index) const{
	/* If the index is out of bounds (less than zero or exceeds the size),
	throw an exception
	*/
	if (index >= size || index < 0)
		throw OutOfBoundsException();
	else
		return data[index];
}

template <class T>
void DynamicSafeArray<T>::resize(int newSize){
	if (size != newSize){
		// Using a temporary pointer to hold the previous data during the resizing process
		T* temp = new T[size];
		memcpy(temp, data, sizeof(T)*size);
		if (data != 0){
			delete [] data;
			data = 0;
		}
		data = new T[newSize];
		size = newSize;
		memcpy(data, temp, sizeof(T)*size);
		if (temp != 0){
			delete [] temp;
			temp = 0;
		}
	}
}

// Merge Sort
// Stable Sorting Algorithm

template <class T>
void merge(T* a, int lowerBound, int upperBound){
	int midIndex = (lowerBound+upperBound)/2;
	int i = lowerBound;
	int j = midIndex+1;
	int k = 0;
	int sizeOfAux = upperBound-lowerBound+1;
	DynamicSafeArray<T> aux(sizeOfAux);
	while ((i<=midIndex) && (j<=upperBound)){
		if (a[i]<a[j])
			aux[k++] = a[i++];
		else
			aux[k++] = a[j++];
	}
	while (i<=midIndex)
		aux[k++] = a[i++];
	while (j<=upperBound)
		aux[k++] = a[j++];
	for (k=0; k<(upperBound-lowerBound+1); ++k){
		a[lowerBound+k] = aux[k];
	}
}

template <class T>
void mergeSort(T* a, int lowerBound, int upperBound){
	if (lowerBound<upperBound){
		int midIndex = (lowerBound+upperBound)/2;
		mergeSort(a, lowerBound, midIndex);
		mergeSort(a, midIndex+1, upperBound);
		merge(a, lowerBound, upperBound);
	}
}

template <class T>
void DynamicSafeArray<T>::sortArray(void){
	mergeSort(data, 0, size-1);
}

template <class T>
bool DynamicSafeArray<T>::operator== (const DynamicSafeArray<T>& rhs)
{
	bool isEqual;
	if(size == rhs.getSize())
		for (int i=0; i<rhs.getSize(); i++)
		{
			if (data[i] == rhs.data[i])
				isEqual = true;	
			else
				isEqual = false;
			if(isEqual == false)
				break;
		}
	else
		isEqual = false;
	return isEqual;
}

// The following statement prevents the compiler from throwing an "undefined reference" error
// Each template instantiation must be referenced at the end of this file
template class DynamicSafeArray<double>;
template class DynamicSafeArray<bool>;
template class DynamicSafeArray<Process>;
