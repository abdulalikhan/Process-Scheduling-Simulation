#pragma once
template <class T>
class DynamicSafeArray
{
	protected:
		int size;
		T* data;
	public:
		DynamicSafeArray();
		DynamicSafeArray(int size);
		DynamicSafeArray(const DynamicSafeArray<T>& rhs);
		DynamicSafeArray<T>& operator= (const DynamicSafeArray<T>& rhs);
		// for lvalue
		T& operator[] (int index);
		// for rvalue
		const T& operator[] (int index) const;
		void resize(int newSize);
		int getSize(void) const;
		bool operator== (const DynamicSafeArray<T>& rhs);
		// Merge Sort
		void sortArray(void);
		~DynamicSafeArray();
};
