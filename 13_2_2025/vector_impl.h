#ifndef VECTOR
#define VECTOR
#include<iostream>
using namespace std;
class vector {
	private:
		int* data;
		size_t size;
		size_t capacity;
		void reallocate (int new_capacity);
	public:
		vector():size(0),capacity(0),data(nullpt){}
		vetor(size_t size): size(size), m_cap(isze)
		{
			data = mew int[m_size];
		}
		vector (const vecotr);
		int at(size_t index) const;
		void pop_back(int value);
		void pop_back();
		size_t getSize() const;
		size_t getCup() const;
		void resize(size_t newsize);
		int front() const;
		int back() const;
		bool isEmpty() const;
		void shrink_to_fit();
		void insert(size_t index, int value);
		void erase(size_t index);
		void clear();
}




	
