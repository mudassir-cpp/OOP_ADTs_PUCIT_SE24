#ifndef MATRIX_H
#define MATRIX_H
struct Matrix
{
	int** data;
	int rows;
	int columns;
};
void createMetrix(Matrix&, int r, int c);
int& getSetElement(Matrix&, int r, int c);
void inputMetrix(Matrix*);
void displayMetrix(Matrix);
void freeMetrix(Matrix&);
Matrix add(Matrix m1, Matrix m2);
Matrix multiply(Matrix, Matrix);
void transpose(Matrix&);
Matrix createClone(Matrix);
#endif