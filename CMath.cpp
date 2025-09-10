#include"CMath.h"
#include "String.h"
float CMath::caluculatePower(int base, int exp)
{
	if (exp == 0)
		return 1;
	float result = 1;
	for (int i = 0; i < exp; i++)
	{
		result = result * base;
	}
	return result;
}
int CMath::calcGCD(int a, int b)
{
	int rem = 0;
	while (a % b != 0)
	{
		rem = a % b;
		a = b;
		b = rem;
	}
	return rem;
}
String CMath::toString(long long int num)
{
	String str;
	str.setNumber(num);
	return str;
}
long long int CMath::toInteger(String str)
{
	long long int num;
	num = str.convertToInteger();
	return num;
}
float CMath::findExp(int n)
{
	if (n == 0)
		return 1;
	float num = 1;
	const float EXP = 2.718281;
	for (int i = 0; i < n; i++)
	{
		num = num * EXP;
	}
	return num;
}
float CMath::findModF(float num, int& integerPart)
{
	float res = num - int(num);
	integerPart = int(num);
	return res;
}
long long int CMath::findExp2(int x)
{
	if (x == 0)
		return 1;
	long long int num = 1;
	for (int i = 0; i < x; i++)
	{
		num = num * 2;
	}
	return num;
}