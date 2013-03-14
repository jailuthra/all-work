#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	double a;
	double b;
	double x;

	cout<<"Enter The Values of a and b of the Equation (ax + b = 0): \n";
	cin>>a>>b;

	cout<<"The Equation Is: "<<a<<"x + "<<b<<" = 0\n\n";

	x = (0-b)/a;

	cout<<"The Value of x is: "<<x<<"\n\n\n";
	
}
