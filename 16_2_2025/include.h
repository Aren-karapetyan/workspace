#include<iostream>
#include<vectori>
using namespace std;
class bitset{
	private:
		vector<int> bits;
		size_t size;
	public:
		void set(size_t pos, bool bit);
		void reset(size_t pos);
		void flip(size_t pos);
		bool test(size_t pos) const;
		size_t count() const;
		size_t size() const;
		void print() const;
		size_t getIndex(size_t pos) const;
		size_t getPosition(size_t pos) const;
}
		

