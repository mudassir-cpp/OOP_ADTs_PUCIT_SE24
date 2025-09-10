#ifndef SET_H
#define SET_H
#include"Array.h"
class Set
{
	Array data;
	int numberOfElements;
	bool isSetFull() const;
	int getElementIndex(int element) const;
public:
	Set(int cap = 0);
	void insert(int element);
	void remove(int element);
	void print();
	int getCardinality() const;
	bool isMember(int val) const;
	int isSubset(Set s2) const;
	void resize(int newCapacity);
	Set calcUnion(const Set& s2) const;
	Set calcIntersection(const Set& s2) const;
	Set calcDifference(const Set& s2) const;
	Set calcSymmetricDifference(const Set& s2) const;

};
#endif#pragma once
