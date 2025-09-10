#include <iostream>
#include "Matrix.h"
using namespace std;
void createMetrix(Matrix& metrix, int r, int c)
{
	metrix.data = new int* [r];
	for (int i = 0; i < r; i++)
	{
		metrix.data[i] = new int[c];
	}
	metrix.rows = r;
	metrix.columns = c;
}
int& getSetElement(Matrix& metrix, int r, int c)
{
	if (r > metrix.rows - 1 || c > metrix.columns - 1)
	{
		int a = 0;
		return a;
	}
	return metrix.data[r][c];
}
void inputMetrix(Matrix* metrix)
{
	for (int i = 0; i < metrix->rows; i++)
	{
		for (int j = 0; j < metrix->columns; j++)
		{
			cin >> getSetElement(*metrix, i, j);
		}
	}
}
void displayMetrix(Matrix metrix)
{
	if (metrix.data == nullptr)
	{
		cout << "There is no metrix : ";
		return;
	}
	for (int i = 0; i < metrix.rows; i++)
	{
		for (int j = 0; j < metrix.columns; j++)
		{
			cout << getSetElement(metrix, i, j) << " ";
		}
		cout << "\n";
	}
}
void freeMetrix(Matrix& metrix)
{
	if (metrix.data == nullptr)
		return;
	for (int i = 0; i < metrix.rows; i++)
	{
		delete[]  metrix.data[i];
	}
	delete[] metrix.data;
	metrix.data = nullptr;
}

Matrix add(Matrix m1, Matrix m2)
{
	Matrix met;
	if (m1.rows != m2.rows || m1.columns != m2.columns)
	{
		met.data = nullptr;
		met.columns = 0;
		met.rows = 0;
		return met;
	}
	else
	{
		createMetrix(met, m1.rows, m1.columns);
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.columns; j++)
			{
				getSetElement(met, i, j) = getSetElement(m1, i, j) + getSetElement(m2, i, j);
			}
		}
		return met;
	}
}
Matrix multiply(Matrix m1, Matrix m2)
{

	Matrix met;
	if (m1.columns == m2.rows)
	{
		createMetrix(met, m1.rows, m2.columns);
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m2.columns; j++)
			{
				int sum = 0;
				for (int k = 0; k < m2.rows; k++)
				{
					sum = sum + getSetElement(m1, i, k) * getSetElement(m2, k, j);
				}
				getSetElement(met, i, j) = sum;
			}
		}
		return met;
	}
	else
	{
		met.data = nullptr;
		met.rows = 0;
		met.columns = 0;
	}
}
Matrix createClone(Matrix metrix)
{
	Matrix met;
	createMetrix(met, metrix.rows, metrix.columns);
	for (int i = 0; i < metrix.rows; i++)
	{
		for (int j = 0; j < metrix.columns; j++)
		{
			getSetElement(met, i, j) = getSetElement(metrix, i, j);
		}
	}
	met.rows = metrix.rows;
	met.columns = metrix.columns;
	return met;
}
void transpose(Matrix& metrix)
{
	Matrix met;
	if (metrix.data != nullptr)
	{
		createMetrix(met, metrix.columns, metrix.rows);
		for (int i = 0; i < metrix.rows; i++)
		{
			for (int j = 0; j < metrix.columns; j++)
			{
				getSetElement(met, j, i) = getSetElement(metrix, i, j);
			}
		}
		freeMetrix(metrix);
		metrix.data = met.data;
		metrix.rows = met.rows;
		metrix.columns = met.columns;
	}
}
