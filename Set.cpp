#include<iostream>
#include"Set.h"
#include"Array.h"
using namespace std;
enum { EXISTS = 1, NOT_EXISTS = 0 };
enum { THIS_IS_SUBSET = 1, S2_IS_SUBSET = -1, NO_ONE_IS_SUBSET = 0, IMPROPER_SUBSET = 2 };
Set::Set(int cap) :data(cap)
{
	numberOfElements = 0;
}
bool Set::isSetFull() const
{
	return data.getCapacity() == numberOfElements;
}
void Set::insert(int element)
{
	if (isSetFull())
	{
		resize(numberOfElements * 2);
	}
	if (!isMember(element))
	{
		data.getSet(numberOfElements) = element;
		numberOfElements++;
	}
}
int Set::getElementIndex(int element) const
{
	for (int i = 0; i < numberOfElements; i++)
	{
		if (element == data.getSet(i))
			return i;
	}
	return -1;
}
void Set::remove(int element)
{
	if (!isMember(element))
		return;
	int index = getElementIndex(element);
	data.getSet(index) = data.getSet(numberOfElements - 1);
	numberOfElements--;
}
void Set::print()
{
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << data.getSet(i) << " ";
	}
	cout << "\n";
}
int Set::getCardinality() const
{
	return numberOfElements;
}
bool Set::isMember(int val) const
{
	if (getElementIndex(val) != -1)
		return EXISTS;
	return NOT_EXISTS;
}
int Set::isSubset(Set s2) const
{
	bool flag = true;
	if (this->numberOfElements >= s2.numberOfElements)
	{
		for (int i = 0; i < s2.numberOfElements; i++)
		{
			if (this->isMember(s2.data.getSet(i)) == NOT_EXISTS)
			{
				flag = false;
			}
		}
		if (flag && this->numberOfElements != s2.numberOfElements)
		{
			return S2_IS_SUBSET;
		}
		else if (flag)
		{
			return IMPROPER_SUBSET;
		}
	}
	flag = true;
	for (int i = 0; i < numberOfElements; i++)
	{
		if (s2.isMember(data.getSet(i)) == NOT_EXISTS)
		{
			flag = false;
		}
	}
	if (flag)
	{
		return THIS_IS_SUBSET;
	}
	else
		return NO_ONE_IS_SUBSET;
}
void Set::resize(int newCapacity)
{
	if (newCapacity > 0)
	{
		data.resize(newCapacity);
	}
}
Set Set::calcUnion(const Set& s2) const
{
	Set testSet(1);
	for (int i = 0; i < numberOfElements; i++)
	{
		testSet.insert(data.getSet(i));
	}
	for (int i = 0; i < s2.numberOfElements; i++)
	{
		if (!s2.isMember(data.getSet(i)))
			testSet.insert(s2.data.getSet(i));
	}
	return testSet;
}
Set Set::calcIntersection(const Set& s2) const
{
	Set testSet(1);
	for (int i = 0; i < numberOfElements; i++)
	{
		if (s2.isMember(data.getSet(i)))
		{
			testSet.insert(data.getSet(i));
		}
	}
	return testSet;
}
Set Set::calcDifference(const Set& s2) const
{
	Set testSet(1);
	for (int i = 0; i < numberOfElements; i++)
	{
		if (!s2.isMember(data.getSet(i)))
		{
			testSet.insert(data.getSet(i));
		}
	}
	return testSet;
}
Set Set::calcSymmetricDifference(const Set& s2) const
{
	Set testSet(1);
	for (int i = 0; i < numberOfElements; i++)
	{
		if (!isMember(s2.data.getSet(i)))
			testSet.insert(data.getSet(i));
	}
	for (int i = 0; i < s2.numberOfElements; i++)
	{
		if (!s2.isMember(data.getSet(i)))
			testSet.insert(s2.data.getSet(i));
	}
	return testSet;
}