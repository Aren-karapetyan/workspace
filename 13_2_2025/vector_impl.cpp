#include "vector_impl.h"
int at(size_t index) const 
{
    return vec[index];
}
int pop_back()
{
	if(size > 0)
	--size;
}
size_t getSize() const 
{
    return vec.size;
}
size_t getCap() const
{
	return cap
}
void resize(size_t newsize)
{
	if (newsize >= 0)
	{
		size = newsize;
	}
}
void fron() const
{
	return data[0];
}
int back()
{
	return data[size - 1];
}
bool isEmpty() const
{
	return size;
}
void shrink_to_fit()
{
	realloc(size);
}
void insert(size_t index, int value)
{
	for (int i = index - 1; i < 0; i ++)
	{
		data[i]



