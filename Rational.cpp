#include<iostream>
#include"Rational.h"
using namespace std;
void inputRational(Rational& rational)
{
	cout << "Enter Numerator: ";
	cin >> rational.numerator;
	cout << "Enter Denomirator: ";
	cin >> rational.denomirator;
	reduce(&rational);
}
void printRational(Rational rational)
{
	cout << rational.numerator << "/" << rational.denomirator << "\n";
}
static int findLCM(int a, int b)
{
	return (a * b) / findGCD(a, b);
}
Rational addRational(Rational a, Rational b)
{
	Rational r;
	int lcm = findLCM(a.denomirator, b.denomirator);
	r.numerator = ((lcm / a.denomirator) * a.numerator) + ((lcm / b.denomirator) * b.numerator);

	r.denomirator = lcm;
	reduce(&r);
	return r;
}
Rational diffRational(Rational a, Rational b)
{
	Rational r;
	int lcm = findLCM(a.denomirator, b.denomirator);
	r.denomirator = lcm;
	r.numerator = ((lcm / a.denomirator) * a.numerator) - ((lcm / b.denomirator) * b.numerator);
	reduce(&r);
	return r;
}
Rational divRational(Rational a, Rational b)
{
	Rational r;
	r.numerator = a.numerator * b.denomirator;
	r.denomirator = a.denomirator * b.numerator;
	reduce(&r);
	return r;
}
static int findGCD(int a, int b)
{
	int rem;
	while (a % b != 0)
	{
		rem = a % b;
		a = b;
		b = rem;
	}
	return b;
}
void reduce(Rational* a)
{
	int gcd = findGCD(a->numerator, a->denomirator);
	a->numerator = a->numerator / gcd;
	a->denomirator = a->denomirator / gcd;
}