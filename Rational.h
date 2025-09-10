#ifndef RATIONAL_H
#define RATIONAL_H
struct Rational
{
	int numerator;
	int denomirator;
};
void inputRational(Rational&);
void printRational(Rational);
Rational addRational(Rational a, Rational b);
Rational diffRational(Rational a, Rational b);
Rational divRational(Rational a, Rational b);
void reduce(Rational* a);
static int findGCD(int a, int b);
static int findLCM(int a, int b);
#endif