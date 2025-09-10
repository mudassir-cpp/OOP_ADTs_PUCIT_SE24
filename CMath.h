#ifndef C_MATH_H
#define C_MATH_H
#include "String.h"
class CMath
{
public:
	static float caluculatePower(int base, int exp);
	static int calcGCD(int a, int b);
	static String toString(long long int);
	static long long int toInteger(String str);
	static float findExp(int n);
	static float findModF(float num, int& integerPart);
	static long long int findExp2(int x);
};

#endif
