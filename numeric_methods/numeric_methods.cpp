#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

struct pt { float x, y; };

double getfunc(double a, double b, double x);
double getdfunc(double a, double b, double c, double x);
double getfuncdiff(double a, double b, double xd);
double getfuncint(double a, double b, double x1, double x2);
double getfloat(string inq);
int getint(string inq);
long long getlong(string inq);

vector<pt> dtp;

int main()
{
    std::cout << "Numeric methods\n";
	double x1 = getfloat("Input x1\n");
	double x2 = getfloat("Input x2\n");
	double a = getfloat("Input a\n");
	double b = getfloat("Input b\n");
	double n = getfloat("Input n\n");
	double delta = (x2 - x1) / n;

	printf("Calculating integral\n");
	double integr = 0;
	int nn=0;
	for (double i = 0; i < (n-1); i++)
	{
		double cx = x1 + i * delta;
		integr+= getfunc(a, b, cx) * delta;
		nn++;
		if (nn == 100000) { printf("%.2f (i=%f)\n", (i / n) * 100, i); nn = 0; }
	}
	double integrt = 0;
	nn = 0;
	for (double i = 0; i < (n - 1); i++)
	{
		double cx = x1 + i * delta;
		integrt += getfunc(a, b, cx) * delta + ((getfunc(a,b,cx+delta)- getfunc(a, b, cx))*delta*0.5);
		nn++;
		if (nn == 100000) { printf("%.2f (i=%f)\n", (i / n) * 100, i); nn = 0; }
	}
	double integran = getfuncint(a, b, x1, x2);
	printf("Integration. Analytical: %f; rectangular: %f; trapezoid: %f\n",integran, integr, integrt);

	double xd = getfloat("Input xd\n");
	double dxd = getfloat("Input x increase\n");
	a = getfloat("Input a\n");
	b = getfloat("Input b\n");
	double c = getfloat("Input c\n");
	
	double fs = (getdfunc(a, b, c, xd + dxd) - getdfunc(a, b, c, xd - dxd))/(2 * dxd);
	double fsa = getfuncdiff(a, b, xd);
	printf("Differentiation. Analytical: %f; numerical: %f\n", fsa, fs);

}

double getfunc(double a, double b, double x)
{
	return a * x + b;
}

double getfuncint(double a, double b, double x1, double x2)
{
	return 0.5*((x2 - x1)*(2 * b + a * x1 + a * x2));
}

double getdfunc(double a, double b, double c, double x)
{
	return pow(x, 3)*a + x * b + c;
}

double getfuncdiff(double a, double b, double xd)
{
	return 3 * a * pow(xd,2) + b;
}

double getfloat(string inq)
{
	printf(inq.c_str());
	string k = "";
	getline(cin, k);
	return atof(k.c_str());
}

int getint(string inq)
{
	printf(inq.c_str());
	string k = "";
	getline(cin, k);
	return atoi(k.c_str());
}

long long getlong(string inq)
{
	printf(inq.c_str());
	string k = "";
	getline(cin, k);
	return atoi(k.c_str());
}